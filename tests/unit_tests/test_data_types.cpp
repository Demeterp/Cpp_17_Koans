//
// Created by Demeter on 22.09.2018.
//
//
// Created by Demeter on 21.09.2018.
//
#include "gtest/gtest.h"

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>


const int FILL_ME = 0;

TEST(DataTypes, basic) {

    char aChar;
    EXPECT_EQ(sizeof(aChar), 1);

    short a;
    EXPECT_EQ(sizeof(a), FILL_ME);
    EXPECT_EQ(SHRT_MAX, 32767);

    short int b;
    EXPECT_EQ(sizeof(b), FILL_ME);

    signed short c;
    EXPECT_EQ(sizeof(c), FILL_ME);

    signed short int d;
    EXPECT_EQ(sizeof(d), FILL_ME);

    unsigned short e;
    EXPECT_EQ(sizeof(e), FILL_ME);

    unsigned short int f;
    EXPECT_EQ(sizeof(f), FILL_ME);

    unsigned short int g;
    EXPECT_EQ(sizeof(g), FILL_ME);

    int hInt;
    EXPECT_EQ(sizeof(hInt), FILL_ME);
    EXPECT_EQ(INT_MAX, 0x7fffffff);
    EXPECT_EQ(INT_MAX, FILL_ME);


    signed aSigned;
    EXPECT_EQ(sizeof(aSigned), FILL_ME);

    signed int aSignedInt;
    EXPECT_EQ(sizeof(aSignedInt), FILL_ME);

    unsigned aUnsigned;
    EXPECT_EQ(sizeof(aUnsigned), FILL_ME);
    EXPECT_EQ(UINT_MAX, 0xffffffffU);
    EXPECT_EQ(UINT_MAX, FILL_ME);

    unsigned int l;
    EXPECT_EQ(sizeof(l), FILL_ME);

    unsigned int m;
    EXPECT_EQ(sizeof(m), FILL_ME);

    long n;
    EXPECT_EQ(sizeof(n), FILL_ME);

    long int o;
    EXPECT_EQ(sizeof(o), FILL_ME);

    signed long p;
    EXPECT_EQ(sizeof(p), FILL_ME);

    signed long int r;
    EXPECT_EQ(sizeof(r), FILL_ME);
    EXPECT_EQ(ULONG_MAX, 2147483647L);
    EXPECT_EQ(ULONG_MAX, FILL_ME);

    unsigned long s;
    EXPECT_EQ(sizeof(s), FILL_ME);
    EXPECT_EQ(ULONG_MAX, 0xffffffffUL);
    EXPECT_EQ(ULONG_MAX, FILL_ME);

    unsigned long int t;
    EXPECT_EQ(sizeof(t), FILL_ME);

    unsigned long int u;
    EXPECT_EQ(sizeof(u), FILL_ME);

    long long v;
    EXPECT_EQ(sizeof(v), FILL_ME);

    long long int w;
    EXPECT_EQ(sizeof(w), FILL_ME);

    signed long long q;
    EXPECT_EQ(sizeof(q), FILL_ME);

    signed long long int x;
    EXPECT_EQ(sizeof(x), FILL_ME);

    unsigned long long y;
    EXPECT_EQ(sizeof(y), FILL_ME);
    EXPECT_EQ(ULLONG_MAX, 0xffffffffffffffffull);
    EXPECT_EQ(ULLONG_MAX, FILL_ME);


    unsigned long long int z;
    EXPECT_EQ(sizeof(z), FILL_ME);
    EXPECT_EQ(ULLONG_MAX, 0xffffffffffffffffull);
    EXPECT_EQ(ULLONG_MAX, FILL_ME);

    std::string aString;
    EXPECT_EQ(sizeof(aString), 24);

    /**
     *
#define SHRT_MIN (-32768)
#define SHRT_MAX 32767
#define USHRT_MAX 0xffffU
#define INT_MIN (-2147483647 - 1)
#define INT_MAX 2147483647
#define UINT_MAX 0xffffffffU
#define LONG_MIN (-2147483647L - 1)
#define LONG_MAX 2147483647L
#define ULONG_MAX 0xffffffffUL
#define LLONG_MAX 9223372036854775807ll
#define LLONG_MIN (-9223372036854775807ll - 1)
#define ULLONG_MAX 0xffffffffffffffffull
     */
}

using namespace std;
