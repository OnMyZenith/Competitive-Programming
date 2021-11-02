#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll p, a, b, c, x, y;
    cin >> p >> a >> b >> c >> x >> y;

    cout << p / min((a * x + b), (a * y + c)) << '\n';
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