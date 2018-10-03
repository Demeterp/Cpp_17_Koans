//
// Created by Demeter on 03.10.2018.
//
#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <regex> //for __gcd
#include <cassert>
#include <cstddef>

#define ul unsigned long long
#define ll long long
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define setmax(x, y) if (x < y) x = y
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)


using namespace std;

//[color][color] <value, rebro number>
vector<tuple<int, unsigned char>> nodes[5][5];
int maxValue;
bool visited[101];
bool visitedNode[5];

void findMax(int node, int summa) {
    bool removeVisit = false;
    if (!visitedNode[node] && nodes[node][node].size() > 0) {
        visitedNode[node] = true;
        removeVisit = true;
        summa += get<0>(nodes[node][node][0]);
    }
    setmax(maxValue, summa);
    for (int i = 1; i < 5; ++i) {
        if (i != node) {
            for (auto rebro : nodes[node][i]) {
                unsigned char num = get<1>(rebro);
                if (!visited[num]) {
                    visited[num] = true;
                    findMax(i, summa + get<0>(rebro));
                    visited[num] = false;
                    break;
                }
            }
        }
    }
    if (removeVisit) {
        visitedNode[node] = false;
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a, b, v;
        cin >> a >> v >> b;
        assert(a <= 4);
        assert(b <= 4);
        nodes[a][b].push_back(make_tuple(v, (unsigned char) i));
        if (a != b) {
            nodes[b][a].push_back(make_tuple(v, (unsigned char) i));
        }
    }

    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (j == i) {
                while (nodes[i][j].size() > 1) {
                    tuple<int, unsigned char> rebro = nodes[i][j].back();
                    nodes[i][j].pop_back();
                    get<0>(nodes[i][j][0]) += get<0>(rebro);
                }
            } else {
                int limit = 2;
                if (nodes[i][j].size() % 2 == 1) {
                    limit = 3;
                }
                sort(nodes[i][j].begin(), nodes[i][j].end());
                while (nodes[i][j].size() > limit) {
                    tuple<int, unsigned char> rebro = nodes[i][j].back();
                    nodes[i][j].pop_back();
                    get<0>(nodes[i][j][limit - 1]) += get<0>(rebro);
                }
                sort(nodes[i][j].rbegin(), nodes[i][j].rend());
            }
        }
    }

    for (int i = 1; i <= 4; ++i) {
        findMax(i, 0);
    }

    cout << maxValue;
}
/**

6
2 1 4
1 2 4
3 4 4
2 8 3
3 16 3
1 32 2


 46
1 40242 4
3 26096 2
3 49445 4
3 45429 2
4 66798 2
1 52701 3
4 11244 4
4 65037 3
4 33954 2
1 42569 2
2 97573 4
2 32648 3
4 17381 4
1 95223 2
2 35482 3
2 5804 2
1 74801 3
4 81742 1
1 30039 4
3 482 1
1 84708 3
3 58521 1
1 66251 3
4 69880 1
4 89921 1
3 77768 2
3 63596 3
3 58591 4
1 4654 4
3 33391 4
4 82706 4
2 973 1
4 34582 1
4 17124 3
2 21625 4
4 34331 3
3 77990 1
2 45059 1
2 99745 3
3 17766 3
3 71090 1
3 35020 1
2 68175 1
2 88847 1
3 4367 3
1 44834 4
**/