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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (n == 1) {
            cout << "YES\n";
            cout << "0 0\n";
        } else if (n == 2) {
            cout << "YES\n";
            cout << "0 0\n";
            cout << a[0] + a[1] << " 0\n";
        } else if (n == 3) {
            cout << "YES\n";
            cout << "0 0\n";
            cout << a[0] + a[1] << " 0\n";
            cout << a[0] << " " << a[2] << "\n";
        } else if (n == 4) {
            cout << "YES\n";
            cout << a[0] << " 0\n";
            cout << "0 " << a[1] << "\n";
            cout << -1 * a[2] << " 0\n";
            cout << "0 " << -1 * a[3] << "\n";
        } else
            cout << "NO\n";
    }
    return 0;
}