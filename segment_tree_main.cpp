//
// Created by Demeter on 27.09.2018.
//


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <regex> //for __gcd
#include <cassert> //for __gcd

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
        //return min(a, b);
        return (a + b);
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

//struct Segtree {
//    int n;
//    vector<int> data;
//
//    void build_rec(unsigned node, int *begin, int *end) {
//        if (end == begin + 1) {
//            if (data.size() <= node) data.resize(node + 1);
//            data[node] = *begin;
//        } else {
//            int *mid = begin + (end - begin + 1) / 2;
//            build_rec(2 * node + 1, begin, mid);
//            build_rec(2 * node + 2, mid, end);
//            cout << "B " << node << " " << data[2 * node + 1] << "+" << data[2 * node + 2] << endl;
//            data[node] = F(data[2 * node + 1], data[2 * node + 2]);
//        }
//    }
//
//    void update_rec(int node, int begin, int end, int pos, int val) {
//        if (end == begin + 1) {
//            data[node] = val;
//        } else {
//            int mid = begin + (end - begin + 1) / 2;
//            if (pos < mid) {
//                update_rec(2 * node + 1, begin, mid, pos, val);
//            } else {
//                update_rec(2 * node + 2, mid, end, pos, val);
//            }
//            cout << "U " << node << data[2 * node + 1] << "+" << data[2 * node + 2] << endl;
//            data[node] = F(data[2 * node + 1], data[2 * node + 2]);
//        }
//    }
//
//    int query_rec(int node, int tbegin, int tend, int abegin, int aend) {
//        if (tbegin >= abegin && tend <= aend) {
//            return data[node];
//        } else {
//            int mid = tbegin + (tend - tbegin + 1) / 2;
//            int res = INITIAL_VALUE;
//            if (mid > abegin && tbegin < aend)
//                res = F(res, query_rec(2 * node + 1, tbegin, mid, abegin, aend));
//            if (tend > abegin && mid < aend)
//                res = F(res, query_rec(2 * node + 2, mid, tend, abegin, aend));
//            return res;
//        }
//    }
//
//    // Create a segtree which stores the range [begin, end) in its bottommost level.
//    Segtree(int *begin, int *end) {
//        n = end - begin;
//        build_rec(0, begin, end);
//    }
//
//    // Call this to update a value (indices are 0-based).
//    void update(int pos, int val) {
//        update_rec(0, 0, n, pos, val);
//    }
//
//    // Returns F in range [begin, end). Indices are 0-based.
//    int query(int begin, int end) {
//        return query_rec(0, 0, n, begin, end);
//    }
//
//    int query(int index) {
//        return query_rec(0, 0, n, index, index + 1);
//    }
//};


    int st__main() {
        fastio;
//    int n;
//    cin >> n;
        vector<int> input = {1, 5, 12, 6, -1, -3};
        MyTree t = MyTree(&(*input.begin()), &(*input.end()), summa);

        t.println();

        t.update(0, 0);
        t.println();

        t.update(4, 0);
        t.println();

        assert(20 == t.query(0, 5));

//    for (int i = 0; i < input.size(); ++i) {
//        cout << "   t[" << i << "]=" << t.query(i, i);
//    }
//    cout << endl;
//    for (int i = 0; i < input.size()-1; ++i) {
//        cout << "   t[" << i << "+1]=" << t.query(i, i+1);
//    }
//    cout << endl;
//    for (int i = 0; i < input.size()-2; ++i) {
//        cout << "   t[" << i << "+2]=" << t.query(i, i+2);
//    }

//    Segtree s = Segtree(&(*input.begin()), &(*input.end()));
//    cout << s.query(0, 1) << " " << s.query(1, 2) << " " << s.query(2, 3) << " " << s.query(3, 4) << endl;
//    cout << s.query(0, 2) << " " << s.query(1, 3) << " " << s.query(2, 4) << " " << s.query(3, 5) << endl;
//    s.update(5, 2);
//    cout << "Result: " << s.query(0, 6) << endl;


    }

}
