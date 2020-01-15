////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2020 Vladislav Trifochkin
//
// This file is part of [pfs-modulus](https://github.com/semenovf/pfs-modulus) library.
//
// Changelog:
//      2020.01.15 Initial version
////////////////////////////////////////////////////////////////////////////////
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pfs/timer.hpp"
#include <atomic>

TEST_CASE("Basic timer") {
    using timer_manager = pfs::timer_manager<>;

    timer_manager tm;
    std::atomic_int t0{0};
    std::atomic_int t1{0};
    std::atomic_int t2{0};
    std::atomic_int t3{0};

    // Timer fires once, one second from now
    tm.create(1, 0, [& t0]() { ++t0; });

    // Timer fires every second, starting one seconds from now
    tm.create(1, 1, [& t1]() { ++t1; });

    // Timer fires every second, starting now
    tm.create(0, 1, [& t2]() { ++t2; });

    // Timer fires every 100ms, starting now
    tm.create(0, 0.1, [& t3]() { ++t3; });

    std::this_thread::sleep_for(std::chrono::seconds(5));

    CHECK(t0 == 1);
    CHECK(t1 > 2);
    CHECK(t2 > 3);
    CHECK(t3 > 10);
}
