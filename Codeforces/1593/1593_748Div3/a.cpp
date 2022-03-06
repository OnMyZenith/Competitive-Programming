#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

void solve() {
    ll a[3];
    for (ll i = 0; i < 3; i++)
        cin >> a[i];
    if (a[0] == a[1] && a[1] == a[2]) {
        cout << 1 << " " << 1 << " " << 1 << '\n';
        return;
    }
    if (a[0] != a[1] && a[1] != a[2] && a[2] != a[0]) {
        ll m = -1, idxm = -1;
        for (ll i = 0; i < 3; i++)
            if (m < a[i]) {
                m = a[i];
                idxm = i;
            }
        for (ll i = 0; i < 3; i++)
            if (i != idxm) cout << m - a[i] + 1 << " ";
            else
                cout << 0 << " ";
        cout << '\n';
        return;
    }
    ll b[3];
    for (ll i = 0; i < 3; i++)
        b[i] = a[i];
    sort(b, b + 3);
    if (b[2] > b[1]) {
        ll m = -1, idxm = -1;
        for (ll i = 0; i < 3; i++)
            if (m < a[i]) {
                m = a[i];
                idxm = i;
            }
        for (ll i = 0; i < 3; i++)
            if (i != idxm) cout << b[2] - a[i] + 1 << " ";
            else
                cout << 0 << " ";
        cout << '\n';
    } else {
        pair<ll, ll> mx;
        mx.first = -1;
        for (ll i = 0; i < 3; i++) {
            if (a[i] == b[2])
                if (mx.first == -1)
                    mx.first = i;
                else
                    mx.second = i;
        }
        for (ll i = 0; i < 3; i++)
            if (i != mx.first && i != mx.second) cout << b[2] - b[0] + 1 << " ";
            else
                cout << 1 << " ";
        cout << '\n';
    }
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