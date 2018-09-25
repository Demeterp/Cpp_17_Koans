//
// Created by Demeter on 22.09.2018.
//
#include "gtest/gtest.h"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ul;

#define all(a) (a).begin(), (a).end()
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

//this is GCC, Clang, and EDG compilers specific
#define countbits(a) __builtin_popcountll(a)

TEST(Codeforces, Basics) {
    fastio;

    ll i = 1234567890123456789;
    ASSERT_EQ(i, 1234567890123456789);

    ASSERT_EQ(5, __gcd(15, 10));
    ASSERT_EQ(13, __gcd(13*10001, 13*1002));

    ASSERT_EQ(1, countbits(1));
    ASSERT_EQ(8, countbits(0xFF));
    ASSERT_EQ(16, countbits(0xFFFF));
    ASSERT_EQ(32, countbits(0xFFFFFFFF));

}
