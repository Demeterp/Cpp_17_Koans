//
// Created by Demeter on 22.09.2018.
//
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

TEST(Pointers, basic) {

    int z = 10;
    int a[] = {0, 2, 6, 8, 10, 12};
    int b = 127;
    int c = 256;
    EXPECT_EQ(2, a[1]);
    EXPECT_EQ(12, a[5]);

    int *parr = a;
    EXPECT_EQ(*parr, 0);
    EXPECT_EQ(*parr, a[0]);

    EXPECT_EQ(2, a[1]);

    int *pa = &a[1];
    EXPECT_EQ(*pa, a[1]);
    EXPECT_EQ(*(pa - 1), a[0]);

    EXPECT_EQ(*(parr + 5), 12);
    EXPECT_EQ(*(parr + 5), a[5]);

    //exit through array boundary
    EXPECT_NE(*(parr + 6), 127);


    //int *powerful_pointer = &an_int;


}
