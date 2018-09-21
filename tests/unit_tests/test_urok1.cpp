#include "gtest/gtest.h"

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

#include "uchim_string.h"

int sqr(int a) {
    return pow(a, 2);
}

TEST(Example, Equals) {
    EXPECT_EQ(1, 1);
    EXPECT_EQ(4, sqr(2));
}

const string UTROM = "Utrom v rzhanom zakute";
const string ONCE = "Once upon a time in america";

TEST(Urok1, initialize) {
    string stroka = fixme1();
    EXPECT_EQ(stroka, UTROM);

    stroka = "";
    fixme2(stroka);
    EXPECT_EQ(stroka, UTROM);
}

TEST(Urok1, copy) {
    string stroka;

    stroka = fixme3(UTROM);
    EXPECT_EQ(stroka, UTROM);

    stroka = fixme4(UTROM);
    EXPECT_EQ(stroka, UTROM);

    stroka = "bullshit";
    fixme5(UTROM, stroka);
    EXPECT_EQ(stroka, UTROM);

    stroka = UTROM;
    fixme6(stroka);
    EXPECT_EQ(stroka, "Utrom v rzhnom zkute");

}


TEST(Urok1, reverse) {

    string stroka = UTROM + "aa";
    string reversed = stroka;
    reverse(reversed.begin(), reversed.end());

    fixme7(stroka);
    EXPECT_EQ(stroka, reversed);

    stroka = UTROM;
    reversed.assign(stroka);
    reverse(reversed.begin(), reversed.end() - 7);

    fixme8(stroka);
    EXPECT_EQ(stroka, reversed);
}

TEST(Urok1, replace) {
    string stroka = "Utrom v  zakute";
    fixme9(stroka);
    EXPECT_EQ(stroka, UTROM);

    stroka = UTROM;
    fixme10(stroka);
    EXPECT_EQ("v rzhanom zakute", stroka);

    stroka = UTROM;
    fixme11(stroka);
    EXPECT_EQ("Utrom v mrachnom zakute", stroka);
}

TEST(Urok1, clear) {
    string stroka = UTROM;
    fixme12(stroka);
    EXPECT_EQ(stroka, "");
}

TEST(Urok1, swap) {
    string stroka = UTROM;
    string another = ONCE;
    fixme15(stroka, another);
    EXPECT_EQ(stroka, ONCE);
    EXPECT_EQ(another, UTROM);


    EXPECT_EQ(20, stroka.find("america", 10));
}



//go read more info on http://www.cplusplus.com/reference/string/string/replace/
