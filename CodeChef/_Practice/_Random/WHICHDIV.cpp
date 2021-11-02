#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        if (r >= 2000) cout << 1 << "\n";
        else if (r >= 1600)
            cout << 2 << "\n";
        else
            cout << 3 << "\n";
    }

    return 0;
}