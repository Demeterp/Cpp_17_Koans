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

#define datatype pair<int, int>

    const datatype INITIAL_VALUE = {INT_MAX, INT_MAX};

    datatype summa(int lvl, datatype a, datatype b) {
        if (a == INITIAL_VALUE) return b;
        if (b == INITIAL_VALUE) return a;

        return make_pair(min(a.first, b.first), max(a.second, b.second));
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
                    return get(lvl, left);
                }
                if (left + 1 == right) {
                    return F(lvl + 1, leftValue, rightValue);
                }
                if ((left & 1) == 0) {
                    leftValue = F(lvl + 1, leftValue, get(lvl, left + 1));
                }
                if (right & 1) {
                    rightValue = F(lvl + 1, rightValue, get(lvl, right - 1));
                }
                left /= 2;
                right /= 2;
            }
            assert("Can't be"); //unreachable code
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
                    cout << get(lvl, i).first << "," << get(lvl, i).second << "  ";
                }
                ln /= 2;
                cout << endl;
            }
        }

        void find(vector<int> &points, int &otrezki, int lvl, int ind) {
            pair<int, int> o = get(lvl, ind);
            auto leftBound = lower_bound(points.begin(), points.end(), o.first);
            auto rightBound = upper_bound(points.begin(), points.end(), o.second) - 1;
            if (leftBound != points.end() && rightBound >= points.begin()) {
                int left = leftBound - points.begin();
                int right = rightBound - points.begin();
                find(left, right, points, otrezki, lvl - 1, ind * 2);
                find(left, right, points, otrezki, lvl - 1, ind * 2 + 1);
            }
        }

        void find(int lower, int upper, vector<int> &points, int &otrezki, int lvl, int ind) {
            pair<int, int> o = get(lvl, ind);
            auto leftBound = lower_bound(points.begin() + lower, points.begin() + upper + 1, o.first);
            auto rightBound = upper_bound(points.begin() + lower, points.begin() + upper + 1, o.second) - 1;

            if (leftBound != (points.begin() + lower, points.begin() + upper + 1) &&
                rightBound >= (points.begin() + lower)) {
                if (lvl == 0) {
                    //otrezki.insert(o);
                    otrezki++;
                } else {
                    int left = leftBound - points.begin();
                    int right = rightBound - points.begin();
                    find(left, right, points, otrezki, lvl - 1, ind * 2);
                    find(left, right, points, otrezki, lvl - 1, ind * 2 + 1);
                }
            }
        }
    };

}

int r126_main() {
    fastio;
    unsigned n, m;
//    { //solves https://codeforces.com/contest/339/problem/D
//        cin >> n >> m;
//        ll length = pow(2, n);
//        vector<int> nums(length);
//        for (int i = 0; i < length; ++i) {
//            cin >> nums[i];
//        }
//        MyTree t = MyTree(&(*nums.begin()), &(*nums.end()), xu);
//
//        for (int i = 0; i < m; ++i) {
//            int x, v;
//            cin >> x >> v;
//            x--;
//            t.update(x, v);
//            //t.println();
//            cout << t.get() << endl;
//        }
//    }


    { //https://codeforces.com/contest/369/problem/E
        cin >> n >> m;
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            nums[i] = {x, y};
        }
        sort(nums.begin(), nums.end());

        MyTree t = MyTree(&(*nums.begin()), &(*nums.end()), summa);
        //t.println();

        for (int i = 0; i < m; ++i) {
            int cnt;
            cin >> cnt;
            vector<int> points(cnt);
            //set<pair<int, int>> otrezki;
            for (int j = 0; j < cnt; ++j) {
                cin >> points[j];
                //t.find(points[j], otrezki, t.maxLevel, 0);
            }
            int otrezki = 0;
            t.find(points, otrezki, t.maxLevel, 0);
            cout << otrezki << endl;
        }
    }

}