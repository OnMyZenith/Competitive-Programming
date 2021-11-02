#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool safe = true;
    for (int i = 0; i < n; i++)
        if (a[i] == '1' && b[i] == '1') {
            safe = false;
            break;
        }
    if (safe) cout << "YES\n";
    else
        cout << "NO\n";
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