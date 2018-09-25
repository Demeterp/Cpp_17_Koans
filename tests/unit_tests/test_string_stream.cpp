//
// Created by Demeter on 22.09.2018.
//
#include "gtest/gtest.h"

#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

TEST(StringStream, Stream) {
    string str = "1 2 10 20 30 500";
    stringstream stream(str);
    vector<int> numbers(6);
    for (int &number : numbers) {
        stream >> number;
    }

    vector<int> etalon = {1, 2, 10, 20, 30, 500};
    ASSERT_EQ(numbers, etalon);
    for (int i = 0; i < numbers.size(); i++) {
        ASSERT_EQ(numbers[i], etalon[i]);
    }
}
