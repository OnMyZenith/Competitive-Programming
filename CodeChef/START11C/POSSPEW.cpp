#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k, res = 0;
        cin >> n >> k;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        while (k--) {
            ll nxt[n];
            for (ll i = 1; i < n - 1; i++) {
                if (a[i - 1] > 0 && a[i + 1] > 0)
                    nxt[i] = a[i] + 2;
                else if (a[i - 1] > 0 || a[i + 1] > 0)
                    nxt[i] = a[i] + 1;
                else
                    nxt[i] = a[i];
            }
            //for a[0]
            if (a[n - 1] > 0 && a[1] > 0) nxt[0] = a[0] + 2;
            else if (a[n - 1] > 0 || a[1] > 0)
                nxt[0] = a[0] + 1;
            else
                nxt[0] = a[0];

            //for a[n-1]
            if (a[n - 2] > 0 && a[0] > 0) nxt[n - 1] = a[n - 1] + 2;
            else if (a[n - 2] > 0 || a[0] > 0)
                nxt[n - 1] = a[n - 1] + 1;
            else
                nxt[n - 1] = a[n - 1];

            //for a=nxt
            for (ll i = 0; i < n; i++)
                a[i] = nxt[i];
            bool allPos = true;

            for (ll i = 0; i < n; i++)
                if (a[i] <= 0) {
                    allPos = false;
                    break;
                }
            if (allPos) break;
        }
        res = 0;
        for (ll i = 0; i < n; i++)
            res += a[i];
        if (k > 0) res = res + 2 * n * k;
        cout << res << "\n";
    }

    return 0;
}