//
// Created by Demeter on 21.09.2018.
//
#include <string>
#include <iostream>
#include <algorithm>
#include "uchim_string.h"

using namespace std;

void println(string s) {
    cout << s << endl;
}

//make it return "Utrom v rzhanom zakute"
string fixme1() { //fix me
    return "Utrom v rzhanom zakute";
    //return "";
}

void fixme2(string &s) { //fix me
    s = "Utrom v rzhanom zakute";
}


//return copy of s with use of for loop
//use push_back() function
string fixme3(string s) { //fix me
    string result;
    for (int i = 0; i < s.length(); i++) {
        result.push_back(s[i]);
    }
    //do not forgot to return result
    return result;
}


//return copy of s with use of for loop
//use result += c;
string fixme4(string in) {
    string result;
    for (char c: in) {
        result += c;
    }
    //do not forgot to return result
    return result;
}

void fixme5(string in, string &out) { //use assign function
    out.assign(in);
}

void fixme6(string &inout) { //fix me
    for (auto it = inout.begin(); it != inout.end(); it++) {
        if (*it == 'a')
            inout.erase(it);
    }
}


void fixme7(string &inout) { //reverse whole line
    reverse(inout.begin(), inout.end());
}

void fixme8(string &inout) { //reverse whole line except last word
    reverse(inout.begin(), inout.end() - 7);
}

//insert missing word make it work
void fixme9(string &inout) { //fix me
    inout.insert(8, "rzhanom");
}

//sotri slovo "Utrom " v stroke
void fixme10(string &inout) { //fix me
    inout.erase(0, 6);
}

//replace slovo rzhanom na mrachnom v stroke
void fixme11(string &inout) { //use raplace function
    inout.replace(inout.find("rzhanom"), 7, "mrachnom");
}

//ochisti stroku
void fixme12(string &inout) { //use clear function
    inout.clear();
}

void fixme13(string &inout) { //fix me
}

void fixme14(string &inout) { //fix me
}

//swap two string contents
void fixme15(string &inout1, string &inout2) { //use swap function
    swap(inout1, inout2);
}


