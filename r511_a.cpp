#pragma GCC optimize("O3")

//
// Created by Demeter on 29.09.2018.
//
#include <iostream>
#include <vector>
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

void println(vector<int> v) {
    for (auto now : v) {
        cout << now << ' ';
    }
    cout << endl;
}

void println(set<int> v) {
    for (auto now : v) {
        cout << now << ' ';
    }
    cout << endl;
}

void println(multiset<int> v) {
    for (auto now : v) {
        cout << now << ' ';
    }
    cout << endl;
}

int gcdAll(vector<int> &nums) {
    int gcd = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (gcd == 1) break;
        gcd = __gcd(gcd, nums[i]);
    }
    return gcd;
}


//task C staff start
#define  MX 15000000
int freq[MX + 1];
int minDiv[MX + 1];
int prime[MX + 1];
int nums[3 * 100000 + 1];
//task C staff end


int main() {
    fastio;

    {  //task C https://codeforces.com/contest/1047/problem/C brute 295 мс !!!
        unsigned n;
        cin >> n;
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;
        int g = arr[0];
        for (auto i : arr) g = __gcd(g, i);
        for (auto &i : arr) i /= g;
        for (auto &i : arr) {
            for (int j = 2; j * j <= i && n * j <= MX; ++j) {
                if (i % j == 0) freq[j]++;
                while (i % j == 0) i /= j;
            }
            if (i > 1) freq[i]++;
        }
        ll mx = 0;
        for (int i : freq) setmax(mx, i);
        if (mx == 0) cout << -1;
        else cout << n - mx;
        return 0;
    }

    { //task C https://codeforces.com/contest/1047/problem/C

        clock_t z = clock();
        int primeCount = 0;
        {//linear eratosfen - http://e-maxx.ru/algo/prime_sieve_linear
            for (int i = 2; i <= MX; ++i) {
                if (minDiv[i] == 0) {
                    prime[primeCount++] = minDiv[i] = i;
                }
                for (int j = 0; j < primeCount && prime[j] <= minDiv[i] && i * prime[j] <= MX; ++j) {
                    minDiv[i * prime[j]] = prime[j];
                }
            }
        }
        debug("Total Time: %.3f\n", (double) (clock() - z) / CLOCKS_PER_SEC);

        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> nums[i];
        }

        z = clock();
        int gcd = nums[1];
        for (int i = 2; i <= n; ++i) {
            gcd = __gcd(gcd, nums[i]);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = nums[i] / gcd; j > 1;) {
                int x = minDiv[j];
                ++freq[x];
                while (minDiv[j] == x) {
                    j /= minDiv[j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < primeCount; ++i) {
            ans = max(ans, freq[prime[i]]);
        }
        cout << (ans ? n - ans : -1);

        debug("Total Time: %.3f\n", (double) (clock() - z) / CLOCKS_PER_SEC);
    }

//    { //task A https://codeforces.com/contest/1047/problem/A
//        int n;
//        cin >> n;
//        int a1 = n / 3;
//        int b1 = n / 3;
//        int c1 = n / 3;
//
//        int left = -3;
//        int right = 5;
//
//        for (int i = left; i < right; i++) {
//            int a = a1 + i;
//            if (a < 1) continue;
//            for (int j = left; j < right; j++) {
//                int b = b1 + j;
//                if (b < 1) continue;
//                int c = n - a - b;
//                if (c < 1) continue;
////                if (a==b) continue;
////                if (b==c) continue;
////                if (a==c) continue;
//                if (a % 3 != 0 && b % 3 != 0 && c % 3 != 0) {
//                    cout << a << " " << b << " " << c;
//                    return 0;
//                }
//            }
//        }
//    }

//    { // taskB https://codeforces.com/contest/1047/problem/B
//        int n;
//        cin >> n;
//        int maxXY = 0;
//        for (int i = 0; i < n; ++i) {
//            int x, y;
//            cin >> x >> y;
//            if (x + y > maxXY) maxXY = x + y;
//        }
//        cout << maxXY;
//    }


}