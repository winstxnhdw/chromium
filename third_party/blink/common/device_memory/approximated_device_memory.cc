// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/public/common/device_memory/approximated_device_memory.h"

#include "base/byte_size.h"
#include "base/check_op.h"
#include "base/system/sys_info.h"

namespace blink {

namespace {

constexpr float kStandardizedDeviceMemoryGb = 8.0f;

}  // namespace

// static
float ApproximatedDeviceMemory::approximated_device_memory_gb_ = 0.0;
int64_t ApproximatedDeviceMemory::physical_memory_mb_ = 0;

// static
void ApproximatedDeviceMemory::Initialize() {
  if (approximated_device_memory_gb_ > 0.0)
    return;
  DCHECK_EQ(0, physical_memory_mb_);
  physical_memory_mb_ = ::base::SysInfo::AmountOfTotalPhysicalMemory().InMiB();
  CalculateAndSetApproximatedDeviceMemory();
}

// static
float ApproximatedDeviceMemory::GetApproximatedDeviceMemory() {
  return approximated_device_memory_gb_;
}

// static
void ApproximatedDeviceMemory::CalculateAndSetApproximatedDeviceMemory() {
  DCHECK_GT(physical_memory_mb_, 0);
  // This value is exposed through both navigator.deviceMemory and the
  // Device-Memory client hint, so keep it independent of physical RAM.
  approximated_device_memory_gb_ = kStandardizedDeviceMemoryGb;
}

// static
void ApproximatedDeviceMemory::SetPhysicalMemoryMBForTesting(
    int64_t physical_memory_mb) {
  physical_memory_mb_ = physical_memory_mb;
  CalculateAndSetApproximatedDeviceMemory();
}

}  // namespace blink
