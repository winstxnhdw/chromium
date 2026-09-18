// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/metrics/histogram_functions.h"

#include <string_view>

#include "base/time/time.h"

namespace base {
// LINT.IfChange

// Higher-level helpers below delegate to these no-op primitives. Keep every
// name overload non-recording so callers cannot bypass the behavior through
// overload resolution.

void UmaHistogramBoolean(std::string_view, bool) {}

void UmaHistogramBoolean(const std::string&, bool) {}

void UmaHistogramBoolean(const char*, bool) {}

void UmaHistogramExactLinear(std::string_view, int, int) {}

void UmaHistogramExactLinear(const std::string&, int, int) {}

void UmaHistogramExactLinear(const char*, int, int) {}

void UmaHistogramPercentage(std::string_view name, int percent) {
  UmaHistogramExactLinear(name, percent, 101);
}

void UmaHistogramPercentage(const std::string& name, int percent) {
  UmaHistogramExactLinear(name, percent, 101);
}

void UmaHistogramPercentage(const char* name, int percent) {
  UmaHistogramExactLinear(name, percent, 101);
}

void UmaHistogramPercentageObsoleteDoNotUse(std::string_view name,
                                            int percent) {
  UmaHistogramExactLinear(name, percent, 100);
}

void UmaHistogramPercentageObsoleteDoNotUse(const std::string& name,
                                            int percent) {
  UmaHistogramExactLinear(name, percent, 100);
}

void UmaHistogramPercentageObsoleteDoNotUse(const char* name, int percent) {
  UmaHistogramExactLinear(name, percent, 100);
}

void UmaHistogramCustomCounts(std::string_view, int, int, int, size_t) {}

void UmaHistogramCustomCounts(const std::string&, int, int, int, size_t) {}

void UmaHistogramCustomCounts(const char*, int, int, int, size_t) {}

void UmaHistogramCounts100(std::string_view name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 100, 50);
}

void UmaHistogramCounts100(const std::string& name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 100, 50);
}

void UmaHistogramCounts100(const char* name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 100, 50);
}

void UmaHistogramCounts1000(std::string_view name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 1000, 50);
}

void UmaHistogramCounts1000(const std::string& name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 1000, 50);
}

void UmaHistogramCounts1000(const char* name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 1000, 50);
}

void UmaHistogramCounts10000(std::string_view name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 10000, 50);
}

void UmaHistogramCounts10000(const std::string& name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 10000, 50);
}

void UmaHistogramCounts10000(const char* name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 10000, 50);
}

void UmaHistogramCounts100000(std::string_view name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 100000, 50);
}

void UmaHistogramCounts100000(const std::string& name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 100000, 50);
}

void UmaHistogramCounts100000(const char* name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 100000, 50);
}

void UmaHistogramCounts1M(std::string_view name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 1000000, 50);
}

void UmaHistogramCounts1M(const std::string& name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 1000000, 50);
}

void UmaHistogramCounts1M(const char* name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 1000000, 50);
}

void UmaHistogramCounts10M(std::string_view name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 10000000, 50);
}

void UmaHistogramCounts10M(const std::string& name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 10000000, 50);
}

void UmaHistogramCounts10M(const char* name, int sample) {
  UmaHistogramCustomCounts(name, sample, 1, 10000000, 50);
}

void UmaHistogramCustomTimes(std::string_view,
                             TimeDelta,
                             TimeDelta,
                             TimeDelta,
                             size_t) {}

void UmaHistogramCustomTimes(const std::string&,
                             TimeDelta,
                             TimeDelta,
                             TimeDelta,
                             size_t) {}

void UmaHistogramCustomTimes(const char*,
                             TimeDelta,
                             TimeDelta,
                             TimeDelta,
                             size_t) {}

void UmaHistogramTimes(std::string_view name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Seconds(10), 50);
}

void UmaHistogramTimes(const std::string& name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Seconds(10), 50);
}

void UmaHistogramTimes(const char* name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Seconds(10), 50);
}

void UmaHistogramMediumTimes(std::string_view name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Minutes(3), 50);
}

void UmaHistogramMediumTimes(const std::string& name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Minutes(3), 50);
}

void UmaHistogramMediumTimes(const char* name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Minutes(3), 50);
}

void UmaHistogramLongTimes(std::string_view name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Hours(1), 50);
}

void UmaHistogramLongTimes(const std::string& name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Hours(1), 50);
}

void UmaHistogramLongTimes(const char* name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Hours(1), 50);
}

void UmaHistogramLongTimes100(std::string_view name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Hours(1), 100);
}

void UmaHistogramLongTimes100(const std::string& name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Hours(1), 100);
}

void UmaHistogramLongTimes100(const char* name, TimeDelta sample) {
  UmaHistogramCustomTimes(name, sample, Milliseconds(1), Hours(1), 100);
}

void UmaHistogramCustomMicrosecondsTimes(std::string_view,
                                         TimeDelta,
                                         TimeDelta,
                                         TimeDelta,
                                         size_t) {}

void UmaHistogramCustomMicrosecondsTimes(const std::string&,
                                         TimeDelta,
                                         TimeDelta,
                                         TimeDelta,
                                         size_t) {}

void UmaHistogramCustomMicrosecondsTimes(const char*,
                                         TimeDelta,
                                         TimeDelta,
                                         TimeDelta,
                                         size_t) {}

void UmaHistogramMicrosecondsTimes(std::string_view name, TimeDelta sample) {
  UmaHistogramCustomMicrosecondsTimes(name, sample, Microseconds(1),
                                      Seconds(10), 50);
}

void UmaHistogramMicrosecondsTimes(const std::string& name, TimeDelta sample) {
  UmaHistogramCustomMicrosecondsTimes(name, sample, Microseconds(1),
                                      Seconds(10), 50);
}

void UmaHistogramMicrosecondsTimes(const char* name, TimeDelta sample) {
  UmaHistogramCustomMicrosecondsTimes(name, sample, Microseconds(1),
                                      Seconds(10), 50);
}

void UmaHistogramMemoryKB(std::string_view name, int sample_kb) {
  UmaHistogramCustomCounts(name, sample_kb, 1000, 500000, 50);
}

void UmaHistogramMemoryKB(const std::string& name, int sample_kb) {
  UmaHistogramCustomCounts(name, sample_kb, 1000, 500000, 50);
}

void UmaHistogramMemoryKB(const char* name, int sample_kb) {
  UmaHistogramCustomCounts(name, sample_kb, 1000, 500000, 50);
}

void UmaHistogramMemoryKB(std::string_view name, ByteSize sample) {
  UmaHistogramMemoryKB(name, static_cast<int>(sample.InKiB()));
}

void UmaHistogramMemoryKB(const std::string& name, ByteSize sample) {
  UmaHistogramMemoryKB(name, static_cast<int>(sample.InKiB()));
}

void UmaHistogramMemoryKB(const char* name, ByteSize sample) {
  UmaHistogramMemoryKB(name, static_cast<int>(sample.InKiB()));
}

void UmaHistogramMemoryMB(std::string_view name, int sample_mb) {
  UmaHistogramCustomCounts(name, sample_mb, 1, 1000, 50);
}

void UmaHistogramMemoryMB(const std::string& name, int sample_mb) {
  UmaHistogramCustomCounts(name, sample_mb, 1, 1000, 50);
}

void UmaHistogramMemoryMB(const char* name, int sample_mb) {
  UmaHistogramCustomCounts(name, sample_mb, 1, 1000, 50);
}

void UmaHistogramMemoryMB(std::string_view name, ByteSize sample) {
  UmaHistogramMemoryMB(name, static_cast<int>(sample.InMiB()));
}

void UmaHistogramMemoryMB(const std::string& name, ByteSize sample) {
  UmaHistogramMemoryMB(name, static_cast<int>(sample.InMiB()));
}

void UmaHistogramMemoryMB(const char* name, ByteSize sample) {
  UmaHistogramMemoryMB(name, static_cast<int>(sample.InMiB()));
}

void UmaHistogramMemoryLargeMB(std::string_view name, int sample_mb) {
  UmaHistogramCustomCounts(name, sample_mb, 1, 64000, 100);
}

void UmaHistogramMemoryLargeMB(const std::string& name, int sample_mb) {
  UmaHistogramCustomCounts(name, sample_mb, 1, 64000, 100);
}

void UmaHistogramMemoryLargeMB(const char* name, int sample_mb) {
  UmaHistogramCustomCounts(name, sample_mb, 1, 64000, 100);
}

void UmaHistogramMemoryLargeMB(std::string_view name, ByteSize sample) {
  UmaHistogramMemoryLargeMB(name, static_cast<int>(sample.InMiB()));
}

void UmaHistogramMemoryLargeMB(const std::string& name, ByteSize sample) {
  UmaHistogramMemoryLargeMB(name, static_cast<int>(sample.InMiB()));
}

void UmaHistogramMemoryLargeMB(const char* name, ByteSize sample) {
  UmaHistogramMemoryLargeMB(name, static_cast<int>(sample.InMiB()));
}

void UmaHistogramSparse(std::string_view, int) {}

void UmaHistogramSparse(const std::string&, int) {}

void UmaHistogramSparse(const char*, int) {}

ScopedUmaHistogramTimer::ScopedUmaHistogramTimer(std::string_view,
                                                 ScopedHistogramTiming timing)
    : constructed_(), timing_(timing) {}

ScopedUmaHistogramTimer::ScopedUmaHistogramTimer(
    ScopedUmaHistogramTimer&& other)
    : constructed_(), timing_(other.timing_) {}

ScopedUmaHistogramTimer::~ScopedUmaHistogramTimer() = default;
// LINT.ThenChange(//base/metrics/histogram_macros.h)
}  // namespace base
