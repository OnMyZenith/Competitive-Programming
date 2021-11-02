#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

void solve() {
    string n;
    cin >> n;
    ll cost[4]; //00 25 50 75
    cost[0] = 1e18;
    cost[1] = 1e18;
    cost[2] = 1e18;
    cost[3] = 1e18;
    for (ll j = n.length() - 1; j >= 0; j--) {
        if (n[j] == '0')
            for (ll k = j - 1; k >= 0; k--) {
                if (n[k] == '0') {
                    cost[0] = n.length() - k - 2;
                    goto out1;
                }
            }
    }
out1:
    for (ll j = n.length() - 1; j >= 0; j--) {
        if (n[j] == '5')
            for (ll k = j - 1; k >= 0; k--) {
                if (n[k] == '2') {
                    cost[1] = n.length() - k - 2;
                    goto out2;
                }
            }
    }
out2:
    for (ll j = n.length() - 1; j >= 0; j--) {
        if (n[j] == '0')
            for (ll k = j - 1; k >= 0; k--) {
                if (n[k] == '5') {
                    cost[2] = n.length() - k - 2;
                    goto out3;
                }
            }
    }
out3:
    for (ll j = n.length() - 1; j >= 0; j--) {
        if (n[j] == '5')
            for (ll k = j - 1; k >= 0; k--) {
                if (n[k] == '7') {
                    cost[3] = n.length() - k - 2;
                    goto out4;
                }
            }
    }
out4:
    ll mn = 1e18;
    for (ll i = 0; i < 4; i++)
        if (cost[i] < mn) mn = cost[i];
    cout << mn << '\n';
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