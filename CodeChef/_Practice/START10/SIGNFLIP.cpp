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
        cin >> n >> k;
        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        vector<ll> neg;
        for (int i = 0; i < k; i++)
            if (a[i] < 0) neg.push_back(-1 * a[i]);
            else
                break;

        ll res = 0;
        for (int i = n - 1; i >= 0; i--)
            if (a[i] > 0) res += a[i];
            else
                break;

        for (size_t i = 0; i < neg.size(); i++)
            res += neg[i];
        cout << res << "\n";
    }

    return 0;
}