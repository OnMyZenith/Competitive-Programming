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
        if ((n * (n + 1) / 2) % 2) cout << n - 1 << "\n";
        else
            cout << n << "\n";
    }

    return 0;
}