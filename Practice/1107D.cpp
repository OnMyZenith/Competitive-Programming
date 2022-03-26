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

#ifdef asr_debug
bitset<10> a[10];
#else
bitset<5207> a[5207];
#endif

int main() {
    vamos;

    int n; cin >> n;

    auto resolve = [&](string &s, int r) -> void {
        int c = 0;
        for (auto &ch : s) {
            int mask;
            if(ch <= 57) {
                mask = (ch - 48);
            } else {
                mask = 10 + (ch - 65);
            }
            for (int i = 3, j = 0; i >= 0; i--, j++) {
                if((mask >> i) & 1) {
                    a[r][j + c] = 1;
                }
            }
            c += 4;
        }
    };

    for (int r = 0; r < n; r++) {
        string s; cin >> s;
        resolve(s, r);
    }

    int g_c = 0, g_r = 0;
    for (int i = 0; i < n; i++) {
        bool p = a[i][0];
        int cnt = 0, g_one_c = 0;
        for (int j = 0; j < n; j++) {
            if(p == a[i][j]) cnt++;
            else g_one_c = gcd(g_one_c, cnt), dbg(cnt), cnt = 1, p = !p;
            if(j == n - 1) g_one_c = gcd(g_one_c, cnt);
        }
        g_c = gcd(g_c, g_one_c);
    }
    for (int i = 0; i < n; i++) {
        bool p = a[0][i];
        int cnt = 0, g_one_r = 0;
        for (int j = 0; j < n; j++) {
            if(p == a[j][i]) cnt++;
            else g_one_r = gcd(g_one_r, cnt), dbg(cnt), cnt = 1, p = !p;
            if(j == n - 1) g_one_r = gcd(g_one_r, cnt);
        }
        g_r = gcd(g_r, g_one_r);
    }
    int res = gcd(g_r, g_c);
    if(!res) res = n;
    cout << res << '\n';

    return 0;
}