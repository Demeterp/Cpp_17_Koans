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

#define datatype int

    const datatype INITIAL_VALUE = -1;

    datatype mergeColor(int lvl, datatype a, datatype b) {
        if (a == INITIAL_VALUE) return b;
        if (b == INITIAL_VALUE) return a;
        if (a != b) return -1;
        else return a;
    };

    struct PaintTree {

        unsigned length, n, maxLevel;

        vector<datatype> data;
        function<datatype(int, datatype, datatype)> F;

        // Create a segtree which stores the range [begin, end) in its bottommost level.
        PaintTree(unsigned size, function<datatype(int, datatype, datatype)> func) {
            F = func;
            length = size;
            n = nearestPowerOfTwo(length);
            maxLevel = 32 - __builtin_clz(n) - 1;
            data = vector<datatype>(n * 2, INITIAL_VALUE);
            if (length > 1) build_rec(1, n / 2);
        }

        static unsigned nearestPowerOfTwo(unsigned x) {
            if (__builtin_popcount(x) == 1) return x; //power of 2
            else return 1u << (32 - __builtin_clz(x));
        }

        inline int index(int lvl, int i) {
            return (1 << (maxLevel - lvl)) - 1 + i;
        }

        datatype at(int lvl, int i) {
            return data[index(lvl, i)];
        }

        void build_rec(unsigned lvl, int count) {
            for (int i = 0; i < count; i++) {
                data[index(lvl, i)] = F(lvl, data[index(lvl - 1, i * 2)], data[index(lvl - 1, i * 2 + 1)]);
            }
            if (count > 1) build_rec(lvl + 1, count / 2);
            else maxLevel = lvl;
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
            assert("Unreachable Code");
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

        void push(int lvl, int ind) {
            if (lvl == 0) return;
            int color = at(lvl, ind);
            if (color != INITIAL_VALUE) {
                data[index(lvl, ind)] = -1;
                data[index(lvl - 1, ind * 2)] = color;
                data[index(lvl - 1, ind * 2 + 1)] = color;
            }
        }

        static inline int leftPos(int lvl, int ind) {
            int p2 = 1 << lvl;
            return ind * p2;
        }

        static inline int rightPos(int lvl, int ind) {
            int p2 = 1 << lvl;
            return ind * p2 + p2 - 1;
        }

        void paint(int left, int right, datatype color) {
            assert(left >= 0);
            assert(right < length);
            paint(maxLevel, 0, left, right, color);
        }

        void paint(int lvl, int ind, int left, int right, datatype color) {
            int leftB = leftPos(lvl, ind);
            int rightB = rightPos(lvl, ind);
            if (rightB < left) return; //miss
            if (leftB > right) return; //miss
            if (left <= leftB && right >= rightB) {
                data[index(lvl, ind)] = color;
            } else if (lvl > 0) {
                push(lvl, ind);
                paint(lvl - 1, 2 * ind, left, right, color);
                paint(lvl - 1, 2 * ind + 1, left, right, color);
            }
        }

        int getColor(int position) {
            return getColor(maxLevel, 0, position);
        }

        int getColor(int lvl, int ind, int position) {
            int color = at(lvl, ind);
            if (color != INITIAL_VALUE || lvl == 0) return color;
            int leftB = leftPos(lvl, ind);
            int rightB = rightPos(lvl, ind);
            assert(position >= leftB);
            assert(position <= rightB);
            int mid = (leftB + rightB) / 2;
            if (position <= mid)
                return getColor(lvl - 1, 2 * ind, position);
            else
                return getColor(lvl - 1, 2 * ind + 1, position);
        }

        void println() {
            int ln = n;
            for (int lvl = 0; lvl <= maxLevel; lvl++) {
                for (int i = 0; i < ln; i++) {
                    datatype v = at(lvl, i);
                    //if (v == INITIAL_VALUE) continue;
                    //cout << v.first << "," << v.second << "  ";
                    //cout << get<0>(v) << "," << get<1>(v) << "," << get<2>(v) << "   ";
                    cout << v << "  ";
                }
                ln /= 2;
                cout << endl;
            }
        }

    };

}


int main() {
    fastio;
    unsigned n, m, size;

    { //https://codeforces.com/contest/292/problem/E
        //43545400	2018-09-28 21:58:22	Demeter	E - Копирование данных	GNU C++17	Полное решение	654 мс	3000 КБ
        cin >> n >> m;
        vector<datatype> a(n);
        vector<datatype> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        PaintTree tree = PaintTree(n, mergeColor);
        vector<tuple<int, int, int>> zaprosy(m);
        for (int color = 0; color < m; ++color) {
            int t;
            cin >> t;
            if (t == 1) {
                int ax, bx, k;
                cin >> ax >> bx >> k;
                ax--;
                bx--;
                zaprosy[color] = {ax, bx, k};
                int by = bx + k - 1;
                tree.paint(bx, by, color);
            } else {
                int bx;
                cin >> bx;
                bx--;
                int color = tree.getColor(bx);
                if (color == -1) {
                    cout << b[bx] << endl;
                } else {
                    tuple<int, int, int> move = zaprosy[color];
                    int deltaB = bx - get<1>(move);
                    assert(deltaB >= 0);
                    int ind = get<0>(move) + deltaB;
                    cout << a[ind] << endl;
                }
            }
        }

//        t.paint(0, 9, 1);
//        t.paint(0, 5, 2);
//        t.paint(0, 0, 3);
//        t.paint(1, 1, 4);
//        t.println();
//
//        //assert(3 == t.getColor(0));
//        assert(4 == t.getColor(1));
//        assert(2 == t.getColor(2));
//        assert(2 == t.getColor(3));
//        assert(2 == t.getColor(4));
//        assert(2 == t.getColor(5));
//
//        assert(1 == t.getColor(6));
//        assert(1 == t.getColor(7));
//        assert(1 == t.getColor(8));
//        assert(1 == t.getColor(9));
//
//        t.paint(0, 9, 8);
//        t.paint(9, 9, 9);
//        for (int i = 0; i <9 ; ++i) {
//            assert(8 == t.getColor(i));
//        }
//        assert(9 == t.getColor(9));
    }

}