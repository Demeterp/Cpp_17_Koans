//
// Created by Demeter on 28.09.2018.
//


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <regex> //for __gcd
#include <cassert>

#define ul unsigned long long
#define ll long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

namespace {

    unsigned nearestPowerOfTwo(unsigned x) {
        int validBits = 32 - __builtin_clz(x);
        int setBits = __builtin_popcount(x);
        if (setBits == 1) return x;
        else return 1u << validBits;
    }

    const int INITIAL_VALUE = INT_MAX;

    int summa(int lvl, int a, int b) {
        if (a == INITIAL_VALUE) return b;
        if (b == INITIAL_VALUE) return a;
        return (a + b);
    };

    int xu(int lvl, int a, int b) {
        if (a == INITIAL_VALUE) return b;
        if (b == INITIAL_VALUE) return a;
        if (lvl % 2 == 1) return a | b;
        else return a ^ b;
    };


    struct MyTree {
        unsigned length, n, maxLevel;
        vector<int> data;
        vector<int> shiftByLevel;
        function<int(int, int, int)> F;

        // Create a segtree which stores the range [begin, end) in its bottommost level.
        MyTree(int *begin, int *end, function<int(int, int, int)> func) {
            F = func;
            length = end - begin;
            n = nearestPowerOfTwo(length);
            shiftByLevel.resize(32);
            shiftByLevel[0] = 0;
            int c = n;
            for (int i = 1; i < 32; i++) {
                shiftByLevel[i] = shiftByLevel[i - 1] + c;
                c /= 2;
            }
            data = vector<int>(n * 2, INITIAL_VALUE);
            for (int i = 0; i < length; ++i) {
                data[i] = *(begin + i);
            }
            if (length > 1) build_rec(1, n / 2);
        }

        int index(int lvl, int i) {
            return shiftByLevel[lvl] + i;
        }

        void build_rec(unsigned lvl, int count) {
            for (int i = 0; i < count; i++) {
                data[index(lvl, i)] = F(lvl, data[index(lvl - 1, i * 2)], data[index(lvl - 1, i * 2 + 1)]);
            }
            if (count > 1) build_rec(lvl + 1, count / 2);
            else maxLevel = lvl;
        }

        int get(int lvl, int i) {
            return data[index(lvl, i)];
        }

        /**
         * Equivalent to query(0, end) or get(maxLevel, 0);
         * @return
         */
        int get() {
            return get(maxLevel, 0);
        }

        int query(int left, int right) {
            int leftValue = data[left];
            int rightValue = data[right];
            for (int lvl = 0; lvl < maxLevel; lvl++) {
                if (left == right) {
                    return get(lvl, left);
                }
                if (left + 1 == right) {
                    return F(lvl + 1, leftValue, rightValue);
                }
                if (left % 2 == 0) {
                    leftValue = F(lvl + 1, leftValue, get(lvl, left + 1));
                }
                if (right % 2 == 1) {
                    rightValue = F(lvl + 1, rightValue, get(lvl, right - 1));
                }
                left /= 2;
                right /= 2;
            }
            assert("Can't be"); //unreachable code
        }

        void update(int ind, int value) {
            assert(ind >= 0);
            assert(ind < length);
            data[ind] = value;
            for (int lvl = 1; lvl <= maxLevel; lvl++) {
                ind /= 2;
                data[index(lvl, ind)] = F(lvl, get(lvl - 1, ind * 2), get(lvl - 1, ind * 2 + 1));
            }
        }

        void println() {
            int ln = nearestPowerOfTwo(length);
            for (int lvl = 0; lvl <= maxLevel; lvl++) {
                for (int i = 0; i < ln; i++) {
                    cout << get(lvl, i) << " ";
                }
                ln /= 2;
                cout << endl;
            }
        }
    };

}

int r197__main() {
    fastio;
    int n, m;
    { //solves https://codeforces.com/contest/339/problem/D
        cin >> n >> m;
        ll length = pow(2, n);
        vector<int> nums(length);
        for (int i = 0; i < length; ++i) {
            cin >> nums[i];
        }
        MyTree t = MyTree(&(*nums.begin()), &(*nums.end()), xu);

        for (int i = 0; i < m; ++i) {
            int x, v;
            cin >> x >> v;
            x--;
            t.update(x, v);
            //t.println();
            cout << t.get() << endl;
        }
    }

//    { //https://codeforces.com/contest/369/problem/E
//        cin >> n >> m;
//        vector<int> nums(n);
//        for (int i = 0; i < n; ++i) {
//            int x,y;
//            cin >> x >> y;
//        }
//    }

}