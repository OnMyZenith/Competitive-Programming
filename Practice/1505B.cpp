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

int solve(int n){
    string s = to_string(n);
    if((int)s.length() == 1) return n;
    int res = 0;
    for (auto &c : s) {
        res += c - '0';
    }
    return solve(res);
}

int main() {
    vamos;

    int n; cin >> n;
    cout << solve(n) << '\n';
    return 0;
}