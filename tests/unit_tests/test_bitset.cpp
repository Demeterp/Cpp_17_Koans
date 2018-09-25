//
// Created by Demeter on 24.09.2018.
//

#include "gtest/gtest.h"
#include <bitset>

using namespace std;

typedef long long ll;


TEST(Bitset, Basics) {
    bitset<10> s(string("0010011010"));
    ASSERT_EQ(4, s.count());

    bitset<10> a(string("0010110110"));
    bitset<10> b(string("1011011000"));

    ASSERT_EQ((a & b), (bitset<10>) string("0010010000"));

    ASSERT_EQ((a | b), (bitset<10>) string("1011111110"));

    ASSERT_EQ((a ^ b), (bitset<10>) string("1001101110"));
}


