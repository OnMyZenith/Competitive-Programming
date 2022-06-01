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


template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); // mt19937 rng(61378913);
// e.g. shuffle(permutation.begin(), permutation.end(), rng);

// Not Complete
void solve() {
    int n; cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        p[a[i]] = i;
    }
    vector<array<int, 3>> bad;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] != i) {
            int r = i; bool yuck = 1;
            for (int j = i; j <= r; j++) {
                if(a[j] != j) ckmax(r, a[j]);
                else yuck = 0, ans++;
            }
            bad.push_back({i, r, yuck});
            i = r;
        }
    }
    ans += (int)bad.size();
    cout << ans << '\n';
    for (auto &[l, r, terrible] : bad) {
        if(!terrible) {
            cout << l + 1 << " " << r + 1 << '\n';
            int nl = l, nr = r;
            for (int i = l; i <= r; i++) {
                if(a[i] != i) {
                    for (int j = i + 1; j <= r; j++) {
                        if(a[j] == i) {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    nl = i + 1;
                } else break;
            }
            l = nl;
            for (int i = r; i >= l; i--) {
                if(a[i] != i) {
                    for (int j = i - 1; j >= l; j++) {
                        if(a[j] == i) {
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    nr = i - 1;
                } else break;
            }
            r = nr;
            vector<int> b(a.begin() + l, a.begin() + r + 1);
            bool fail = 0;
            do {
                rotate(a.begin() + l, a.begin() + l + 1, a.begin() + r + 1);
                for (int i = l; i <= r; i++) {
                    if(a[i] == i || a[i] == b[i - l]) {
                        fail = 1;
                        break;
                    }
                }
            } while(fail);
            ov(a, 1);

            cout << l + 1 << " " << r + 1 << '\n';
            sort(a.begin() + l, a.begin() + r + 1);
            ov(a, 1);
        } else {
            cout << l + 1 << " " << r + 1 << '\n';
            sort(a.begin() + l, a.begin() + r + 1);
            ov(a, 1);
        }
    }
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