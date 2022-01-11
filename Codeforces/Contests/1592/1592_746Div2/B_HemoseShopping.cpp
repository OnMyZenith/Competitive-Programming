#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    sort(b, b + n);
    if (x <= n / 2) cout << "YES\n";
    else {
        bool sorted = true;
        for (int i = n - x; i < x; i++)
            if (a[i] != b[i]) {
                sorted = false;
                break;
            }
        if (sorted) cout << "YES\n";
        else
            cout << "NO\n";
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