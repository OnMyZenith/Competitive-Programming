

/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
#ifndef asr_debug
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
#endif
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

    vector<string> res;
    for (int i = 0; i < a; i++) res.push_back("A");
    for (int i = 0; i < b; i++) res.push_back("B");
    for (int i = 0; i < c; i++) res.push_back("AB");
    for (int i = 0; i < d; i++) res.push_back("BA");

    sort(res.begin(), res.end());

    do {
        string poss;
        for (auto str : res) {
            poss += str;
        }
        if(poss == s) {
            cout << "YES\n";
            return;
        }
    } while(next_permutation(res.begin(), res.end()));

    cout << "NO\n";

    // if(count(s.begin(), s.end(), 'A') != a + c + d || count(s.begin(), s.end(), 'B') != b + c + d) {
    //     cout << "NO\n";
    //     return;
    // }

    // int n = (int)s.size();

    // vector<bool> vis(n);

    // for (int i = 0, cnt = 1; i < n - 1; i++) {
    //     if(s[i] != s[i + 1]) {
    //         cnt++;
    //     }
    //     if(s[i] == s[i + 1]) {
    //         if(cnt >= 2) {
    //             for (int j = i - cnt + 1; j <= i; j++) {
    //                 vis[j] = 1;
    //             }
    //         }
    //         cnt = 1;
    //     }
    //     if(i == n - 2 && s[i] != s[i + 1]) {
    //         if(cnt >= 2) {
    //             for (int j = i - cnt + 2; j < n; j++) {
    //                 vis[j] = 1;
    //             }
    //         }
    //         cnt = 1;
    //     }
    // }
    // vector<int> cnta, cntb;
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

    // // dbg(s);
    // // dbg(vis);
    // // dbg(cnta);
    // // dbg(cntb);

    // vector<int> ab, ba;
    // int pool = 0;
    // for (auto cnt : cnta) {
    //     if(cnt & 1) {
    //         pool += cnt / 2;
    //     } else ab.push_back(cnt);
    // }
    // for (auto cnt : cntb) {
    //     if(cnt & 1) {
    //         pool += cnt / 2;
    //     } else ba.push_back(cnt);
    // }
    // // dbg(pool, c, d);
    // // dbg(ab);
    // // dbg(ba);

    // sort(ba.begin(), ba.end());
    // sort(ab.begin(), ab.end());

    // for (auto &cnt : ab) {
    //     if(c >= cnt / 2) c -= cnt / 2;
    //     else {
    //         cnt -= c * 2;
    //         c = 0;
    //         break;
    //     }
    // }
    
    // for (auto &cnt : ba) {
    //     if(d >= cnt / 2) d -= cnt / 2;
    //     else {
    //         cnt -= d * 2;
    //         d = 0;
    //         break;
    //     }
    // }

    // if(c == 0) {
    //     if(d) {
    //         for (auto &cnt : ab) {
    //             if(cnt < 4) continue;
                
    //             if(d >= (cnt - 2) / 2) d -= (cnt - 2) / 2;
    //             else {
    //                 cnt -= (d + 1) * 2;
    //                 d = 0;
    //                 break;
    //             }
    //         }
    //     }
    // } else if (d == 0) {
    //     if(c) {
    //         for (auto &cnt : ba) {
    //             if(cnt < 4) continue;
                
    //             if(c >= (cnt - 2) / 2) c -= (cnt - 2) / 2;
    //             else {
    //                 cnt -= (c + 1) * 2;
    //                 c = 0;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // if(c + d <= pool) {
    //     cout << "YES\n";
    // } else cout << "NO\n";
    


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