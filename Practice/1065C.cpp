/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int N = 2e5 + 7;
int h[N];
int a[N];

int main() {
    vamos;

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    for (int i = a[0] + 1; i <= a[n - 1]; i++) {
        h[i] = n - (lower_bound(a, a + n, i) - a);
    }

    int ans = 0, curr = 0;
    for (int i = a[n - 1]; i > a[0]; i--) {
        if (curr + h[i] <= k) curr += h[i];
        else {
            ans++;
            curr = h[i];
        }
    }

    cout << ans + (curr > 0) << '\n';

    return 0;
}