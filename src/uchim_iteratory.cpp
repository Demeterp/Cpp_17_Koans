//
// Created by Demeter on 21.09.2018.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void println(string s) {
    cout << s << endl;
}

int main() {
    string stroka = "Utrom v rzhanom zakute";

    println(stroka);
    for (char c:stroka) {
        cout << c;
    }
    cout << endl;

    for (int i = 0; i < stroka.length(); i++) {
        cout << stroka[i];
    }
    cout << endl;

    for (auto it = stroka.begin(); it != stroka.end(); it++) {
//        if (*it == 'a')
//            stroka.erase(it);
        cout << *it;
    }
    cout << endl;


    reverse(stroka.begin(), stroka.end());
    println(stroka);

    reverse(stroka.begin(), stroka.end() - 6);
    println(stroka);

    stroka.insert(9, " <ZZZ> ");
    println(stroka);

    stroka.erase(9, 8);
    println(stroka);

    stroka.insert(9, " <ZZZ> ");
    println(stroka);

    stroka.replace(9, 7, " [YYY_XXX] ");
    println(stroka);

    //http://www.cplusplus.com/reference/string/string/replace/


    stroka.erase(stroka.begin() + 9, stroka.end() - 9);
    println(stroka);

    stroka.clear();
    string another = "Once 999 upon a Time 999 in America  567";

    for (char c: another) {
        stroka.push_back(c);
    }

    stroka.swap(another);
    println(stroka);
    println(another);


    cout << stroka.find("999", 10) << endl;


    for (auto it = stroka.begin(); it != stroka.end(); it++) {
        if (' ' == *it) {
        } else if ('0' <= *it and *it <= '9' ){
            if (*(it+1) != ' ') *it -= 1;
        } else {
            *it += 1;
        }
    }
    println(stroka);

    stroka.assign(another);
    for (char &it : stroka) {
        if (' ' == it) {
            it = '_';
        } else if ('0' <= it and it <= '9') {
            it -= 1;
        } else {
            it += 2;
        }
    }
    println(stroka);



    //Zadacha 1: udalit vse glasnye v stroke

    //Zadacha 2: udalit vse glasnye v stroke krome teh chto v konce slov

    //Zadacha 3: vse cifry v stroke umnozhit na 3 (mogut poluchits chisla)

}