#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll a, b;
    cin >> a >> b;

    if (a % 2 == 0)
        if (b % 2 == 0)
            while (a % 2 == 0)
                a = a / 2;
        else {
            cout << "NO\n";
            return;
        }

    for (ll i = 3; i * i <= a; i += 2)
        if (a % i == 0)
            if (b % i == 0)
                while (a % i == 0)
                    a = a / i;
            else {
                cout << "NO\n";
                return;
            }

    if (b % a == 0) {
        cout << "YES\n";
        return;
    } else
        cout << "NO\n";
    return;
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