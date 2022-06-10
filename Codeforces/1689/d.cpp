/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

#ifdef asr_debug
#include "dbg.hpp"
const int N = 10;
#else
const int N = 1007;
#define dbg(...) 007
#endif

bitset<N> g[N];
// bitset<1000007> g;
template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char c;
        for (int j = 0; j < m; j++) {
            cin >> c;
            // g[i * m + j] = c == 'B';
            g[i][j] = c == 'B';
        }
        dbg(g[i]);
    }

    int tl = -1;
    for (int power = 1; power <= n + m - 1; power++) {
        int r = min(power - 1, n - 1);
        for (int c = max(power - n, 0); c < m && r >= 0 && r + c + 1 <= power; c++, r--) {
            if(g[r][c]) {
                tl = power;
                break;
            }
        }
        if(tl != -1) break;
    }

    int tr = -1;
    for (int power = 1; power <= n + m - 1; power++) {
        int c = max(m - power, 0);
        for (int r = max(power - m, 0); r < n && c < m && r + m - c <= power; r++, c++) {
            // dbg(r + 1, c + 1, (int)g[r][c]);
            if(g[r][c]) {
                tr = power;
                break;
            }
        }
        if(tr != -1) break;
    }

    int br = -1;
    for (int power = 1; power <= n + m - 1; power++) {
        int c = max(m - power, 0);
        for (int r = n - 1 - max(power - m, 0); r >= 0 && c < m && n + m - 1 - r - c <= power; r--, c++) {
            if(g[r][c]) {
                br = power;
                break;
            }
        }
        if(br != -1) break;
    }

    int bl = -1;
    for (int power = 1; power <= n + m - 1; power++) {
        int r = max(n - power, 0);
        for (int c = max(power - n, 0); c < m && r < n && n - r + c <= power; c++, r++) {
            dbg(r + 1, c + 1, (int)g[r][c], power);
            if(g[r][c]) {
                bl = power;
                break;
            }
        }
        if(bl != -1) break;
    }
    dbg(tl, tr, bl, br);

    int best = 1e9, r = -1, c = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if(i + j + 1 < tl || n - i + j < bl || i + m - j < tr || n + m - i - j - 1 < br) continue;
            if(ckmin(best, max({max((i + j + 1 - tl), 0), max((i + m - j - tr), 0), max((n - i + j - bl), 0), max((n + m - i - j - 1 - br), 0)}))) {
                r = i, c = j;
            }
        }
    }

    cout << r + 1 << " " << c + 1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}