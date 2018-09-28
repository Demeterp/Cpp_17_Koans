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

#define datatype tuple<int, int, int>

    const datatype INITIAL_VALUE = {0, 0, 0};

    datatype summa(int lvl, datatype a, datatype b) {
        if (a == INITIAL_VALUE) return b;
        if (b == INITIAL_VALUE) return a;
        int gcdLeft = get<2>(a);
        int gcdRight = get<2>(b);
        int wc = 0;
        int winner = min(get<0>(a), get<0>(b));
        if (gcdRight % get<0>(a) == 0) {
            wc += get<1>(a);
        }
        if (gcdLeft % get<0>(b) == 0) {
            wc += get<1>(b);
        }
        return {winner, wc, __gcd(gcdLeft, gcdRight)};
    };


    struct MyTree {
        unsigned length, n, maxLevel;
        vector<int> shiftByLevel;

        vector<datatype > data;
        function<datatype(int, datatype, datatype)> F;

        // Create a segtree which stores the range [begin, end) in its bottommost level.
        MyTree(datatype *begin, datatype *end, function<datatype(int, datatype, datatype)> func) {
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
            data = vector<datatype >(n * 2, INITIAL_VALUE);
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

        datatype at(int lvl, int i) {
            return data[index(lvl, i)];
        }

        /**
         * Equivalent to query(0, end) or at(maxLevel, 0);
         * @return
         */
        datatype at() {
            return at(maxLevel, 0);
        }

        datatype query(int left, int right) {
            datatype leftValue = data[left];
            datatype rightValue = data[right];
            if (left == right) {
                return leftValue;
            }
            for (int lvl = 0; lvl < maxLevel; lvl++) {
                if (left + 1 == right) {
                    return F(lvl + 1, leftValue, rightValue);
                }
                if ((left & 1) == 0) { //chet
                    leftValue = F(lvl + 1, leftValue, at(lvl, left + 1));
                }
                if (right & 1) { //nechet
                    rightValue = F(lvl + 1, at(lvl, right - 1), rightValue);
                }
                left /= 2;
                right /= 2;
            }
            assert("Can't be"); //unreachable code
        }

        int queryGood(int left, int right) {
            int len = right - left + 1;
            datatype value = query(left, right);
            return len - std::get<1>(value);
        }

        void update(int ind, datatype value) {
            assert(ind >= 0);
            assert(ind < length);
            data[ind] = value;
            for (int lvl = 1; lvl <= maxLevel; lvl++) {
                ind /= 2;
                data[index(lvl, ind)] = F(lvl, at(lvl - 1, ind * 2), at(lvl - 1, ind * 2 + 1));
            }
        }

        void println() {
            int ln = n;
            for (int lvl = 0; lvl <= maxLevel; lvl++) {
                for (int i = 0; i < ln; i++) {
                    datatype v = at(lvl, i);
                    if (v == INITIAL_VALUE) continue;
                    //cout << at(lvl, i).first << "," << at(lvl, i).second << "  ";
                    cout << get<0>(v) << "," << get<1>(v) << "," << get<2>(v) << "   ";
                }
                ln /= 2;
                cout << endl;
            }
        }

    };

}


int r271_f_main() {
    fastio;
    unsigned n, m;

    { //https://codeforces.com/contest/380/problem/C
        cin >> n;
        vector<datatype > nums(n);
        for (int i = 0; i < n; ++i) {
            int s;
            cin >> s;
            nums[i] = {s, 1, s};
        }
        MyTree t = MyTree(&(*nums.begin()), &(*nums.end()), summa);
        //t.println();

        cin >> m;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << t.queryGood(x, y) << endl;
        }
    }

    return 0;
}