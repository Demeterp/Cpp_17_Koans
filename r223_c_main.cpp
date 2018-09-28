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

    const datatype INITIAL_VALUE = tuple(0, 0, 0);

    datatype merge(int lvl, datatype a, datatype b) {
        if (a == INITIAL_VALUE) return b;
        if (b == INITIAL_VALUE) return a;
        int t = min(get<1>(a), get<2>(b));
        return {get<0>(a) + get<0>(b) + t, get<1>(a) + get<1>(b) - t, get<2>(a) + get<2>(b) - t};
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

        datatype get(int lvl, int i) {
            return data[index(lvl, i)];
        }

        /**
         * Equivalent to query(0, end) or get(maxLevel, 0);
         * @return
         */
        datatype get() {
            return get(maxLevel, 0);
        }

        datatype query(int left, int right) {
            datatype leftValue = data[left];
            datatype rightValue = data[right];
            for (int lvl = 0; lvl < maxLevel; lvl++) {
                if (left == right) {
                    return leftValue;
                }
                if (left + 1 == right) {
                    return F(lvl + 1, leftValue, rightValue);
                }
                if ((left & 1) == 0) { //chet
                    leftValue = F(lvl + 1, leftValue, get(lvl, left + 1));
                }
                if (right & 1) { //nechet
                    rightValue = F(lvl + 1, get(lvl, right - 1), rightValue);
                }
                left /= 2;
                right /= 2;
            }
            assert("Can't be"); //unreachable code
        }

        int queryGood(int left, int right) {
            if (left == right) return 0;
            datatype value = query(left, right);
            return std::get<0>(value) * 2;
        }

        void update(int ind, datatype value) {
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
                    //cout << get(lvl, i).first << "," << get(lvl, i).second << "  ";
                    datatype v = get(lvl, i);
                    if (v == INITIAL_VALUE) continue;
                    cout << std::get<0>(v) << "," << std::get<1>(v) << "," << std::get<1>(v) << "   ";
                }
                ln /= 2;
                cout << endl;
            }
        }

    };


    int r223_main() {
        fastio;
        unsigned n, m;

        { //https://codeforces.com/contest/380/problem/C
            string s;
            getline(cin, s);
            s.erase(find_if(s.rbegin(), s.rend(), [](int ch) { return !isspace(ch); }).base(), s.end());
            n = s.length();
            vector<tuple<int, int, int>> nums(n);
            for (int i = 0; i < n; ++i) {
                nums[i] = {0, s[i] == '(' ? 1 : 0, s[i] == ')' ? 1 : 0};
            }
            MyTree t = MyTree(&(*nums.begin()), &(*nums.end()), merge);
            //t.println();

            cin >> m;
            for (int i = 0; i < m; ++i) {
                int x, y;
                cin >> x >> y;
                x--;
                y--;
                //cout << s.substr(x, y - x + 1) << "  ";
                cout << t.queryGood(x, y) << endl;
            }
        }

    }

}
