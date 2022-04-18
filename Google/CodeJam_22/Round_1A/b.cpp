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

template <typename T_vector>
void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);

constexpr int pctll(ll x) { return __builtin_popcountll(x); }                                // # of bits set
constexpr int log_2(ll x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clzll(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr ll next_pow_2(ll x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }                  // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(ll x) { return log_2(x) + int(__builtin_popcountll(x) != 1); }      // Ceil of log_2(x);

void solve() {
    int n;
    cin >> n;
    vector<int> p2, a, b(n);
    for (int i = 0, cnt = 3; i < n; i++) {
        if (i < 30 && (1 << i) < 1e9) p2.push_back(1 << i);
        else {
            a.push_back(cnt++);
            while (!(cnt & 1))
                cnt++;
        }
    }
    for (int i = 0; i < (int)a.size(); i++) cout << a[i] << " ";
    for (int i = 0; i < (int)p2.size(); i++) cout << p2[i] << " \n"[i == (int)p2.size() - 1];

    cout.flush();
    for (int i = 0; i < n; i++)
        cin >> b[i];
    a.reserve(2 * n);
    for (int i = 0; i < n; i++)
        a.push_back(b[i]);
    sort(a.begin(), a.end());

    ll p2s = accumulate(p2.begin(), p2.end(), 0LL);
    ll t = (accumulate(a.begin(), a.end(), 0LL) + p2s) / 2;
    vector<int> res;
    set<int> _p2(p2.begin(), p2.end());
    set<int> as(a.begin(), a.end());
    while (t > p2s) {
        auto it = as.begin();
        // assert(it != as.begin());
        // it--;
        t -= *it;
        res.push_back(*it);
        as.erase(it);
    }
    dbg(t);
    assert(t >= 0);
    for (int i = 0; i < 30; i++) {
        if((t >> i) & 1) {
            res.push_back(1 << i);
        }
    }

    ov(res);
    cout.flush();




    // cout << "Case #" << _TC << ": ";
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve();
    }

    return 0;
}