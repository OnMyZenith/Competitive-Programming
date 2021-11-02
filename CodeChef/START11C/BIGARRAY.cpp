#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, s, res;
        cin >> n >> s;
        res = (n * (n + 1) / 2) - s;
        if (res > 0 && res <= n) cout << res << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}