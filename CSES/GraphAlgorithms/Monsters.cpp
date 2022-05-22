/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

struct point {
    int x, y;
};

const int N = 1e3 + 7;

bool g[N][N];
bool vis[N][N];

int main() {
    vamos;

    int n, m; cin >> n >> m;
    queue<point> hero, monsters;

    vector<string> _g(n);
    for (int i = 0; i < n; i++) cin >> _g[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(_g[i][j] == 'A') hero.push({i, j}), vis[i][j] = 1;
            else if(_g[i][j] == 'M') monsters.push({i, j}), vis[i][j] = 1;
            else g[i][j] = _g[i][j] == '.';
        }
    }



    return 0;
}