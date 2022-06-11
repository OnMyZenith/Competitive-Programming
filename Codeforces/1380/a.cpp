/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; --a[i];
        pos[a[i]] = i;
    }
    set<int> left(a.begin(), a.begin() + 1), right(a.begin() + 2, a.end());
    for (int i = 1; i < n - 1; i++) {
        int x = a[i];
        if (*left.begin() < x && x > *right.begin()) {
            cout << "YES\n";
            cout << pos[*left.begin()] + 1 << " " << i + 1 << " " << pos[*right.begin()] + 1 << '\n';
            return;
        }
        left.insert(x);
        if(i < n - 1) right.erase(a[i + 1]);
    }
    cout << "NO\n";








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