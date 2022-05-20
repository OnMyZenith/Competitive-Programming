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
#ifdef asr_time
    auto begin = chrono::high_resolution_clock::now();
#endif



    int n; cin >> n;

    ll sum = 0, ans = 0;
    map<ll, int> f;
    f[0] = 1;
    for (int i = 0, y; i < n; i++) {
        cin >> y; sum += y;
        for (ll x = ((sum - ((--f.end())->second)) / n) * n - n; ; x += n) {
            auto it = f.lower_bound(sum - x);
            if(it != f.end()) ans += ((it->first == sum - x) ? it->second : 0);
            if(sum - f.begin()->first + n < x) break;
        }
        f[sum]++;
    }
    cout << ans << '\n';

#ifdef asr_time
    auto end = chrono::high_resolution_clock::now();
    cerr << setprecision(2) << fixed;
    cerr << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif
    return 0;
}