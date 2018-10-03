//tasks from C1 Day0
//https://codeforces.com/group/Hva90m7IIH/contest/229115

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <regex>

#define ul unsigned long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

//int solveD(vector<int> &keys, vector<ul> &sums, int l, int r) {
//    long double summNaOtrzeke = keys[r] + sums[r] - sums[l];
//    int lengthOtrzeka = r - l + 1;
//    auto leftIt = keys.begin() + l;
//    auto rightIt = keys.begin() + r;
//    auto it = lower_bound(leftIt, rightIt, summNaOtrzeke / lengthOtrzeka);
//    return *it;
//}
//
//vector<ul> sums(vector<int> &keys) {
//    vector<ul> sums(keys.size());
//    ul sum = 0;
//    for (ul i = 0; i < keys.size(); i++) {
//        sums[i] = sum;
//        sum += keys[i];
//    }
//    return sums;
//}

vector<string> solveC(string &s) {
    vector<string> chisla;
    while (!s.empty()) {
        auto notNull = s.find_first_not_of('0');
        if (notNull != string::npos) {
            s = s.substr(notNull);
        } else {
            s = "";
        }
        if (s.empty()) break;

        string odin(s.length(), '1');
        if (s >= odin) {
            chisla.push_back(odin);
            for (char &c : s) {
                c -= 1;
            }
        } else {
            chisla.emplace_back(string(s.length() - 1, '9'));
            for (int i = 1; i < s.size(); i++) {
                s[i] -= 9;
            }
        }

        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] < '0') {
                s[i] += 10;
                s[i - 1] -= 1;
            }
        }
    }
    return chisla;
}

int maxLength = 0;
int maxCity = 0;
vector<int> putDomoj;
vector<bool> visitedNodes;


void traverse(vector<vector<int>> &nodes, vector<int> &path, int current, int previous) {
    visitedNodes[current] = true;
    path.push_back(current);

    if (path.size() > maxLength) {
        maxLength = path.size();
        maxCity = current;
    }

    for (int nextNode: nodes[current]) {
        if (nextNode == previous) continue;
        if (nextNode == 1 && path.size() > 1) {
            putDomoj = path;
        }
        if (!visitedNodes[nextNode]) {
            traverse(nodes, path, nextNode, current);
            path.pop_back();
        }
    }
}

//tasks from C1 Day0
//https://codeforces.com/group/Hva90m7IIH/contest/229115

int day0_main() {
    fastio;

//    { // task D
//        //go read some https://cses.fi/book/book.pdf
//        int n, m;
//        cin >> n >> m;
//        vector<int> keys(n);
//
//        for (int i = 0; i < n; i++) {
//            cin >> keys[i];
//        }
//        vector<ul> summs = sums(keys);
//        for (int i = 0; i < m; i++) {
//            int l, r;
//            cin >> l >> r;
//            cout << solveD(keys, summs, l - 1, r - 1) << endl;
//        }
//    }

//    { //task A
//        int n;
//        cin >> n;
//        vector<int> mestoByDrug(n+1);
//        for (int mesto = 1; mesto <= n; mesto++) {
//            int drug;
//            cin >> drug;
//            mestoByDrug[drug] = mesto;
//        }
//        for (int drug = 1; drug <= n; drug++) {
//            cout << mestoByDrug[drug] << " ";
//        }
//    }

//    { //task F
//        int n;
//        cin >> n;
//        multiset<int> processes;
//        for (int i = 0; i < 2 * n + 1; i++) {
//            int id;
//            cin >> id;
//            processes.insert(id);
//        }
//        for (int p: processes) {
//            if (processes.count(p) == 1) {
//                cout << p;
//                return 0;
//            }
//        }
//    }

//    { // task C
//        string s;
//        cin >> s;
//
//        vector<string> chisla = solveC(s);
//
//        cout << chisla.size() << endl;
//        for (string ch: chisla){
//            cout << ch << " ";
//        }
//    }

//    { // task B
//        int l, r;
//        cin >> l >> r;
//
//        ul s = 1;
//        for (ul i = l; i <= r; i++) {
//            if (__gcd(s, i) == 1) {
//                s += i;
//            }
//        }
//        cout << s;
//    }

//    { //task A2 TreeMap, suppose druzja idut ne podrad
//        int n;
//        cin >> n;
//        map<int, int> mestoByDrug;
//        for (int mesto = 1; mesto <= n; mesto++) {
//            int drug;
//            cin >> drug;
//            mestoByDrug[drug] = mesto;
//        }
//        for (pair<int, int> drug : mestoByDrug) {
//            cout << drug.second << " ";
//        }
//    }

//    { //task A3 using sort
//        int n;
//        cin >> n;
//        vector<pair<int, int>> mestoByDrug;
//        int drug;
//        for (int mesto = 1; mesto <= n; mesto++) {
//            cin >> drug;
//            mestoByDrug.emplace_back(make_pair(drug, mesto));
//        }
//
//        sort(mestoByDrug.begin(), mestoByDrug.end());
//
//        for (pair<int, int> pair : mestoByDrug) {
//            cout << pair.second << " ";
//        }
//    }
    { //task E
        int n, m;
        cin >> n >> m;
        vector<vector<int>> nodes(n + 1);
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            nodes[l].push_back(r);
            nodes[r].push_back(l);
        }

        visitedNodes.reserve(n + 1);
        for (int j = 1; j <= n; ++j) {
            visitedNodes[j] = false;
        }
        vector<int> path;
        traverse(nodes, path, 1, -1);

        if (putDomoj.empty()) {
            cout << "-1" << endl;
            cout << maxCity;
        } else {
            cout << putDomoj.size() << endl;
            for (int node : putDomoj) {
                cout << node << " ";
            }
        }
    }

    return 0;
}

