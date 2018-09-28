#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <regex> //for __gcd
#include <assert.h>

#define ul unsigned long long
#define ll long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

void println(vector<int> v) {
    for (int c: v) {
        cout << c << " ";
    }
    cout << endl;
}

void println(vector<ll> v) {
    for (ll c: v) {
        cout << c << " ";
    }
    cout << endl;
}

const int MOD = 1000000007;

class FenvickSum { //https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/
    vector<ll> tree;

public:
    explicit FenvickSum(unsigned int n) {
        tree = vector<ll>(n);
    }

    ll get(int x) {
        ll res = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1) {
            res += tree[x];
        }
        return res;
    }

    ll get(int L, int R) {
        return get(R) - get(L - 1);
    }

    void update(int x, int delta) {
        for (; x < tree.size(); x = (x | (x + 1))) {
            tree[x] += delta;
        }
    }
};

class FenvickSumMod {
    vector<ll> tree;

public:
    explicit FenvickSumMod(unsigned int n) {
        tree = vector<ll>(n);
    }

    ll get(int x) {
        ll res = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1) {
            res += tree[x];
            if (res >= MOD) res -= MOD;
        }
        return res;
    }

    ll get(int L, int R) {
        ll res = get(R) - get(L - 1);
        if (res < 0) res += MOD;
        return res;
    }

    void update(int x, ll delta) {
        delta %= MOD;
        if (delta < 0) delta += MOD;
        assert(delta >= 0);
        for (; x < tree.size(); x = (x | (x + 1))) {
            tree[x] += delta;
            if (tree[x] >= MOD) tree[x] -= MOD;
        }
    }
};

int tech2019_f_main() { //http://codeforces.com/contest/1030/problem/F
//#ifndef NDEBUG
//    freopen("input.txt", "r", stdin);
//#endif // DEBUG
    fastio;
    unsigned n, q;
    cin >> n >> q;

    vector<int> weight(n);
    vector<int> position(n);
    for (int i = 0; i < n; ++i) {
        cin >> position[i];
        position[i] -= i;
    }
    FenvickSum t = FenvickSum(n);
    FenvickSumMod tMod = FenvickSumMod(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
        t.update(i, weight[i]);
        tMod.update(i, position[i] * (ll) weight[i]);
    }

    function solveSlow = [&](int left, int right) {
        ll total = 0;
        ll leftWeigth = 0;
        ll rightWeigth = t.get(left, right);
        for (int x = left; x < right; x++) {
            leftWeigth += weight[x];
            rightWeigth -= weight[x];
            if (position[x + 1] - position[x] == 0) continue;
            ll delta = min(leftWeigth, rightWeigth) * (position[x + 1] - position[x]);
            total += delta % MOD;
        }
        return total % MOD;
    };

    function solveFast = [&](int x, int y) {
        ll sum = t.get(x, y);
        ll need = sum / 2 + t.get(x - 1);
        int l = x - 1;
        int r = y;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (t.get(m) <= need) {
                l = m;
            } else {
                r = m;
            }
        }
        int p = l + 1;
        ll ans = -tMod.get(x, p) + tMod.get(p + 1, y);
        if (ans < 0) ans += MOD;
        ans += (t.get(x, p) % MOD * (ll) position[p]) % MOD;
        if (ans >= MOD) ans -= MOD;
        ans -= (t.get(p + 1, y) % MOD * (ll) position[p]) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    };

    for (int j = 0; j < q; ++j) {
        int x, y;
        cin >> x;
        cin >> y;
        if (x < 0) {
            x = abs(x);
            x--;
            int delta = y - weight[x];
            t.update(x, delta);
            tMod.update(x, position[x] * (ll) delta);
            weight[x] = y;
        } else {
            cout << solveFast(x - 1, y - 1) << endl;
        }
    }
}