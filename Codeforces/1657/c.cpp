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
    int n; string s; cin >> n >> s;
    int cnt = 0, cntf = 0;
    bool fail = 1;
    if(n == 1) {
        cout << "0 1\n";
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1] || s[i] == '(') {
            if(i == n - 3) cntf = 1;
            i++, cnt++;
        }
        else {
            fail = 1, cntf = 0;
            for (int j = i + 2; j < n; j++) {
                if(s[j] == ')') {
                    if(j == n - 2) {
                        cntf = 1;
                    } else {
                        fail = 0;
                    }
                    cnt++;
                    i = j;
                    break;
                }
            }
            if(fail && !cntf) {
                cntf = n - i;
                break;
            }
        }
    }
    cout << cnt << " " << cntf << '\n';
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