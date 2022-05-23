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

    vector<bool> vis(n);
    set<pair<int, int>> adj;
    auto add = [&](int l, int r) {
        adj.insert({min(l, r), max(l, r)});
    };
    auto rem = [&](int l, int r) {
        adj.erase({min(l, r), max(l, r)});
    };
    for (auto &c : s) {
        if(c == '0') c = '1';
        else c = '0';
    }
    if(count(s.begin(), s.end(), '0') < 2) {
        cout << "NO\n";
        return;
    }
    bool fk = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '1') continue;
        int l = i, r = -1;
        for (int j = i + 1; j < n; j++) if (s[j] == '0') {
            r = j; break;
        }
        // vis[l] = vis[r] = 1;
        // leading edge
        // add(l, r);
        for (int j = l + 1; j < r - 1; j++) {
            add(j, j + 1);
        }
        // rem(l, r);
        int _l = l;
        add(l, l + 1);
        add(r, r - 1);
        l = r - 1;
        dbg(l, r);
        for (int j = r + 1; j <= r + 1 + n; j++) {
            int k1 = j % n;
            if(k1 == _l) break;
            dbg(adj, l, r);

            if(s[k1] == '0') {
                add(l, k1);
                fk = !fk;
                r = k1;
            } else {
                add(k1, l);
                add(k1, r);
                rem(l, r);
                r = k1;
            }

            // if(s[k1] == s[k2] && s[k1] == '1') {
            //     rem(l, r);
            //     add(k1, k2);
            //     add(k1, r);
            //     add(k2, l);
            //     r = k2;
            //     dbg(adj);
            // } else if (s[k1] == s[k2] && s[k1] == '0') {
            //     add(k1, r);
            //     add(k2, r);
            // } else if (s[k1] == '0' && s[k2] == '1') {
            //     add(k1, k2);
            //     add(k2, r);
            //     add(k2, l);
            //     rem(l, r);
            //     r = k2;
            // } else if (s[k1] == '1' && s[k2] == '0') {
            //     add(k1, k2);
            //     add(k1, r);
            //     add(k1, l);
            //     rem(l, r);
            //     r = k1;
            // } else assert(false);
        }
        break;
    }
    if(fk) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    dbg(adj);
    // if((int)adj.size() != n - 1) {
    //     dbg(adj);
    //     dbg(s);
    //     cout.flush();
    //     exit(0);
    // }
    assert((int)adj.size() == n - 1);
    for (auto &[x, y] : adj) {
        cout << x + 1 << " "  << y + 1 << '\n';
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