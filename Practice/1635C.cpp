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
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    if(is_sorted(a.begin(), a.end())){
        cout << "0\n";
        return;
    }
    if(a[n - 1] < a[n - 2]){
        cout << "-1\n";
        return;
    }
    int pos_idx = -1;
    for (int i = n - 1; i >= 0; i--) {
        if(a[i] >= 0) {
            pos_idx = i; break;
        }
    }
    if(pos_idx < 2 || !is_sorted(a.begin() + pos_idx - 1, a.end())){
        cout << "-1\n";
        return;
    }

    cout << n - 2 << '\n';
    for (int i = pos_idx - 2; i >= 0; i--) {
        cout << i + 1 << " " << i + 2 << " " << pos_idx + 1 << '\n';
        a[i] = a[i + 1] - a[pos_idx];
    }
    // dbg(a);
    // assert(is_sorted(a.begin(), a.end()));
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