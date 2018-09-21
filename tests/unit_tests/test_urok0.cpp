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
    unsigned number = stoi(str);
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
    unsigned indexOfIshem = str.find("Ishem");
    EXPECT_EQ(0, indexOfIshem);

    unsigned indexOf33 = str.find("33");
    EXPECT_EQ(string::npos, indexOf33);;

    unsigned badIndexOf42 = str.find(42);
    EXPECT_EQ(string::npos, badIndexOf42);;

    unsigned indexOf42 = str.find("42");
    EXPECT_EQ(indexOf42, indexOf42);;

    indexOf42 = str.find("42", indexOf42+1);
    EXPECT_EQ(string::npos, indexOf42);;
}

TEST(Urok0, Substring) {

    string str = "Ishem chislo 42 v stroke";
    unsigned indexOfChislo = str.find("chislo");
    EXPECT_EQ("chislo", str.substr(indexOfChislo, 6));

    string empty;
    EXPECT_TRUE(empty.empty());
    EXPECT_FALSE(str.empty());
}

TEST(Urok0, TrimLeftRight) {
    string withSpaces = "     trim some spaces please     ";

    //lets trim spaces from begining
    while(*withSpaces.begin() == ' '){
        withSpaces.erase(withSpaces.begin());
    }
    EXPECT_EQ("trim some spaces please     ", withSpaces);

    //lets trim spaces from end
    while(*(withSpaces.end()-1) == ' '){
        withSpaces.pop_back();
    }
    EXPECT_EQ("trim some spaces please", withSpaces);
}
