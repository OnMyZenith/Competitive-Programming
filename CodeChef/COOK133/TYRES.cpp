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
        if (n % 4 == 0) cout << "NO\n";
        else if (n % 4 > 1)
            cout << "YES\n";
    }

    return 0;
}