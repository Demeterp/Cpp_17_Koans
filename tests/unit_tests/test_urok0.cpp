//
// Created by Demeter on 21.09.2018.
//
#include "gtest/gtest.h"

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

TEST(Urok0, insert) {
    string s = "string";

//insert() something into 's' to make it work
    s.insert(0, "Sub");
    EXPECT_EQ(s, "Substring");

//insert() something into 's' to make it work
    s.insert(9, "!");
    EXPECT_EQ(s, "Substring!");
}

TEST(Urok0, TransformLowerUpwer) {
    string str = "Lower and Upper";
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    EXPECT_EQ("lower and upper", str);

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    EXPECT_EQ("LOWER AND UPPER", str);
}

TEST(Urok0, StringToNumber) {
    string str = "42";
    int number = stoi(str);
    EXPECT_EQ(42, number);

    str = "3.1415";
    float pi = stof(str);
    EXPECT_EQ(3.1415f, pi);

    str = "0,2500001"; //bad delimeter
    str[str.find(',')] = '.';
    double quarter = stod(str);
    EXPECT_EQ(0.2500001, quarter);

    str = to_string(quarter);
    EXPECT_EQ("0.250000", str);
}

TEST(Urok0, SubstringSearch) {

    string str = "Ishem chislo 42 v stroke";
    int indexOfIshem = str.find("Ishem");
    EXPECT_EQ(0, indexOfIshem);

    int indexOf33 = str.find("33");
    EXPECT_EQ(string::npos, indexOf33);;

    int badIndexOf42 = str.find(42);
    EXPECT_EQ(string::npos, badIndexOf42);;

    int indexOf42 = str.find("42");
    EXPECT_EQ(indexOf42, str.find("42"));;
}
