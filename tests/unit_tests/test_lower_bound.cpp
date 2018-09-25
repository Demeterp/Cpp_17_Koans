//
// Created by Demeter on 24.09.2018.
//
#include "gtest/gtest.h"
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ul;


ul solve(vector<ul> &keys, vector<ul> sums, int l, int r) {
    long double summNaOtrzeke = keys[r] + sums[r] - sums[l];
    ul lengthOtrzeka = r - l + 1;
    auto leftIt = keys.begin() + l;
    auto rightIt = keys.begin() + r;
    auto it = lower_bound(leftIt, rightIt, summNaOtrzeke / lengthOtrzeka);
    return *it;
}

vector<ul> sums(vector<ul> keys) {
    vector<ul> sums(keys.size());
    ul sum = 0;
    for (ul i = 0; i < keys.size(); i++) {
        sums[i] = sum;
        sum += keys[i];
    }
    return sums;
}

TEST(LowerBound, Basic) {
    vector<ul> keys = {1, 2, 3};
    ASSERT_EQ(2, solve(keys, sums(keys), 0, 2));
    ASSERT_EQ(2, solve(keys, sums(keys), 1, 1));

    keys = {1, 1};
    ASSERT_EQ(1, solve(keys, sums(keys), 0, 0));
    ASSERT_EQ(1, solve(keys, sums(keys), 0, 1));


    keys = {1, 1, 1, 1, 1, 1, 1, 1, 2};
    ASSERT_EQ(2, solve(keys, sums(keys), 0, 8));
    ASSERT_EQ(1, solve(keys, sums(keys), 4, 4));
    ASSERT_EQ(1, solve(keys, sums(keys), 2, 2));

    keys = {1, 20, 30, 40, 50, 60, 70, 80, 90};
    ASSERT_EQ(30, solve(keys, sums(keys), 0, 4));
    ASSERT_EQ(90, solve(keys, sums(keys), 7, 8));
}
