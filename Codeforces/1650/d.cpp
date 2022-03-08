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

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}



void solve() {
    int n; cin >> n;
    vector<int> a(n), fin(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--; fin[a[i]] = i;
    }
    // dbg(fin);
    vector<int> res(n);
    // int s = 0;
    for (int i = n - 1; i >= 0; i--) {
        int r = fin[i];
        res[i] = i;
        for (int j = n - 1; j >= i; j--) {
            r -= res[j];
            r %= j + 1; r += j + 1;
            r %= j + 1;
        }
        // dbg(r, res);
        res[i] = r;
        // dbg(res[i], i);
        // res[i] %= i + 1; res[i] += i + 1;
        // res[i] %= i + 1;
        // s += res[i];
    }
    dbg(res);
    // res[n - 1]++;
    vector<int> sane(n);
    iota(sane.begin(), sane.end(), 1);
    for (int i = 0; i < n; i++) {
        rotate(sane.begin(), sane.begin() + i + 1 - res[i], sane.begin() + i + 1);
    }
    // dbg(sane);
    for (int i = 0; i < n; i++) a[i]++;
    if(sane == a) {
        ov(res);
    } else {
        cout << "-1\n";
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