//tasks from

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <regex>

#define ul unsigned long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

int ss__main() {
    fastio;
//    { http://codeforces.com/contest/1041/problem/A
//        int n;
//        cin >> n;
//        set<int> keys;
//        for (int i = 0; i < n; ++i) {
//            int v;
//            cin >> v;
//            keys.insert(v);
//        }
//        int delta = *(--keys.end()) - *keys.begin();
//        int stolen = 1+ delta - keys.size();
//        cout << stolen;
//
//    }

//    //http://codeforces.com/contest/1041/problem/B
//    {
//        ul a, b, x, y;
//        cin >> a >> b >> x >> y;
//        ul g = __gcd(x, y);
//        ul w = x / g;
//        ul h = y / g;
//        x = a / w;
//        y = b / h;
//        cout << min(x,y);
//    }


//    { //task C
//        int n, m, d;
//        //200000 1000000000 231340971
//
//        cin >> n >> m >> d;
//        set<int> minutes;
//        unordered_map<int,int> indexByMinute;
//        for (int index = 1; index <= n; ++index) {
//            int minute;
//            cin >> minute;
//            minutes.insert(minute);
//            indexByMinute[minute] = index;
//        }
//        int day = 0;
//        vector<int> dayByIndex(n + 1);
//        while (!minutes.empty()) {
//            day++;
//            int minute = -d;
//            auto it = minutes.begin();
//            while (it != minutes.end()) {
//                minute = *it;
//                dayByIndex[indexByMinute[minute]] = day;
//                minutes.erase(it);
//                it = minutes.lower_bound(minute + d + 1);
//            }
//        }
//        cout << day << endl;
//        for (int i = 1; i <= n; ++i) {
//            cout << dayByIndex[i] << " ";
//        }
//  }

    { //task D http://codeforces.com/contest/1041/problem/D
        int n, h; //n < 2 * 10^5
        cin >> n >> h;
        vector<pair<int, int>> potoki(n);
        vector<ul> sums(n);
        vector<int> nado(n);
        int lastNado = 0;
        int lastRight = INT_MAX;
        ul sum = 0;
        for (int i = 0; i < n; ++i) {
            int left, right;
            cin >> left >> right;
            sum += right - left;
            sums[i] = sum;
            potoki[i] = {left, right};
            if (lastRight != INT_MAX) {
                lastNado += left - lastRight;
            }
            nado[i] = lastNado;
            lastRight = right;
        }

        ul maxSumm = 0;
        for (int i = 0; i < n; ++i) { //perebor
            auto it = upper_bound(nado.begin() + i, nado.end(), h + nado[i] - 1);
            int index = it - nado.begin() - 1;
            if (index < i) continue;
            sum = sums[index];
            if (i > 0) sum -= sums[i - 1];
            if (sum > maxSumm) maxSumm = sum;
        }

        cout << maxSumm + h;
    }

}