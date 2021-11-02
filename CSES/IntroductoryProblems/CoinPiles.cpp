#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    if (2 * a < b) cout << "NO\n";
    else {
        int diff = b - a;
        b -= 2 * diff;
        a -= diff;
        if (a == b && a % 3 == 0) cout << "YES\n";
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