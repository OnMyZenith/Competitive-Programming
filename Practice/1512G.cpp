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

int res[(int)1e7 + 7];

int main() {
    vamos;
    int n = 1e7;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    // vector<vector<int>> series(n + 1);
    map<int, int> mp;
    vector<int> series;
    series.reserve(1e7 + 7);
    for (ll i = 2; i <= 1e7; i++) {
        if(is_prime[i]) {
            // series[i].reserve(1e7 / i + 1);
            int sm = i + 1;
            for (ll j = i; j < 1e7 && sm <= 1e7; j *= i, sm += j) {
                series.push_back(sm);
                mp[sm] = j;
            }
        }
    }
    sort(series.begin(), series.end());

    int m = (int)series.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n && (ll) series[i] * series[j] <= 1e7; j++) {
            res[series[i] * series[j]] = mp[series[i]] * mp[series[j]];
        }
    }


    int TT = 1;
    cin >> TT;
    while(TT--) {
        int c; cin >> c;
        cout << (res[c] ? res[c] : -1) << '\n';
    }

    return 0;
}