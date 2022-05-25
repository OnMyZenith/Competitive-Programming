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
    int a, b, c, d; cin >> a >> b >> c >> d;
    string s; cin >> s;

    if(count(s.begin(), s.end(), 'A') != a + c + d || count(s.begin(), s.end(), 'B') != b + c + d) {
        cout << "NO\n";
        return;
    }

    int n = (int)s.size();

    // vector<bool> vis(n);
    vector<int> cnta, cntb;

    for (int i = 0, cnt = 1; i < n - 1; i++) {
        if(s[i] != s[i + 1]) {
            cnt++;
        }
        if(s[i] == s[i + 1]) {
            if(cnt >= 2) {
                // for (int j = i - cnt + 1; j <= i; j++) {
                //     vis[j] = 1;
                // }
                if (s[i - cnt + 1] == 'A') cnta.push_back(i + 1 - (i - cnt + 1));
                else cntb.push_back(i + 1 - (i - cnt + 1));
            }
            cnt = 1;
        }
        if(i == n - 2 && s[i] != s[i + 1]) {
            if(cnt >= 2) {
                // for (int j = i - cnt + 2; j < n; j++) {
                //     vis[j] = 1;
                // }
                if (s[i - cnt + 2] == 'A') cnta.push_back(n - (i - cnt + 2));
                else cntb.push_back(n - (i - cnt + 2));
            }
            cnt = 1;
        }
    }
    // for (int l = 0; l < n;) {
    //     if(vis[l]) {
    //         int r = l;
    //         for (; r < n && vis[r]; r++) {
    //             //
    //         }
    //         if(s[l] == 'A') cnta.push_back(r - l);
    //         else cntb.push_back(r - l);
    //         l = r;
    //     } else l++;
    // }

    dbg(s);
    // dbg(vis);
    dbg(cnta);
    dbg(cntb);

    vector<int> ab, ba;
    int pool = 0;
    for (auto cnt : cnta) {
        if(cnt & 1) {
            pool += cnt / 2;
        } else ab.push_back(cnt);
    }
    for (auto cnt : cntb) {
        if(cnt & 1) {
            pool += cnt / 2;
        } else ba.push_back(cnt);
    }
    dbg(pool, c, d);
    dbg(ab);
    dbg(ba);

    sort(ba.begin(), ba.end());
    sort(ab.begin(), ab.end());

    for (auto &cnt : ab) {
        if(c >= cnt / 2) c -= cnt / 2, cnt = 0;
        else {
            cnt -= c * 2;
            c = 0;
            break;
        }
    }
    
    for (auto &cnt : ba) {
        if(d >= cnt / 2) d -= cnt / 2, cnt = 0;
        else {
            cnt -= d * 2;
            d = 0;
            break;
        }
    }

    if(c == 0) {
        if(d) {
            for (auto &cnt : ab) {
                if(cnt < 4) continue;
                
                if(d >= (cnt - 2) / 2) d -= (cnt - 2) / 2, cnt = 0;
                else {
                    cnt -= (d + 1) * 2;
                    d = 0;
                    break;
                }
            }
        }
    } else if (d == 0) {
        if(c) {
            for (auto &cnt : ba) {
                if(cnt < 4) continue;
                
                if(c >= (cnt - 2) / 2) c -= (cnt - 2) / 2, cnt = 0;
                else {
                    cnt -= (c + 1) * 2;
                    c = 0;
                    break;
                }
            }
        }
    }

    if(c + d <= pool) {
        cout << "YES\n";
    } else cout << "NO\n";
    


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