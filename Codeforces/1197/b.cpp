/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << (is_sorted(a.begin(), max_element(a.begin(), a.end())) && is_sorted(max_element(a.begin(), a.end()), a.end(), greater<int>()) ? "YES" : "NO") << '\n';

    return 0;
}