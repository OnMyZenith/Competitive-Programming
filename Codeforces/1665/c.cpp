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
    int n; cin >> n;
    vector<int> a(n - 1);
    for (auto &u : a) {
        cin >> u; u--;
    }
    vector<int> f(n);
    for (int i = 0; i < n - 1; i++) f[a[i]]++;
    // f[n - 1] = 1;
    vector<int> fin;
    for (int i = 0; i < n; i++) {
        if(f[i]) fin.push_back(f[i]);
    }
    fin.push_back(1);
    sort(fin.rbegin(), fin.rend());
    vector<int> tim((int)fin.size());
    int t = 0;
    for (int i = 0; i < (int)fin.size(); i++) {
        tim[i] = ++t;
    }
    // int ans = t;
    for (int i = 0; i < (int)fin.size(); i++) {
        t += max(fin[i] - (t - tim[i]) - 1, 0);
    }
    dbg(fin);
    cout << t << '\n';
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