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
    int r, c;
};

const int N = 1e3 + 7;

const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // URDL
const char dir[4] = {'U', 'R', 'D', 'L'};

bool g[N][N];
bool vism[N][N];
bool vish[N][N];
char from[N][N];

int main() {
    vamos;

    int n, m;
    cin >> n >> m;
    queue<point> hero, monsters;
    vector<string> _g(n);
    for (int i = 0; i < n; i++)
        cin >> _g[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (_g[i][j] == 'A') hero.push({i, j}), vish[i][j] = 1, from[i][j] = 'S';
            if (_g[i][j] == 'M') monsters.push({i, j}), vism[i][j] = 1;
            g[i][j] = (_g[i][j] == '.') || (_g[i][j] == 'A');
        }
    }
    while (1) {
        queue<point> _hero, _monsters;
        while (!monsters.empty()) {
            point v = monsters.front();
            monsters.pop();
            for (int i = 0; i < 4; i++) {
                int _r = v.r + dr[i], _c = v.c + dc[i];
                if (_r < 0 || _r >= n || _c < 0 || _c >= m) continue;
                if (!vism[_r][_c] && g[_r][_c]) {
                    vism[_r][_c] = 1;
                    _monsters.push({_r, _c});
                }
            }
        }
        while (!hero.empty()) {
            point v = hero.front();
            hero.pop();
            for (int i = 0; i < 4; i++) {
                int _r = v.r + dr[i], _c = v.c + dc[i];
                if (_r == -1 || _r == n || _c == -1 || _c == m) {
                    cout << "YES\n";
                    char _d = dir[i];
                    string path;
                    // path += _d;
                    while (from[v.r][v.c] != 'S') {
                        path += from[v.r][v.c];
                        _d = path.back();
                        int d;
                        for (int j = 0; j < 4; j++)
                            if (dir[j] == _d) d = j;
                        d = (d + 2) % 4;
                        v = {v.r + dr[d], v.c + dc[d]};
                    }
                    reverse(path.begin(), path.end());
                    cout << (int)path.size() << '\n';
                    cout << path << '\n';
                    return 0;
                }

                if (!vism[_r][_c] && !vish[_r][_c] && g[_r][_c]) {
                    vish[_r][_c] = 1;
                    from[_r][_c] = dir[i];
                    _hero.push({_r, _c});
                }
            }
        }
        swap(hero, _hero);
        swap(monsters, _monsters);
        if (hero.empty()) {
            cout << "NO\n";
            return 0;
        }
    }

    return 0;
}