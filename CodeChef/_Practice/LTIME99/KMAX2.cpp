#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        ll res = 0;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int m = a[0];
        for (int i = 0; i < n; i++)
            if (m < a[i]) m = a[i];

        for (int i = k - 1; i < n; i++)
            if (a[i] == m) res += n - i;

        cout << res << "\n";
    }

    return 0;
}