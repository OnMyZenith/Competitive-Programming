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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    auto sa = a, sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        if(sa[i] != a[i]) {
            for (int j = i + 1; j < n; j++) {
                if(a[j] == sa[i]) {
                    res.emplace_back(i, j);
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    break;
                }
            }
        }
    }
    swap(sa, sb);
    swap(a, b);
    for (int i = 0; i < n; i++) {
        if(sa[i] != a[i]) {
            for (int j = i + 1; j < n; j++) {
                if(a[j] == sa[i]) {
                    res.emplace_back(i, j);
                    swap(b[i], b[j]);
                    swap(a[i], a[j]);
                    break;
                }
            }
        }
    }
    bool ok = 1;
    for (int i = 0; i < n - 1; i++) {
        ok &= a[i] <= a[i + 1];
        ok &= b[i] <= b[i + 1];
    }
    if(!ok) {
        cout << "-1\n";
        return;
    }

    cout << (int)res.size() << '\n';
    for (auto &[x, y] : res) {
        cout << x + 1 << " " << y + 1 << '\n';
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