//
// Created by Demeter on 22.09.2018.
//
#include "gtest/gtest.h"

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

const int FILL_ME = 0;

TEST(StringStream, Stream) {
    string str = "1 2 10 20 30 500";
    stringstream stream(str);
    int numbers[6];

    copy(istream_iterator<int, char>(stream), istream_iterator<int, char>(), numbers);

    int etalon[6] = {1, 2, 10, 20, 30, 500};
    for (int i: numbers){
        cout << endl << i;
    }

    //EXPECT_EQ(numbers , etalon);


}
