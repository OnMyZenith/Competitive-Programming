#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (n == k) {
        for (ll i = 1; i <= n; i++)
            cout << i << " ";
        cout << '\n';
    } else if (n - k < 2)
        cout << -1 << '\n';
    else {
        for (ll i = 1; i <= n - 1; i++)
            if (i <= k)
                cout << i << " ";
            else
                cout << i + 1 << " ";
        cout << k + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}