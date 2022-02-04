/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())

using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#define chk(...) 007
#endif

const long double PI = 3.14159265358979323846L;
const long long LINF = 2e18L + 007;
const int IINF = 2e9 + 007;
const int MOD = 1e9 + 007; // 998244353;
const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB
template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


vector<int> _mp[2*__];
vector<int> *mp = _mp + __;

int main() {

    vamos;

    int n; cin >> n;
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]-i].push_back(i);
    }
    ll best = 0;
    for (int i = -__; i < __; i++) {
        vector<int> v = mp[i];
        if(v.empty()) continue;
        dbg(v);
        ll curr = 0;
        for (auto &a : v) {
            curr+=b[a];
        }
        ckmax(best,curr);
    }
    cout << best << '\n';

    return 0;
}