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
//        if (a == INITIAL_VALUE) return b;
//        if (b == INITIAL_VALUE) return a;
        if (a != b) return -1;
        else return a;
    };

    datatype summa(int lvl, datatype a, datatype b) {
        if (a == INITIAL_VALUE) return b;
        if (b == INITIAL_VALUE) return a;
        return a + b;
    };

    struct PaintTree {

        unsigned length, n, maxLevel;

        vector<datatype> data;
        //vector<datatype> lazy;
        function<datatype(int, datatype, datatype)> F;

        // Create a segtree which stores the range [begin, end) in its bottommost level.
        PaintTree(unsigned size, function<datatype(int, datatype, datatype)> func) {
            F = func;
            length = size;
            n = nearestPowerOfTwo(length);
            maxLevel = 32 - __builtin_clz(n) - 1;
            data = vector<datatype>(n * 2, INITIAL_VALUE);
            //lazy = vector<datatype>(n * 2, 0);
            if (length > 1) build_rec(1, 0, n / 2);
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

        /**
         * Equivalent to query(0, end) or at(maxLevel, 0);
         * @return
         */
        datatype at() {
            return at(maxLevel, 0);
        }

        datatype query(int left, int right) {
            datatype leftValue = at(0, left);
            datatype rightValue = at(0, right);
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

        static inline int leftInd(int node) {
            return node * 2 + 1;
        }

        static inline int rightInd(int node) {
            return node * 2 + 2;
        }

        datatype leftValue(int node) {
            return data[leftInd(node)];
        }

        datatype rightValue(int node) {
            return data[rightInd(node)];
        }

        void update(int ind, datatype value) {
            assert(ind >= 0);
            assert(ind < length);
            data[index(0, ind)] = value;
            for (int lvl = 1; lvl <= maxLevel; lvl++) {
                ind /= 2;
                int node = index(lvl, ind);
                data[node] = F(lvl, leftValue(node), rightValue(node));
            }
        }

        void push(int lvl, int ind) {
            push(index(lvl, ind));
        }

        void push(int node) {
            if (node > n) return;
            int color = data[node];
            if (color != INITIAL_VALUE) {
                data[node] = -1;
                data[leftInd(node)] = color;
                data[rightInd(node)] = color;
            }
        }

        static inline int leftBound(int lvl, int ind) {
            return ind * 1 << lvl;;
        }

        static inline int rightBound(int lvl, int ind) {
            return (ind + 1) * (1 << lvl) - 1;
        }

        void updateRange(int left, int right, datatype delta) {
            for (int i = left; i <= right; i++) {
                data[n - 1 + i] += delta;
            }
            build_rec(1, left / 2, right / 2);
        }

        void build_rec(unsigned lvl, int left, int right) {
            for (int i = left; i <= right; i++) {
                int node = index(lvl, i);
                data[node] = F(lvl, leftValue(node), rightValue(node));
            }
            if (lvl != maxLevel) build_rec(lvl + 1, left / 2, right / 2);
        }

        void paint(int left, int right, datatype color) {
            paint(0, left, right, color, 0, n - 1);
        }

        void paint(int node, int left, int right, datatype color, int leftB, int rightB) {
            if (rightB < left) return; //miss
            if (leftB > right) return; //miss
            if (left <= leftB && right >= rightB) {
                data[node] = color;
            } else if (node <= n) {
                push(node);
                int mid = (leftB + rightB) >> 1;
                paint(leftInd(node), left, right, color, leftB, mid);
                paint(rightInd(node), left, right, color, mid + 1, rightB);
            }
        }

        int getColor(int position) {
            return getColor(0, position, 0, n - 1);
        }

        int getColor(int node, int position, int leftB, int rightB) {
            int color = data[node];
            if (color != INITIAL_VALUE || node > n) return color;
            assert(position >= leftB);
            assert(position <= rightB);
            int mid = (leftB + rightB) >> 1;
            if (position <= mid)
                return getColor(leftInd(node), position, leftB, mid);
            else
                return getColor(rightInd(node), position, mid + 1, rightB);
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

    PaintTree t = PaintTree(10, mergeColor);
    t.paint(0, 9, 1);
    t.paint(0, 5, 2);
    t.paint(0, 0, 3);
    t.paint(1, 1, 4);
    t.println();

    //assert(3 == t.getColor(0));
    assert(4 == t.getColor(1));
    assert(2 == t.getColor(2));
    assert(2 == t.getColor(3));
    assert(2 == t.getColor(4));
    assert(2 == t.getColor(5));

    t.println();
    assert(1 == t.getColor(6));
    assert(1 == t.getColor(7));
    assert(1 == t.getColor(8));
    assert(1 == t.getColor(9));

    t.paint(0, 9, 8);
    t.paint(9, 9, 9);
    for (int i = 0; i < 9; ++i) {
        assert(8 == t.getColor(i));
    }
    assert(9 == t.getColor(9));

    t.updateRange(0, 5, 1);
    t.println();

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


    }

}