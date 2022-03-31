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
    int n, k; cin >> n >> k;
    vector<int> a(n), freq(n + 1), ans(n + 1), res(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        if(freq[a[i]] >= k) ans[a[i]] = k;
        else {
            sm++;
        }
    }
    sm -= sm % k;
    for (int i = 0; i < n; i++) {
        if(freq[a[i]] >= k) {
            res[i] = max(ans[a[i]]--, 0);
        }
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){return a[i] < a[j];});
    for (int i = 0; i < n; i++) {
        if(freq[a[idx[i]]] < k) {
            sm--;
            res[idx[i]] = max((sm % k) + 1, 0ll);
        }
    }
    ov(res);
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