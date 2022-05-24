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

#ifndef asr_debug
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
#endif

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


int main() {
    vamos;

    ll n, x; cin >> n >> x;
    ll tar = 1;
    for (int i = 0; i < n - 1; i++) tar *= 10;
    int best = 64;
    ll res = 0;
    y_combinator([&](auto self, ll y, int dep) -> void {
        if(dep >= best) return;

        if(y >= tar) {
            if(ckmin(best, dep)) {
                res = y;
            }
            return;
        }
        ll temp = y;
        int need = 0;
        while(temp < tar) {
            temp *= 9;
            need++;
        }
        // dbg(y, need, best);
        if(need + dep >= best) return;


        temp = y;
        bitset<10> has;
        while(temp) {
            has[temp % 10] = 1;
            temp /= 10;
        }

        for (int i = 9; i > 1; i--) {
            if(has[i]) self(i * y, dep + 1);
        }
    })(x, 0);

    dbg(res);

    cout << (best != 64 ? best : -1) << '\n';

    return 0;
}