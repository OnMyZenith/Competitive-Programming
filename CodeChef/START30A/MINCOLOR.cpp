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




void solve() {
    int n, m; cin >> n >> m;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if((abs(x1 - x2) + abs(y1 - y2)) & 1) {
        if((x1 + y1) & 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if((i + j) & 1) {
                        cout << '1';
                    } else {
                        cout << '2';
                    }
                    cout << " \n"[j == m - 1];
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if((i + j) & 1) {
                        cout << '2';
                    } else {
                        cout << '1';
                    }
                    cout << " \n"[j == m - 1];
                }
            }
        }
    } else {
        if((x1 + y1) & 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(i + 1 == x1 && j + 1 == y1) {
                        cout << '1';
                    } else if((i + j) & 1) {
                        cout << '2';
                    } else {
                        cout << '3';
                    }
                    cout << " \n"[j == m - 1];
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(i + 1 == x2 && j + 1 == y2) {
                        cout << '2';
                    } else if((i + j) & 1) {
                        cout << '3';
                    } else {
                        cout << '1';
                    }
                    cout << " \n"[j == m - 1];
                }
            }
        }
    }
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