#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n - 1);
        if (n == 2) cout << b[0] - ((b[0] > a[1]) ? a[1] : a[0]) << "\n";
        else if (b[0] - a[0] == b[1] - a[1] && 2 * a[1] != a[0] + a[2])
            cout << b[0] - a[0] << "\n";
        else if (b[0] - a[0] == b[1] - a[2])
            cout << b[0] - a[0] << "\n";
        else if (b[0] - a[1] == b[1] - a[2])
            cout << b[0] - a[1] << "\n";
    }
    return 0;
}
