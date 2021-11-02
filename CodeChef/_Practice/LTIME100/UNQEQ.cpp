#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 4) cout << "NO\n";
    else {
        cout << "YES\n";
        int i;
        for (i = 1; i <= n / 2 - 1; i += 2)
            cout << i << " ";
        for (i = n / 2 + 2; i <= n; i += 2)
            cout << i << " ";
        cout << '\n';
        for (i = 2; i <= n / 2; i += 2)
            cout << i << " ";
        for (i = n / 2 + 1; i <= n; i += 2)
            cout << i << " ";
        cout << '\n';
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