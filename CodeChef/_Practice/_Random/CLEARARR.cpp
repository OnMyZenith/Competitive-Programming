#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> v;
        ll k_remaining = k;

        ll in;
        while (n--) {
            cin >> in;
            v.push_back(in);
        }

        sort(v.begin(), v.end(), greater<int>());

        auto it = v.begin();
        for (it = v.begin(); (it != v.end() - 1) && (*it + *(it + 1) > x); it += 2)
            ;

        ll k_used = distance(v.begin(), it) / 2;
        if (k < k_used) k_used = k;

        ll cost = x * k_used;

        it = v.begin() + 2 * k_used;

        v.erase(v.begin(), it);

        for (auto i : v)
            cost += i;

        cout << cost << "\n";
    }

    return 0;
}