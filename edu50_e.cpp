#include <iostream>
#include <vector>
//#include <unordered_map>
#include <set>
#include <regex>
#include <cmath>
#include <unordered_set>

#define ul unsigned long long
#define ll long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

int edu50_e_main() {
    fastio;
    int n;
    cin >> n;
    set<pair<int, int>> points;
    set<tuple<int, int, int>> horizontal;
    int horizontalCount = 0;
    set<tuple<int, int, int>> vertical;
    int verticalCount = 0;
    int minusCount = 0;
    for (int count = 0; count < n; ++count) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        int deltaX = abs(ax - bx);
        int deltaY = abs(ay - by);
        if (deltaX == 0) {
            if (ay > by) swap(ay, by);
//            for (int y = ay; y <= by; ++y) {
//                points.insert({ax, y});
//            }
            vertical.insert({ax, ay, by});
            verticalCount += by - ay + 1;
            for (auto it = horizontal.lower_bound({ay, INT_MIN, INT_MIN}); it != horizontal.end(); it++) {
                int y = get<0>(*it);
                if (y > by) break;
                int left = get<1>(*it);
                int right = get<2>(*it);
                if (left <= ax && right >= ax && ay <= y && y <= by) minusCount++;
            }
        } else if (deltaY == 0) {
            if (ax > bx) swap(ax, bx);
//            for (int x = ax; x <= bx; ++x) {
//                points.insert({x, ay});
//            }
            horizontal.insert({ay, ax, bx});
            horizontalCount += bx - ax + 1;
            for (auto it = vertical.lower_bound({ax, INT_MIN, INT_MIN}); it != vertical.end(); it++) {
                int x = get<0>(*it);
                if (x > bx) break;
                int left = get<1>(*it);
                int right = get<2>(*it);
                if (left <= ay && ay <= right && ax <= x && x <= bx) minusCount++;
            }
        } else {
            int gcd = __gcd(deltaX, deltaY);
            int shiftX = deltaX / gcd;
            int shiftY = deltaY / gcd;
            for (int i = 0; i <= (deltaX / shiftX); i++) {
                int x = ax + shiftX * i * ((bx - ax) / deltaX);
                int y = ay + shiftY * i * ((by - ay) / deltaY);
                points.insert({x, y});
            }
        }
    }


    for (auto p: vertical) {
        int x = get<0>(p);
        int left = get<1>(p);
        int right = get<2>(p);
        for (auto it = points.lower_bound({x, left}); it != points.end();) {
            pair<int, int> point = *it;
            if (point.first > x) break;
            if (point.second > right) break;
            if (point.first == x && point.second >= left && point.second <= right) {
                auto erase = it;
                it++;
                points.erase(erase);
            } else {
                it++;
            }
        }
    }


    set<pair<int, int>> points2;
    for (auto &p: points) {
        points2.insert({p.second, p.first});
    }
    points.clear();

    for (auto p: horizontal) {
        int y = get<0>(p);
        int left = get<1>(p);
        int right = get<2>(p);
        for (auto it = points2.lower_bound({y, INT_MIN}); it != points2.end();) {
            pair<int, int> point = *it;
            if (point.first > y) break;
            if (point.first == y && point.second >= left && point.second <= right) {
                auto erase = it;
                it++;
                points2.erase(erase);
            } else {
                it++;
            }
        }
    }



//    for (auto p: points) {
//        cout << p.first << "," << p.second << endl;
//    }

    cout << points2.size() + horizontalCount + verticalCount - minusCount;

}