
//              Copyright Catch2 Authors
// Distributed under the Boost Software License, Version 1.0.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.boost.org/LICENSE_1_0.txt)

// SPDX-License-Identifier: BSL-1.0

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_templated.hpp>

#if defined(CATCH_CPP20_OR_GREATER)

namespace {
    struct MatchAllMatcher final : public Catch::Matchers::MatcherGenericBase {
    public:
        template <typename Any>
        constexpr bool match( Any&& ) const {
            return true;
        }

        std::string describe() const override {
            using namespace std::string_literals;
            return "Matches anything"s;
        }
    };

    constexpr MatchAllMatcher MatchAll() { return MatchAllMatcher(); }

} // namespace

TEST_CASE( "Constexpr support for matchers and compositions", "[constexpr][matchers][approvals]" ) {
    STATIC_REQUIRE( MatchAll().match( 1 ) );
    STATIC_REQUIRE( ( MatchAll() && MatchAll() ).match( 1 ) );
    STATIC_REQUIRE( ( MatchAll() || MatchAll() ).match( 1 ) );
    STATIC_REQUIRE( ( !!MatchAll() ).match( 1 ) );
}

#endif
