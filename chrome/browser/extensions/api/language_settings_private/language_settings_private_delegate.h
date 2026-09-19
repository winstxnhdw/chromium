// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_EXTENSIONS_API_LANGUAGE_SETTINGS_PRIVATE_LANGUAGE_SETTINGS_PRIVATE_DELEGATE_H_
#define CHROME_BROWSER_EXTENSIONS_API_LANGUAGE_SETTINGS_PRIVATE_LANGUAGE_SETTINGS_PRIVATE_DELEGATE_H_

#include <string>

#include "base/memory/raw_ptr.h"
#include "build/chromeos_buildflags.h"
#include "chrome/common/extensions/api/language_settings_private.h"
#include "components/keyed_service/core/keyed_service.h"
#include "extensions/browser/event_router.h"

#if BUILDFLAG(IS_CHROMEOS)
#include "ui/base/ime/ash/input_method_manager.h"
#endif

namespace content {
class BrowserContext;
}

namespace extensions {

// Observes language settings and routes changes as events to listeners of the
// languageSettingsPrivate API.
class LanguageSettingsPrivateDelegate
    : public KeyedService,
#if BUILDFLAG(IS_CHROMEOS)
      public ash::input_method::InputMethodManager::Observer,
#endif  // BUILDFLAG(IS_CHROMEOS)
      public EventRouter::Observer {
 public:
  static std::unique_ptr<LanguageSettingsPrivateDelegate> Create(
      content::BrowserContext* browser_context);

  explicit LanguageSettingsPrivateDelegate(content::BrowserContext* context);
  LanguageSettingsPrivateDelegate(const LanguageSettingsPrivateDelegate&) =
      delete;
  LanguageSettingsPrivateDelegate& operator=(
      const LanguageSettingsPrivateDelegate&) = delete;

  ~LanguageSettingsPrivateDelegate() override;

 protected:
  // KeyedService implementation.
  void Shutdown() override;

  // EventRouter::Observer implementation.
  void OnListenerAdded(const EventListenerInfo& details) override;
  void OnListenerRemoved(const EventListenerInfo& details) override;

#if BUILDFLAG(IS_CHROMEOS)
  // ash::input_method::InputMethodManager::Observer implementation.
  void InputMethodChanged(ash::input_method::InputMethodManager* manager,
                          Profile* profile,
                          bool show_message) override;
  void OnInputMethodExtensionAdded(const std::string& extension_id) override;
  void OnInputMethodExtensionRemoved(const std::string& extension_id) override;
#endif  // BUILDFLAG(IS_CHROMEOS)

 private:
#if BUILDFLAG(IS_CHROMEOS)
  // If there are any JavaScript listeners registered for input method events,
  // ensures we are registered for change notifications. Otherwise, unregisters
  // any observers.
  void StartOrStopListeningForInputMethodChanges();
#endif  // BUILDFLAG(IS_CHROMEOS)

  raw_ptr<content::BrowserContext> context_;

  // True if there are observers listening for input method events.
  bool listening_input_method_;
};

}  // namespace extensions

#endif  // CHROME_BROWSER_EXTENSIONS_API_LANGUAGE_SETTINGS_PRIVATE_LANGUAGE_SETTINGS_PRIVATE_DELEGATE_H_
