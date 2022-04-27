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



int main() {
    vamos;

    int n, k; cin >> n >> k;
    vector<ll> a(n), s(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll val = 0, cnt = 0;
    for (int i = n - 1, j = n - 1 + k; i >= 0; i--, j--, val -= cnt) {
        if(j < n) cnt -= s[j];
        if(a[i] > val) {
            s[i] = (a[i] - val + min(k, i + 1) - 1) / min(k, i + 1);
            val += min(k, i + 1) * s[i];
            cnt += s[i];
        }
    }
    dbg(s);
    cout << accumulate(s.begin(), s.end(), 0ll) << '\n';


    return 0;
}