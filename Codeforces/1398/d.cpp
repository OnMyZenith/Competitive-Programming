/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

const int N = 207;
ll dp[N][N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int r, b, g; cin >> r >> b >> g;
    vector<ll> R(r), B(b), G(g);
    for (auto &u : R) {
        cin >> u;
    }
    for (auto &u : B) {
        cin >> u;
    }
    for (auto &u : G) {
        cin >> u;
    }
    sort(R.rbegin(), R.rend());
    sort(B.rbegin(), B.rend());
    sort(G.rbegin(), G.rend());

    ll ans = 0;

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= g; k++) {
                (i > 0 && j > 0) && ckmax(dp[i][j][k], dp[i - 1][j - 1][k] + R[i - 1] * B[j - 1]);
                (i > 0 && k > 0) && ckmax(dp[i][j][k], dp[i - 1][j][k - 1] + G[k - 1] * R[i - 1]);
                (k > 0 && j > 0) && ckmax(dp[i][j][k], dp[i][j - 1][k - 1] + B[j - 1] * G[k - 1]);
            }
        }
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= g; k++) {
                ckmax(ans, dp[i][j][k]);
            }
        }
    }
    
    // for (int _rb = 0; _rb <= min(r, b); _rb++) {
    //     for (int _bg = 0; _bg <= min(b - _rb, g); _bg++) {
    //         int rb = _rb, bg = _bg, gr = min(r - _rb, g - _bg);
    //         ll curr = 0;
    //         int i = 0, j = 0, k = 0;
    //         while (rb || bg || gr) {
    //             int sk = -1; ll area = -1;
    //             // dbg(i, j, k, rb, bg, gr);
    //             if(rb > 0 && ckmax(area, (ll) R[i] * B[j])) sk = 2;
    //             if(bg > 0 && ckmax(area, (ll) G[k] * B[j])) sk = 0;
    //             if(gr > 0 && ckmax(area, (ll) R[i] * G[k])) sk = 1;
    //             // dbg(sk);
    //             if(sk == 2) {
    //                 rb--; i++, j++;
    //             } else if (sk == 1) {
    //                 gr--, i++, k++;
    //             } else {
    //                 bg--, j++, k++;
    //             }
    //             curr += area;
    //         }
    //         if(_rb == 4 && _bg == 6) {
    //             dbg(rb, bg, gr);
    //             dbg(min(r - _rb, g - _bg), curr);
    //         }
    //         ckmax(ans, curr);
    //     }
    // }

    cout << ans << '\n';
    return 0;
    // while (i < r && j < b && k < g) {
    //     int mn = 2e9, sk = -1;
    //     if(ckmin(mn, R[i])) sk = 0;
    //     if(ckmin(mn, B[j])) sk = 1;
    //     if(ckmin(mn, G[k])) sk = 2;
    //     dbg(sk);
    //     if(sk == 0) {
    //         if (B[j] == R[i]) {
    //             if(b - j < r - i) sk = 1;
    //         } else if (G[k] == R[i]) {
    //             if(g - k < r - i) sk = 2;
    //         }
    //     }
    //     dbg(sk);

    //     if(sk == 1) {
    //         if (B[j] == R[i]) {
    //             if(b - j > r - i) sk = 0;
    //         } else if (G[k] == B[j]) {
    //             if(g - k < b - j) sk = 2;
    //         }
    //     }

    //     if(sk == 2) {
    //         if (G[k] == R[i]) {
    //             if(g - k < r - i) sk = 0;
    //         } else if (G[k] == B[j]) {
    //             if(g - k < b - j) sk = 1;
    //         }
    //     }

    //     if(sk == 0) {
    //         if (B[j] == R[i]) {
    //             if(b - j < r - i) sk = 1;
    //         } else if (G[k] == R[i]) {
    //             if(g - k < r - i) sk = 2;
    //         }
    //     }

    //     if(sk == 1) {
    //         if (B[j] == R[i]) {
    //             if(b - j > r - i) sk = 0;
    //         } else if (G[k] == B[j]) {
    //             if(g - k < b - j) sk = 2;
    //         }
    //     }

    //     ll area = 1;
    //     if (sk != 0) area *= R[i++];
    //     if (sk != 1) area *= B[j++];
    //     if (sk != 2) area *= G[k++];
    //     ans += area;
    // }
    // while (i < r && j < b) {
    //     ll area = (ll) R[i++] * B[j++];
    //     ans += area;
    // }

    // while (i < r && k < g) {
    //     ll area = (ll) R[i++] * G[k++];
    //     ans += area;
    // }

    // while (k < g && j < b) {
    //     ll area = (ll) G[k++] * B[j++];
    //     ans += area;
    // }
}