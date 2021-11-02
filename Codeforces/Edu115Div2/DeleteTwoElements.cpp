#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

void solve() {
    int n;
    cin >> n;
    ll a[n];
    long double sum = 0, avg;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    avg = sum / n;
    long double trgt = avg * 2;
    ll target = trgt;
    if (abs(trgt - target) > eps) {
        cout << 0 << '\n';
        return;
    }
    map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    ll res = 0;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        if ((*it).second >= 1 && (2 * (*it).first) != target) {
            res += ((*it).second) * (freq[target - (*it).first]);
            freq[target - (*it).first] = 0;
            (*it).second = 0;
        } else if ((*it).second >= 1 && (2 * (*it).first) == target) {
            res += ((*it).second * ((*it).second - 1)) / 2;
            (*it).second = 0;
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