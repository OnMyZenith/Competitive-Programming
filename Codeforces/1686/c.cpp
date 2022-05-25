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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> res(n);
    for (int i = 0, l = (n + 1) / 2 - 1, r = n - 1; i < n; i++) {
        if(i & 1) {
            res[i] = a[l--];
        } else res[i] = a[r--];
    }
    dbg(res);
    bool f = 1;
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = i + 1;
        if(l < 0) l += n;
        if(r >= n) r -= n;
        f &= ((res[l] > res[i] && res[i] < res[r]) || (res[l] < res[i] && res[i] > res[r]));
        dbg(f);
    }

    if(f) {
        cout << "YES\n";
        ov(res);
    } else cout << "NO\n";
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