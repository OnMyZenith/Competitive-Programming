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


template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &r : a) {
        for (auto &e : r) {
            cin >> e;
        }
    }
    int l = -1, r = -1;
    // pair<int, int> r = {-1, m - 1};
    vector<bool> ok_row(n, 1);
    vector<pair<int, int>> f_up(n, {-1, -1});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if(a[i][j] > a[i][j + 1]) {
                ok_row[i] = 0;
                if(f_up[i].second != -1) goto kill;
                if(f_up[i].first != -1) f_up[i].second = j + 1;
                else f_up[i].first = j;
            }
        }
        dbg(f_up[i], i + 1);
        if(!ok_row[i]) {
            int _l = f_up[i].first;
            if(f_up[i].second != -1) {
                int _r = f_up[i].second;
                if((r != -1 && r != _r) || (l != -1 && l != _l)) goto kill;

                r = _r;
                l = _l;
                swap(a[i][_l], a[i][_r]);
                bool good = 1;
                for (int j = 0; j < m - 1; j++) {
                    good &= a[i][j] <= a[i][j + 1];
                }
                if(!good) goto kill;
            } else {
                bool try_left_wrong = 1;
                int _r = -1;
                for (int j = _l + 1; j < m; j++) {
                    if(a[i][j] == a[i][_l + 1]) _r = j;
                    else break;
                }
                bool good = 1;
                if((r != -1 && r != _r) || (l != -1 && l != _l)) {try_left_wrong = 0; goto here;}

                swap(a[i][_l], a[i][_r]);
                for (int j = 0; j < m - 1; j++) {
                    good &= a[i][j] <= a[i][j + 1];
                }
                if(!good) try_left_wrong = 0, swap(a[i][_l], a[i][_r]);
here:
                if(!try_left_wrong) {
                    _r = _l + 1;
                    for (int j = _r - 1; j >= 0; j--) {
                        if(a[i][j] == a[i][_r - 1]) _l = j;
                        else break;
                    }
                    if((r != -1 && r != _r) || (l != -1 && l != _l)) goto kill;

                    swap(a[i][_l], a[i][_r]);
                    good = 1;
                    for (int j = 0; j < m - 1; j++) {
                        good &= a[i][j] <= a[i][j + 1];
                    }
                    if(!good) goto kill;
                }
                r = _r;
                l = _l;
            }
        }
        dbg(l, r);
    }
    if(l == -1) {
        cout << "1 1\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if(ok_row[i]) {
            for (int j = l; j < r; j++) {
                if(a[i][j] != a[i][j + 1]) {
                    goto kill;
                }
            }
        }
    }

    cout << l + 1 << " " << r + 1 << '\n';
    return;

kill:
    cout << "-1\n";
    return;
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}