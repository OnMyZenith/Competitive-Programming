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

    int n; cin >> n;
    vector<int> dur(n), deadline(n);
    for (int i = 0; i < n; i++) cin >> dur[i] >> deadline[i];
    sort(dur.begin(), dur.end());

    ll res = accumulate(deadline.begin(), deadline.end(), 0ll), curr_time = 0;
    for (int i = 0; i < n; i++) {
        curr_time += dur[i];
        res -= curr_time;
    }
    cout << res << '\n';

    return 0;
}