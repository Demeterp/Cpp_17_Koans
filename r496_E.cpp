#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <regex> //for __gcd
#include <cassert>

#define setmax(x, y) if (x < y) x = y
#define ul unsigned long long
#define ll long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
using namespace std;

int r496_main() {
    fastio;
    unsigned n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &num:a) {
        cin >> num;
    }

    ul count = 0;
    int left;
    int right;
    int mid;
    for (int i = 0; i < n; ++i) {
        left = right = mid = 0;
        for (int j = i; j < n ; ++j) {
            int num = a[j];
            if (num == m) mid++;
            else if (num < m) left++;
            else if (num > m) right++;
            int med = (left + mid + right - 1) / 2 + 1;
            if (med > left && med <= left + mid) count++;
        }
    }


//    vector<int> b; //Превышено ограничение времени на тесте 28	3000 мс
//    for (int i = 0; i < n; ++i) {
//        b.clear();
//        for (int j = i; j < n; ++j) {
//            auto p = lower_bound(b.begin(), b.end(), a[j]);
//            b.insert(p, a[j]);
//            int mid = b[(b.size()-1) / 2];
//            if (mid == m) count++;
//        }
//    }
    cout << count;

}