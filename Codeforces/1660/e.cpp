/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
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


#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB


const int N = 2007;

// int m[N][N];
int m[3 * N][3 * N];

void solve() {
    int n; cin >> n;
    // vector<vector<int>> m(3 * n, vector<int>(3 * n));
    int area = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            m[i][j] = s[j] == '1';
            m[i + n][j] = m[i][j];
            m[i + 2 * n][j] = m[i][j];

            m[i][j + n] = m[i][j];
            m[i + n][j + n] = m[i][j];
            m[i + 2 * n][j + n] = m[i][j];

            m[i][j + 2 * n] = m[i][j];
            m[i + n][j + 2 * n] = m[i][j];
            m[i + 2 * n][j + 2 * n] = m[i][j];
            area += m[i][j];
        }
    }
    // vector<vector<ll>> a(3 * n + 1, vector<ll>(3 * n + 1));
    // for (auto &r : m) {
    //     dbg(r);
    // }

    auto M = [&](int i, int j) {
        while(i < 0) i += n;
        while(i >= n) i -= n;

        while(j < 0) j += n;
        while(j >= n) j -= n;

        return m[i][j];
        // int _i = i + 3 * n; _i %= n;
        // int _j = j + 3 * n; _j %= n;
        // return m[_i][_j];
    };

    // a[0][0] = 0;
    // for (int i = 0; i < 3 * n; i++) {
    //     for (int j = 0; j < 3 * n; j++) {
    //         a[i + 1][j + 1] = a[i + 1][j] + a[i][j + 1] + M(i, j) - a[i][j];
    //     }
    // }
    // auto area = [&](int l, int r, int u, int d) -> ll {
    //     // dbg(l, r, u, d);
    //     return a[d + 1][r + 1] - a[d + 1][l] - a[u][r + 1] + a[u][l];
    // };

    auto res = [&](int r, int c) -> ll {
        ll dia = 0;
        if(n & 1) {
            for (int i = - n / 2; i <= n / 2; i++) {
                // dia += m[r + i][c + i];
                dia += M(i + r, i + c);
            }
            return (n - dia) + (area - dia);
        }
        for (int i = - n / 2 + 1; i <= n / 2; i++) {
            // dia += m[r + i][c + i];
            dia += M(i + r, i + c);
        }
        return (n - dia) + (area - dia);
    };

    ll cost = 1e9;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            // dbg(r, c);
            ckmin(cost, res(r, c));
        }
    }
    cout << cost << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}