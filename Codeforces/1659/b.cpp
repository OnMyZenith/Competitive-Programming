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
    int n, K; string s; cin >> n >> K >> s;
    int k = K;
    int r = -1;
    vector<int> fin(n);
    for (int i = 0; i < n && k; i++) {
        if(s[i] == '1') {
            k -= (K & 1);
            fin[i] = (K & 1);
        }
        else {
            k -= !(K & 1);
            fin[i] = !(K & 1);
        }
        // dbg(k);
        if(!k) r = i;
    }
    string res = s;
    // dbg(k);
    if(k) {
        if(k & 1) {
            res = string(n, '1');
            res.back() = '0';
            fin.back() += k;
            cout << res << '\n';
            ov(fin);
        } else {
            res = string(n, '1');
            // res.back() = '0';
            fin.back() += k;
            cout << res << '\n';
            ov(fin);
        }
        return;
    }

    for (int i = 0; i <= r; i++) res[i] = '1';
    for (int i = r + 1; i < n; i++) if(K & 1) res[i] = (s[i] == '0' ? '1' : '0');
    cout << res << '\n';
    ov(fin);
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