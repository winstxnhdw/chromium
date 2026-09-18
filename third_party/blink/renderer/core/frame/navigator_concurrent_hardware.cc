// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/frame/navigator_concurrent_hardware.h"

namespace blink {

unsigned NavigatorConcurrentHardware::hardwareConcurrency() const {
  // Keep this fingerprinting surface identical across installations while
  // retaining a useful amount of parallelism for web applications.
  return 8;
}

}  // namespace blink
