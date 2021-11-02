#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (abs(a - b) < 2 || c > 2 * abs(a - b) || max(a, b) > 2 * abs(a - b)) cout << -1 << '\n';
    else if (c > abs(a - b))
        cout << (c + abs(a - b)) % (2 * abs(a - b)) << '\n';
    else
        cout << (c + abs(a - b)) << '\n';
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