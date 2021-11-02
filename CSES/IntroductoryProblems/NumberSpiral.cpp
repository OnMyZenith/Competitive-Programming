#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long y, x;
        cin >> y >> x;
        if (y > x) {
            if (y % 2) cout << (y - 1) * (y - 1) + x << "\n";
            else
                cout << (y - 1) * (y - 1) + 2 * y - x << "\n";
        } else {
            if (x % 2) cout << (x - 1) * (x - 1) + 2 * x - y << "\n";
            else
                cout << (x - 1) * (x - 1) + y << "\n";
        }
    }

    return 0;
}