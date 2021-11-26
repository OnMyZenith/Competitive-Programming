#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

ll minArr(ll a[], ll n) {
    if (n == 2) return min(a[0], a[1]);
    return min(a[n - 1], minArr(a, n - 1));
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> allDiff;
    for (ll i = 0; i < n; i++) {
        vector<ll> tmp;
        for (ll j : a) {
            tmp.push_back(j - a[i]);
        }
        allDiff.push_back(tmp);
    }
    vector<ll> allPoss;
    for (vector<ll> one : allDiff) {
        for (ll k = 1; k <= 2000; k++) {
            ll ki;
            ll wildcard = 0;
            vector<ll> p;
            map<ll, ll> m;
            for (ll i : one) {
                m[i]++;
                if (i == 0) wildcard++;
                if (i % k == 0) {
                    p.push_back(k);
                    if (i / k > 1) {
                        ki = i / k;
                        p.push_back(ki);
                    }
                }
            }
            wildcard = m[0];
            if (count(p.begin(), p.end(), k) >= n / 2 - wildcard) allPoss.push_back(k);
            if (count(p.begin(), p.end(), ki) >= n / 2 - wildcard) allPoss.push_back(ki);
        }
    }
    sort(allPoss.begin(), allPoss.end());
    ll res = allPoss[allPoss.size() - 1];
    for (ll i : a) {
        if (count(a.begin(), a.end(), i) >= n / 2) {
            res = -1;
            break;
        }
    }

    cout << res << '\n';
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