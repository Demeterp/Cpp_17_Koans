#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <regex>

#define ul unsigned long long
#define ll long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

int operationsLeft;

void op2(int a) {
    if (operationsLeft == 0) return;
    cout << "2 " << a << endl;
    operationsLeft--;
}

void op1(int a, int b) {
    if (operationsLeft == 0) return;
    cout << "1 " << a << " " << b << endl;
    operationsLeft--;
}


const int N = 2e5 + 5;

int n;
ll t;
ll ans;
vector<ll> sum(N);

void solve(int left, int right) {
    if (left == right) return;

    int mid = (left + right) >> 1;
    solve(left, mid);
    solve(mid + 1, right);

    int j = mid + 1;
    for (int i = left; i <= mid; ++i) {
        while (j <= right && sum[j] - sum[i] < t)
            j++;
        ans += j - mid - 1;
    }
    sort(sum.begin() + left, sum.begin() + right + 1);
}

int div510_main() {
    fastio;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    solve(0, n);
    cout << ans;

//    { //taskA
//        int n, m;
//        cin >> n >> m;
//        vector<int> lavochki(n);
//        ul summ = 0;
//        int max = 0;
//        for (int i = 0; i < n; ++i) {
//            cin >> lavochki[i];
//            if (lavochki[i] > max) max = lavochki[i];
//            summ += lavochki[i];
//        }
//
//        int kMax = max + m;
//        long double kMinD = ((long double) summ + m) / n;
//        int kMin = (int) kMinD;
//        if (kMinD - kMin > 0.00001) {
//            kMin++;
//        }
//        if (max > kMin) kMin = max;
//        cout << kMin << " " << kMax;
//    }
//    { //taskB https://codeforces.com/contest/1042/problem/B
//        int n;
//        cin >> n;
//        vector<pair<int, string>> soki;
//        vector<pair<int, string>> sokA;
//        vector<pair<int, string>> sokB;
//        vector<pair<int, string>> sokC;
//
//        for (int i = 0; i < n; ++i) {
//            int price;
//            string vit;
//            cin >> price >> vit;
//            soki.push_back(make_pair(price, vit));
//        }
//        sort(soki.begin(), soki.end());
//
//        for (auto sok : soki) {
//            if (sok.second.find('A') != string::npos) {
//                sokA.push_back(sok);
//            }
//            if (sok.second.find('B') != string::npos) {
//                sokB.push_back(sok);
//            }
//            if (sok.second.find('C') != string::npos) {
//                sokC.push_back(sok);
//            }
//        }
//        //now we have 3 sorted arrays
//        if (sokA.empty() || sokB.empty() || sokC.empty()) {
//            cout << -1;
//            return 0;
//        }
//
//        string vit = "";
//        int summ = 0;
//        int min = 0xFFFFFFF;
//        for(auto a: sokA){
//            summ = a.first;
//            if (summ > min) break;
//            vit = a.second;
//            if (vit.find('A')!=string::npos && vit.find('B')!=string::npos && vit.find('C')!=string::npos){
//                if (summ < min) min = summ;
//            }
//            for (auto b:sokB){
//                summ = a.first + b.first;
//                if (summ > min) break;
//                vit = a.second + b.second;
//                if (vit.find('A')!=string::npos && vit.find('B')!=string::npos && vit.find('C')!=string::npos){
//                    if (summ < min) min = summ;
//                }
//                for (auto c: sokC){
//                    summ = a.first + b.first + c.first;
//                    if (summ > min) break;
//                    vit = a.second + b.second + c.second;
//                    if (vit.find('A')!=string::npos && vit.find('B')!=string::npos && vit.find('C')!=string::npos){
//                        if (summ < min) min = summ;
//                    }
//                }
//            }
//            for (auto c: sokC){
//                summ = a.first + c.first;
//                if (summ > min) break;
//                vit = a.second + c.second;
//                if (vit.find('A')!=string::npos && vit.find('B')!=string::npos && vit.find('C')!=string::npos){
//                    if (summ < min) min = summ;
//                }
//            }
//        }
//        for (auto b:sokB){
//            summ = b.first;
//            if (summ > min) break;
//            vit = b.second;
//            if (vit.find('A')!=string::npos && vit.find('B')!=string::npos && vit.find('C')!=string::npos){
//                if (summ < min) min = summ;
//            }
//            for (auto c: sokC){
//                summ = b.first + c.first;
//                if (summ > min) break;
//                vit = b.second + c.second;
//                if (vit.find('A')!=string::npos && vit.find('B')!=string::npos && vit.find('C')!=string::npos){
//                    if (summ < min) min = summ;
//                }
//            }
//        }
//        for (auto c: sokC){
//            summ = c.first;
//            if (summ > min) break;
//            vit =  c.second;
//            if (vit.find('A')!=string::npos && vit.find('B')!=string::npos && vit.find('C')!=string::npos){
//                if (summ < min) min = summ;
//            }
//        }
//
//        cout << min;
//    }

//    {
//        int n;
//        cin >> n;
//        vector<int> numbers(n + 1);
//        for (int i = 1; i <= n; ++i) {
//            cin >> numbers[i];
//        }
//
//        int countMinus = 0;
//        int minMinusValue = INT_MIN;
//        int minMinusIndex = -1;
//        vector<int> positionsToDelete;
//        for (int i = 1; i < numbers.size(); i++) {
//            int c = numbers[i];
//            if (c < 0) {
//                countMinus++;
//                if (minMinusValue < c) {
//                    minMinusValue = c;
//                    minMinusIndex = i;
//                }
//            }
//            if (c == 0) {
//                positionsToDelete.push_back(i);
//            }
//        }
//
//        operationsLeft = n - 1;
//
//        vector<int> positions;
//
//        if (countMinus > 0) {
//            if (countMinus % 2 > 0) {
//                positionsToDelete.push_back(minMinusIndex);
//            } else {
//                positions.push_back(minMinusIndex);
//            }
//        }
//
//        if (positionsToDelete.size() > 0) {
//            for (int j = 0; j < positionsToDelete.size() - 1; ++j) {
//                op1(positionsToDelete[j], positionsToDelete[j + 1]);
//            }
//            op2(*(positionsToDelete.end() - 1));
//        }
//
//
//        for (int i = 1; i < numbers.size(); i++) {
//            if (numbers[i] != 0 && i != minMinusIndex) {
//                positions.push_back(i);
//            }
//        }
//
//        if (!positions.empty()) {
//            for (int i = 0; i < positions.size() - 1; i++) {
//                op1(positions[i], positions[i + 1]);
//            }
//        }
//
//
//    }
    return 0;
}

