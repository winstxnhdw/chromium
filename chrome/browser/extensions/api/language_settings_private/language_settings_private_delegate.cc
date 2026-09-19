// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/extensions/api/language_settings_private/language_settings_private_delegate.h"

#include <memory>
#include <string>
#include <utility>

#include "build/chromeos_buildflags.h"
#include "chrome/browser/profiles/profile.h"
#include "content/public/browser/browser_context.h"

namespace extensions {

namespace language_settings_private = api::language_settings_private;

LanguageSettingsPrivateDelegate::LanguageSettingsPrivateDelegate(
    content::BrowserContext* context)
    : context_(context), listening_input_method_(false) {
  // Register with the event router so we know when renderers are listening to
  // our events. We first check and see if there *is* an event router, because
  // some unit tests try to create all context services, but don't initialize
  // the event router first.
  EventRouter* event_router = EventRouter::Get(context_);
  if (!event_router) {
    return;
  }

  event_router->RegisterObserver(
      this, language_settings_private::OnInputMethodAdded::kEventName);
  event_router->RegisterObserver(
      this, language_settings_private::OnInputMethodRemoved::kEventName);

#if BUILDFLAG(IS_CHROMEOS)
  StartOrStopListeningForInputMethodChanges();
#endif  // BUILDFLAG(IS_CHROMEOS)
}

LanguageSettingsPrivateDelegate::~LanguageSettingsPrivateDelegate() {
  DCHECK(!listening_input_method_);
}

std::unique_ptr<LanguageSettingsPrivateDelegate>
LanguageSettingsPrivateDelegate::Create(content::BrowserContext* context) {
  return std::make_unique<LanguageSettingsPrivateDelegate>(context);
}

void LanguageSettingsPrivateDelegate::Shutdown() {
  // Unregister with the event router. We first check and see if there *is* an
  // event router, because some unit tests try to shutdown all context services,
  // but didn't initialize the event router first.
  EventRouter* event_router = EventRouter::Get(context_);
  if (event_router) {
    event_router->UnregisterObserver(this);
  }

#if BUILDFLAG(IS_CHROMEOS)
  if (listening_input_method_) {
    auto* input_method_manager = ash::input_method::InputMethodManager::Get();
    if (input_method_manager) {
      input_method_manager->RemoveObserver(this);
    }
    listening_input_method_ = false;
  }
#endif  // BUILDFLAG(IS_CHROMEOS)
}

void LanguageSettingsPrivateDelegate::OnListenerAdded(
    const EventListenerInfo& details) {
#if BUILDFLAG(IS_CHROMEOS)
  if (details.event_name ==
          language_settings_private::OnInputMethodAdded::kEventName ||
      details.event_name ==
          language_settings_private::OnInputMethodRemoved::kEventName) {
    StartOrStopListeningForInputMethodChanges();
    return;
  }
#endif  // BUILDFLAG(IS_CHROMEOS)
}

void LanguageSettingsPrivateDelegate::OnListenerRemoved(
    const EventListenerInfo& details) {
#if BUILDFLAG(IS_CHROMEOS)
  StartOrStopListeningForInputMethodChanges();
#endif  // BUILDFLAG(IS_CHROMEOS)
}

#if BUILDFLAG(IS_CHROMEOS)
void LanguageSettingsPrivateDelegate::InputMethodChanged(
    ash::input_method::InputMethodManager* manager,
    Profile* profile,
    bool show_message) {
  // Nothing to do.
}

void LanguageSettingsPrivateDelegate::OnInputMethodExtensionAdded(
    const std::string& extension_id) {
  auto args(
      language_settings_private::OnInputMethodAdded::Create(extension_id));
  std::unique_ptr<extensions::Event> extension_event(new extensions::Event(
      events::LANGUAGE_SETTINGS_PRIVATE_ON_INPUT_METHOD_ADDED,
      language_settings_private::OnInputMethodAdded::kEventName,
      std::move(args)));
  EventRouter::Get(context_)->BroadcastEvent(std::move(extension_event));
}

void LanguageSettingsPrivateDelegate::OnInputMethodExtensionRemoved(
    const std::string& extension_id) {
  auto args(
      language_settings_private::OnInputMethodRemoved::Create(extension_id));
  std::unique_ptr<extensions::Event> extension_event(new extensions::Event(
      events::LANGUAGE_SETTINGS_PRIVATE_ON_INPUT_METHOD_REMOVED,
      language_settings_private::OnInputMethodRemoved::kEventName,
      std::move(args)));
  EventRouter::Get(context_)->BroadcastEvent(std::move(extension_event));
}
#endif  // BUILDFLAG(IS_CHROMEOS)

#if BUILDFLAG(IS_CHROMEOS)
void LanguageSettingsPrivateDelegate::
    StartOrStopListeningForInputMethodChanges() {
  EventRouter* event_router = EventRouter::Get(context_);
  bool should_listen =
      event_router->HasEventListener(
          language_settings_private::OnInputMethodAdded::kEventName) ||
      event_router->HasEventListener(
          language_settings_private::OnInputMethodRemoved::kEventName);

  auto* input_method_manager = ash::input_method::InputMethodManager::Get();
  if (input_method_manager) {
    if (should_listen && !listening_input_method_) {
      input_method_manager->AddObserver(this);
    } else if (!should_listen && listening_input_method_) {
      input_method_manager->RemoveObserver(this);
    }
  }

  listening_input_method_ = should_listen;
}
#endif  // BUILDFLAG(IS_CHROMEOS)

}  // namespace extensions
