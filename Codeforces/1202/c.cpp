/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    string s; cin >> s;
    string hor, ver;

    int l = 0, r = 0, u = 0, d = 0;
{
    int i = 0, j = 0;
    for (auto &c : s) {
        if (c == 'W') i--, ckmin(u, i), ver += '0';
        else if (c == 'A') j--, ckmin(l, j), hor += '0';
        else if (c == 'S') i++, ckmax(d, i), ver += '1';
        else j++, ckmax(r, j), hor += '1';
    }
}
    vector<int> hor_path(2 * (int)hor.size() + 1); hor_path[(int)hor.size()] = 1;
    vector<int> ver_path(2 * (int)ver.size() + 1); ver_path[(int)ver.size()] = 1;

    for (int i = 0, curr = (int)hor.size(); i < (int)hor.size(); i++) {
        if (i && hor[i] != hor[i - 1]) hor_path[curr]++;
        if (hor[i] == '0') {
            hor_path[++curr]++;
        } else {
            hor_path[--curr]++;
        }
    }
    int _l = -1, _r = -1;
    for (int i = 0, start = 0; i < (int)hor_path.size(); i++) {
        if (!start && hor_path[i] == 0) continue;
        if (!start && hor_path[i] != 0) {
            start = 1; _l = i;
        }
        if (start && hor_path[i] == 0) {
            _r = i;
            break;
        }
        if (start && i == (int)hor_path.size() - 1) _r = (int)hor_path.size();
    }


    bool hor_shrink = 0, ver_shrink = 0;
    if (--_r > _l) {
        vector<int> _hor_path(2 * (int)hor.size() + 1); _hor_path[(int)hor.size()] = 1;
        for (int i = 0, curr = (int)hor.size(); i < (int)hor.size(); i++) {
            if (i && hor[i] != hor[i - 1]) _hor_path[curr]++;
            if (hor[i] == '0') {
                _hor_path[++curr]++;
            } else {
                _hor_path[--curr]++;
            }
            if (hor_path[_l] == _hor_path[_l] && _hor_path[_r] == 0) {
                hor_shrink = 1;
                break;
            }
            if (hor_path[_r] == _hor_path[_r] && _hor_path[_l] == 0) {
                hor_shrink = 1;
                break;
            }
        }
    }



    for (int i = 0, curr = (int)ver.size(); i < (int)ver.size(); i++) {
        if (i && ver[i] != ver[i - 1]) ver_path[curr]++;
        if (ver[i] == '0') {
            ver_path[++curr]++;
        } else {
            ver_path[--curr]++;
        }
    }
    int _u = -1, _d = -1;
    for (int i = 0, start = 0; i < (int)ver_path.size(); i++) {
        if (!start && ver_path[i] == 0) continue;
        if (!start && ver_path[i] != 0) {
            _u = i;
            start = 1;
        }
        if (start && ver_path[i] == 0) {
            _d = i;
            break;
        }
        if (start && i == (int)ver_path.size() - 1) _d = (int)ver_path.size();
    }
    if (--_d > _u) {
        vector<int> _ver_path(2 * (int)ver.size() + 1); _ver_path[(int)ver.size()] = 1;
        for (int i = 0, curr = (int)ver.size(); i < (int)ver.size(); i++) {
            if (i && ver[i] != ver[i - 1]) _ver_path[curr]++;
            if (ver[i] == '0') {
                _ver_path[++curr]++;
            } else {
                _ver_path[--curr]++;
            }
            if (ver_path[_u] == _ver_path[_u] && _ver_path[_d] == 0) {
                ver_shrink = 1;
                break;
            }
            if (ver_path[_d] == _ver_path[_d] && _ver_path[_u] == 0) {
                ver_shrink = 1;
                break;
            }
        }
    }
    dbg(hor_path, _l, _r);
    dbg(ver_path, _u, _d);

    int w = abs(l - r) + 1;
    int h = abs(u - d) + 1;

    ll ans = (ll) w * h;
    dbg(ans, w, h, ver_shrink, hor_shrink, hor, ver);
    if (w <= h) {
        if (hor_shrink) {
            ans -= h;
        } else if (ver_shrink) ans -= w;
    } else {
        if (ver_shrink) {
            ans -= w;
        } else if (hor_shrink) ans -= h;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}