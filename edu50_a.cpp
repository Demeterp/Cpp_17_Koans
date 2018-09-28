#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <regex>
#include <cmath>

#define ul unsigned long long
#define ll long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

int edu50_a_d_main() {
    fastio;
/**
    5
    11 2 3 5 7
    4
    11 7 3 7
*/
    unsigned aLength, bLength;
    cin >> aLength;
    vector<ll> a(aLength);
    for (int i = 0; i < aLength; ++i) {
        cin >> a[i];
    }
    cin >> bLength;
    vector<ll> b(bLength);
    for (int i = 0; i < bLength; ++i) {
        cin >> b[i];
    }

    vector<ll> result;

    int aIndex = 0;
    int bIndex = 0;
    ll aa = 0;
    ll bb = 0;
    aa += a[aIndex];
    bb += b[bIndex];
    bool ok = false;
    while (true) {
        if (aa == bb) {
            result.push_back(aa);
            aIndex++;
            bIndex++;
            if (aIndex == aLength && bIndex == bLength) ok = true;
            if (aIndex == aLength || bIndex == bLength) break;
            aa = a[aIndex];
            bb = b[bIndex];
        } else if (aa < bb) {
            aIndex++;
            if (aIndex == aLength) break;
            aa += a[aIndex];
        } else if (aa > bb) {
            bIndex++;
            if (bIndex == bLength) break;
            bb += b[bIndex];
        }
    }

    if (ok) {
        cout << result.size();
    } else {
        cout << -1;
    }

//    int T;
//    vector<pair<ll, ll>> otrezki(T);
//
//    vector<pair<ll, ll>> num;
//    num.emplace_back(0, 0);
//    num.emplace_back(1000, 1000);
//    num.emplace_back(9999, 9999);
//    for (ll i =1;i<9; i++){
//        num.emplace_back(i*10000, i*9999);
//    }
//
//    for (int i = 0; i < T; ++i) {
//        cin >> otrezki[i].first;
//        cin >> otrezki[i].second;
//    }


    //task A
//    ll a, b;
//    cin >> a >> b;
//    long double d = (long double) b / (long double) a;
//    ul res =  ceil(d);

    //task B
//    int q;
//    cin >> q;
//    for (int i = 0; i < q; ++i) {
//        ll x, y, k, res;
//        cin >> x >> y >> k;
//        x = abs(x);
//        y = abs(y);
//        ll base = min(x, y);
//        ll delta = max(x, y) - base;
//        if (base + delta > k) {
//            res = -1;
//        } else {
//            ll rest = k - base;
//            if (delta % 2 != 0) {
//                res = k - 1;
//            } else { //if (delta % 2 == 0) {
//                if (rest % 2 == 0) {
//                    res = k;
//                } else {
//                    res = k - 2;
//                }
//            }
//            //res = k - (delta % 2) - (rest % 2) * 2;
//        }
//        cout << res << endl;
//    }

}

