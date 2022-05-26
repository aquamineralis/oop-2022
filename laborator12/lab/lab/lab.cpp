#include <iostream>
#include "catch_amalgamated.hpp"

bool is_prime(unsigned x) {
    if (x < 2)
        return false;
    for (unsigned d = 2; d <= x / 2; ++d) {
        if (x % d == 0)
            return false;
    }
    return true;
}

TEST_CASE("prime") {
    REQUIRE_FALSE(is_prime(0));
    REQUIRE_FALSE(is_prime(1));
    REQUIRE_FALSE(is_prime(4));
    REQUIRE_FALSE(is_prime(6));

    REQUIRE(is_prime(2));
    REQUIRE(is_prime(3));
    REQUIRE(is_prime(5));
}
