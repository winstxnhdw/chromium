// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_PUBLIC_COMMON_DEVICE_MEMORY_APPROXIMATED_DEVICE_MEMORY_H_
#define THIRD_PARTY_BLINK_PUBLIC_COMMON_DEVICE_MEMORY_APPROXIMATED_DEVICE_MEMORY_H_

#include <stdint.h>

#include "third_party/blink/public/common/common_export.h"

namespace blink {

class ApproximatedDeviceMemory {
 public:
  // Initializes the standardized device-memory value exposed to the web.
  static void BLINK_COMMON_EXPORT Initialize();

  // Returns a device-memory value that is independent of physical RAM to
  // reduce fingerprintability.
  static float BLINK_COMMON_EXPORT GetApproximatedDeviceMemory();

  // Changes the physical-memory input for testing. The reported value remains
  // standardized.
  static void BLINK_COMMON_EXPORT SetPhysicalMemoryMBForTesting(int64_t);

 private:
  static void CalculateAndSetApproximatedDeviceMemory();

  static float approximated_device_memory_gb_;
  static int64_t physical_memory_mb_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_PUBLIC_COMMON_DEVICE_MEMORY_APPROXIMATED_DEVICE_MEMORY_H_
