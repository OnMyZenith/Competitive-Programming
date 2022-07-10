/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


// const int MX = 5.2e6 + 10;
// bitset<MX> bit;


void solve() {
    string s; cin >> s;
    int p; cin >> p;
    vector<int> f(26), nf(26);
    int cost = 0;
    for (auto &c : s) {
        cost += c - 'a' + 1;
        f[c - 'a']++;
    }


    // int curr = 25;
    // while (cost < p && curr >= 0) {
    //     if (f[curr] == 0) {
    //         curr--; continue;
    //     }
    //     if (cost + curr + 1 <= p) {
    //         f[curr]--;
    //         nf[curr]++;
    //         cost += curr + 1;
    //     } else {
    //         curr--;
    //     }
    // }

    vector<int> pre(27);

    for (int i = 0; i < 26; i++) pre[i + 1] = pre[i] + f[i] * (i + 1);

    int curr = 25;
    while (cost > p) {
        if (f[curr] == 0) {
            curr--; continue;
        }
        if (cost - curr - 1 >= p) {
            cost -= curr + 1;
            f[curr]--;
        } else {
            // if (cost - pre[curr] <= p) curr--;
            
            // else 
            cost -= curr + 1, f[curr]--;
        }
    }
    for (auto &c : s) {
        if (f[c - 'a'] > 0) cout << c, f[c - 'a']--;        
    }
    cout << '\n';
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