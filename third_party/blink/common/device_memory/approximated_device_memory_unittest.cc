// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/public/common/device_memory/approximated_device_memory.h"

#include "testing/gtest/include/gtest/gtest.h"

namespace blink {

namespace {

class ApproximatedDeviceMemoryTest : public testing::Test {};

TEST_F(ApproximatedDeviceMemoryTest, StandardizesDeviceMemory) {
  for (int64_t physical_memory_mb : {128, 1024, 8192, 32768, 64385}) {
    ApproximatedDeviceMemory::SetPhysicalMemoryMBForTesting(physical_memory_mb);
    EXPECT_EQ(8.0f, ApproximatedDeviceMemory::GetApproximatedDeviceMemory());
  }
}

}  // namespace

}  // namespace blink
