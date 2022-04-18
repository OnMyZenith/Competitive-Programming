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


template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto ans = [&](int s, int e) -> pair<int, pair<int, int>> {
        // dbg(s, e);
        int res = 0;
        bool neg = 0;
        for (int i = s; i <= e; i++) {
            if(!a[i]) assert(false);
            res += (abs(a[i]) == 2);
            if(a[i] < 0) neg = !neg;
        }
        if(neg) {
            int l = -1, r = -1;
            int r1 = res, r2 = res;
            for (int i = s; i <= e; i++) {
                if(a[i] < 0) {
                    r1 -= (abs(a[i]) == 2);
                    l = i + 1;
                    break;
                } else r1 -= (abs(a[i]) == 2);
            }
            for (int i = e; i >= s; i--) {
                if(a[i] < 0) {
                    r2 -= (abs(a[i]) == 2);
                    r = i - 1;
                    break;
                } else r2 -= (abs(a[i]) == 2);
            }
            if(r1 > r2) {
                return {r1, {l, e}};
            } else {
                return {r2, {s, r}};
            }
        }
        return {res, {s, e}};
    };

    pair<ll, pair<int, int>> fin{0, {-1, -1}};
    for (int i = 0; i < n; i++) {
        if(a[i]) {
            int s = i;
            for (int j = s; j < n; j++) {
                if(a[j] == 0) {
                    auto rr = ans(s, j - 1);
                    if(fin.first < rr.first){
                        fin = rr;
                    }
                    i = j;
                    break;
                } else if(j == n - 1) {
                    auto rr = ans(s, j);
                    if(fin.first < rr.first){
                        fin = rr;
                    }
                    i = j;
                    break;
                }
                
            }
        }
    }
    // if(fin.second.second == -1) {
    //     fin = ans(0, n - 1);
    // }
    if(fin.first == 0) {
        cout << n << " 0\n";
        return;
    }
    dbg(fin);
    cout << fin.second.first << " " << n - fin.second.second - 1 << '\n';
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