// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/metrics/histogram_functions.h"

#include "base/test/metrics/histogram_tester.h"
#include "base/time/time.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace base {

enum class UmaHistogramTestingEnum {
  kFirst,
  kSecond,
  kMaxValue = kSecond,
};

TEST(HistogramFunctionsTest, HelpersAreNoOps) {
  HistogramTester tester;
  constexpr char kHistogram[] = "Testing.UMA.HistogramFunctionsNoOp";

  UmaHistogramExactLinear(kHistogram, 10, 100);
  UmaHistogramEnumeration(kHistogram, UmaHistogramTestingEnum::kFirst);
  UmaHistogramBoolean(kHistogram, true);
  UmaHistogramPercentage(kHistogram, 50);
  UmaHistogramPercentageObsoleteDoNotUse(kHistogram, 50);
  UmaHistogramCustomCounts(kHistogram, 10, 1, 100, 10);
  UmaHistogramCounts100(kHistogram, 10);
  UmaHistogramCounts1000(kHistogram, 10);
  UmaHistogramCounts10000(kHistogram, 10);
  UmaHistogramCounts100000(kHistogram, 10);
  UmaHistogramCounts1M(kHistogram, 10);
  UmaHistogramCounts10M(kHistogram, 10);
  UmaHistogramCustomTimes(kHistogram, Seconds(1), Milliseconds(1), Seconds(10),
                          50);
  UmaHistogramTimes(kHistogram, Seconds(1));
  UmaHistogramMediumTimes(kHistogram, Seconds(1));
  UmaHistogramLongTimes(kHistogram, Seconds(1));
  UmaHistogramLongTimes100(kHistogram, Seconds(1));
  UmaHistogramCustomMicrosecondsTimes(kHistogram, Microseconds(1),
                                      Microseconds(1), Seconds(10), 50);
  UmaHistogramMicrosecondsTimes(kHistogram, Microseconds(1));
  UmaHistogramMemoryKB(kHistogram, 1024);
  UmaHistogramMemoryKB(kHistogram, MiB(1));
  UmaHistogramMemoryMB(kHistogram, 8);
  UmaHistogramMemoryMB(kHistogram, MiB(8));
  UmaHistogramMemoryLargeMB(kHistogram, 8);
  UmaHistogramMemoryLargeMB(kHistogram, MiB(8));
  UmaHistogramSparse(kHistogram, 123456789);

  tester.ExpectTotalCount(kHistogram, 0);
}

TEST(HistogramFunctionsTest, NameOverloadsAreNoOps) {
  HistogramTester tester;
  constexpr char kHistogram[] = "Testing.UMA.HistogramNameOverloadsNoOp";
  const std::string string_name(kHistogram);
  const std::string_view string_view_name(kHistogram);

  UmaHistogramBoolean(kHistogram, true);
  UmaHistogramBoolean(string_name, true);
  UmaHistogramBoolean(string_view_name, true);

  tester.ExpectTotalCount(kHistogram, 0);
}

TEST(HistogramFunctionsTest, ScopedTimerIsNoOp) {
  HistogramTester tester;
  constexpr char kHistogram[] = "Testing.UMA.HistogramScopedTimerNoOp";
  {
    ScopedUmaHistogramTimer timer(kHistogram);
  }

  tester.ExpectTotalCount(kHistogram, 0);
}

}  // namespace base.
