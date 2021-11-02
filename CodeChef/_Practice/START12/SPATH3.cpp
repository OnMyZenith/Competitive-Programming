#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        if (n > m) {
            n = m + n;
            m = n - m;
            n = n - m;
        }
        if (n == 1) cout << (m - 1) * x << '\n';
        else if (2 * x <= y)
            cout << (n - 1 + m - 1) * x << '\n';
        else if (x >= y)
            if ((m - n) % 2) cout << (m - 2) * y + x << '\n';
            else
                cout << (m - 1) * y << '\n';
        else
            cout << (n - 1) * y + (m - n) * x << '\n';
    }
    return 0;
}