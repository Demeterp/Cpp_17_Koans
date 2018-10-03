#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <regex> //for __gcd

#define ul unsigned long long
#define ll long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

ll h;

pair<ll, ll> capacity(ll width) {
    return make_pair(width * (width + 1) / 2, width);
};

pair<ll, ll> nextCapacity(ll lastCapacity, ll lastHeight) {
    ll height = lastHeight + 1;
    return make_pair(lastCapacity+height, height);
};


int r44edu_main() {
    fastio;
    { // task D https://codeforces.com/contest/985/problem/D
        ll n, h;
        cin >> n >> h;

        ll aa = min((ll) sqrt(n) - 1, h);
        pair<ll, ll> curr;
        for (ll w = aa; w < n; w++) {
            if (w <= h) {
                curr = capacity(w);
            } else {
                curr = nextCapacity(curr.first, curr.second);
            }
            if (curr.first >= n) {
                cout << w;
                break;
            }
        }
    }
    return 0;
}