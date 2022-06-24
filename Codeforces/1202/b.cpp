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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    string s; cin >> s;
    vector<vector<int>> res(10, vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            vector<int> mini(10, 1e9);
            for (int k1 = 0; k1 < 11; k1++) {
                for (int k2 = 0; k2 < 11; k2++) {
                    if (!k1 && !k2) continue;
                    ckmin(mini[(k1 * i + k2 * j) % 10], k1 + k2);
                }
            }
            if (i == 0 && j == 1) dbg(mini);

            int cnt = -(int)s.size() + 1;
            for (int k = 1; k < (int)s.size(); k++) {
                int jmp = int(s[k] - s[k - 1]);
                if (jmp < 0) jmp += 10;
                if (mini[jmp] == int(1e9)) {
                    cnt = -1;
                    break;
                }
                cnt += mini[jmp];
            }
            res[i][j] = cnt;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << res[i][j] << " \n"[j == 9];
        }
    }

    return 0;
}