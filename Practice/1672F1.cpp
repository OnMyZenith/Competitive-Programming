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

template <class T>
void remDupf(vector<T> &v) { sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), end(v)); }
template <typename T_vector>
void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}
template <class T>
bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T>
bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int best = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int l = i; cnt = 0;
        for (int j = i; j < n; j++) {
            if (a[l] != a[j]) {
                break;
            } else {
                cnt++;
                ckmax(best, cnt);
            }
            i = j;
        }
    }
    rotate(a.begin(), a.begin() + best, a.end());
    ov(a);
    // remDupf(a);
    // dbg(a);
    // cout << (int)a.size() - 1 << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}