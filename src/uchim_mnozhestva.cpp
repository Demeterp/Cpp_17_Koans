//
// Created by Demeter on 20.09.2018.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


//https://stepik.org/lesson/13029/step/2?unit=4381
void println(vector<int> v){
    for (auto now : v) {
        cout << now << ' ';
    }
    cout << endl;
}
void println(set<int> v){
    for (auto now : v) {
        cout << now << ' ';
    }
    cout << endl;
}
void println(multiset<int> v){
    for (auto now : v) {
        cout << now << ' ';
    }
    cout << endl;
}


int mnozhestva_main() {
    vector<int> chisla = {6, 5, 5, 4, 4, 3, 1, 1, 1, 144, 2, 2, 1, 2 };

    println(chisla);

    sort(chisla.begin(), chisla.end());
    println(chisla);

    cout << chisla.back() << endl;

    reverse(chisla.begin(), chisla.end());
    println(chisla);


    set<int> tree;
    multiset<int> sorted;

    //kladem vse v oba mnozhestva
    for (auto now : chisla) {
        //napishi tut chtoto
        //insert
    }

    for (auto now = tree.begin(); now != tree.end(); now++) {
        cout << *now << ' ';
    }
    cout << endl;

    cout << endl << " set  : ";
    for (auto now : tree) {
        cout << now << ' ';
    }


    cout << endl << "sorted: ";

    println(sorted);

    cout << endl;
    for (auto now : sorted) {
//        cout << now << '(' << .count() << ')';
    }
    cout << endl;

    cout << *sorted.find(144) << endl;
    sorted.erase(2);
    sorted.erase(--sorted.find(6));
    println(sorted);


    map<int, string> numToName;
    numToName[112] = "sos";
    if (numToName.count(112) > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


    //================================= Part 2 ============================
//
//    map<string, vector<string>> nameToNums;
//    nameToNums["Vasya"] = {"112133", "12341"};
//    nameToNums["Dima"] = {"2349298", "+7(981)7244645"};
//
//    cout << endl << "Hard  one : ";
//    for (auto now : nameToNums["Vasya"]) {
//        cout << now << " ";
//    }
//
//
//    cout << endl << "Now simple: ";
//    multimap<string, string> nameToNum = {};
//    nameToNum.insert(make_pair("vasya", "112133"));
//    nameToNum.insert(make_pair("vasya", "12341"));
//    for (pair<string, string> now : nameToNum) {
//        cout << now.second << " ";
//    }
    return 0;
}
