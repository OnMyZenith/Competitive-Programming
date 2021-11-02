#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int k;
    cin >> k;
    int n = sqrt(k);
    int rem = k - n * n;
    if (rem == 0)
        cout << n << " " << 1 << '\n';
    else if (rem <= n + 1)
        cout << rem << " " << n + 1 << '\n';
    else
        cout << n + 1 << " " << 2 * n + 2 - rem << '\n';
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