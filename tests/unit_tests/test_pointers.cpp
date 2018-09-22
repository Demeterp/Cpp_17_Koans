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

    int a[] = {0, 1, 2, 3, 4, 5};
    EXPECT_EQ(1, a[1]);
    EXPECT_EQ(5, a[5]);

    int *parr = a;
    EXPECT_EQ(*parr, a[1]);

    int *pa = &a[1];
    //int *powerful_pointer = &an_int;


}
