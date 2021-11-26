#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int k;
    cin >> k;
    int n = 1, res = 1;
    for (int i = 0; i < k; n++)
        if (n % 3 != 0 && n % 10 != 3) {
            res = n;
            i++;
        }
    cout << res << '\n';
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