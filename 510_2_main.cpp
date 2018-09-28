#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename A>
using ordered_set = tree<A, null_type, less<A>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int div510_2_main() {
    ios::sync_with_stdio(0);
    cin.tie();
    unsigned int n;
    ll t;
    cin >> n >> t;
    ordered_set<pair<ll, int>> X;

    ll ans = 0;

//    ll sum = 0;
//    X.insert(make_pair(sum, 0));
//    for (int i = 1; i <= n; ++i) {
//        ll s;
//        cin >> s;
//        sum += s;
//        ans += X.size() - X.order_of_key(make_pair(-(t - sum - 1), 0));
//        X.insert(make_pair(sum, i));
//    }

    vector<ll> p(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i - 1];
        X.insert({p[i], i});
    }
    for (int i = 0; i < n; i++) {
        X.erase({p[i], i});
        ans += X.order_of_key({p[i] + t, -1});
    }

    cout << ans << "\n";
}

