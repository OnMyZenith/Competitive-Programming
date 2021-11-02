#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

void solve() {
    ll n, L, R;
    cin >> n >> L >> R;
    vector<ll> a;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        ll s;
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    for (auto i : a) {
        ll l = 0, h = a.size() - 1;
        while (l < h) {
            ll mid = (l + h) / 2;
            string p = to_string(i) + to_string(a[mid]);
            if (stoi(p) >= L) h = mid;
            else
                l = mid + 1;
        }
        ll idx_lo = l;
        if (stoi(to_string(i) + to_string(a[idx_lo])) < L) idx_lo++;
        l = 0;
        h = a.size();
        while (l < h) {
            ll mid = (l + h) / 2;
            string p = to_string(i) + to_string(a[mid]);
            if (stoi(p) <= R) l = mid + 1;
            else
                h = mid;
        }
        ll idx_hi = h - 1;
        if (idx_hi >= idx_lo) cnt += idx_hi - idx_lo + 1;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}