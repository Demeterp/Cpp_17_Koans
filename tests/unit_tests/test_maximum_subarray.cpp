/**
 * this is a test of https://cses.fi/book/book.pdf
 Maximum subarray sum
There are often several possible algorithms for solving a problem such that their
time complexities are different. This section discusses a classic problem that has
a straightforward O(n
3
) solution. However, by designing a better algorithm, it is
possible to solve the problem in O(n
2
) time and even in O(n) time.
Given an array of n numbers, our task is to calculate the maximum subarray
sum, i.e., the largest possible sum of a sequence of consecutive values in the
array2
. The problem is interesting when there may be negative values in the
array. For example, in the array
−1 2 4 −3 5 2 −5 2
2J. Bentley’s book Programming Pearls [8] made the problem popular.
21
the following subarray produces the maximum sum 10:
−1 2 4 −3 5 2 −5 2
We assume that an empty subarray is allowed, so the maximum subarray
sum is always at least 0.
 */

#include "gtest/gtest.h"
#include <vector>

using namespace std;

typedef long long ll;

ll subArraySumm(vector<int> &array) {
    ll best = 0, sum = 0;
    for (ll k : array) {
        sum = max(k, sum + k);
        best = max(best, sum);
    }
    return best;
}

TEST(MaxSubArray, Summ) {
    vector<int> e;

    e = {1, 2, 5};
    ASSERT_EQ(8, subArraySumm(e));

    e = {-1, -2, -100};
    ASSERT_EQ(0, subArraySumm(e));

    e = {-1, -2, 0};
    ASSERT_EQ(0, subArraySumm(e));

    e = {-1, 2, 4, -3, 5, 2, -5, 2};
    ASSERT_EQ(10, subArraySumm(e));

}
