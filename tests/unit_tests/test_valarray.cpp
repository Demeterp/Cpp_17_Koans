//
// Created by Demeter on 22.09.2018.
//
#include "gtest/gtest.h"

#include <cmath>
#include <string>
#include <valarray>
#include <iostream>
#include <algorithm>


using namespace std;

const int FILL_ME = 0;


TEST(Valarray, Basics) {
    stringstream stream("1 2 10 20 30 500");
    vector<int> vec(6);

    for (int &number:vec) {
        stream >> number;
    }

    valarray<int> a = {1, 2, 10, 20, 30, 500};
    for (int i = 0; i < a.size(); i++) {
        ASSERT_EQ(a[i], vec[i]);
    }

    valarray<int> b = {0, 2, 10, 20, 35, 999};
    valarray<int> c(6);

    c = a + b;

    for (int i = 0; i < a.size(); i++) {
        ASSERT_EQ(a[i] + b[i], c[i]);
    }
}


