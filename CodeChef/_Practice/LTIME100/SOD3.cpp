#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll l, r;
    cin >> l >> r;
    if ((r - l + 1) % 3) {
        if ((r - l + 1) % 3 == 1) {
            if (l % 3 == 1) {
                cout << (r - l + 1) / 3 << '\n';
            } else if (l % 3 == 2) {
                cout << (r - l + 1) / 3 << '\n';
            } else
                cout << (r - l + 1) / 3 + 1 << '\n';
        } else {
            if (l % 3 == 1) {
                cout << (r - l + 1) / 3 << '\n';
            } else if (l % 3 == 2) {
                cout << (r - l + 1) / 3 + 1 << '\n';
            } else
                cout << (r - l + 1) / 3 + 1 << '\n';
        }

    } else
        cout << (r - l + 1) / 3 << '\n';
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