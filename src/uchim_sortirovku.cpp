//
// Created by Demeter on 20.09.2018.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct man {
    int height;
    string name;
};

//https://stepik.org/lesson/13030/step/2

int sort_main() {
    unsigned n;
    cin >> n;

    vector<int> chisla(n);
    for (int i = 0; i < n; i++) {
        cin >> chisla[i];
    }
    sort(chisla.begin(), chisla.end());

    for (auto now : chisla) {
        cout << now << endl;
    }



//    vector<pair<int, string>> pairs(n);
//    for (int i = 0; i < n; i++) {
//        int j;
//        string s;
//        cin >> j >> s;
//        pairs[i] = pair(j, s); // создание пары значение - номер
//    }
//    sort(pairs.begin(), pairs.end());
//
//    for (auto now : pairs) {
//        cout << now.second << endl;
//    }


//    vector<man> men(n);
//    for (int i = 0; i < n; i++) {
//        man tmp; // временная структура
//        cin >> tmp.height >> tmp.name;
//        men[i] = tmp; // создание пары значение - номер
//    }
//    sort(men.begin(), men.end(), [](man a, man b) { return a.height < b.height; });
//
//    for (auto now : men) {
//        cout << now.name << endl;
//    }
    return 0;
}
