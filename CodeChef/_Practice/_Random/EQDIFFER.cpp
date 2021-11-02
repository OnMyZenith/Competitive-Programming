#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, a;
        cin >> n;
        map<ll, ll> m;

        for (ll i = 0; i < n; i++) {
            cin >> a;
            m[a]++;
        }

        if (n <= 2) cout << 0 << "\n";
        else {
            ll max = 0;
            for (auto i : m)
                if (i.second > max) max = i.second;

            if (max == 1) cout << (n - 2) << "\n";
            else
                cout << (n - max) << "\n";
        }
    }
    return 0;
}