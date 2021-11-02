#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        if (2 * n - s >= n) cout << s << "\n";
        else
            cout << 2 * n - s << "\n";
    }

    return 0;
}