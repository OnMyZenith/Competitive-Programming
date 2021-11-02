#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int y = x % 4;

        if (y == 0) cout << "North\n";
        else if (y == 1)
            cout << "East\n";
        else if (y == 2)
            cout << "South\n";
        else if (y == 3)
            cout << "West\n";
    }

    return 0;
}