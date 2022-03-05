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
    int n, l, r, s; cin >> n >> l >> r >> s;
    vector<int> res; res.reserve(n);
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + i;
    int cnt = r - l + 1;
    if(s < cnt * (cnt + 1) / 2 || s > n * cnt - (cnt - 1) * cnt / 2){ cout << "-1\n"; return;}
    for (int i = 0; i < n; i++) {
        if(pre[i + cnt] - pre[i] < s) continue;
        if(pre[i + cnt] - pre[i] >= s) {
            int d = (pre[i + cnt] - pre[i]) - s;
            set<int> ans;
            for (int j = i + 1; j <= i + cnt; j++) {
                ans.insert(j);
            }
            int j = 1;
            for (; j <= n && (int)res.size() <= l - 2; j++) {
                if(ans.count(j)) continue;
                res.push_back(j);
            }
            for (auto &u : ans) {
                res.push_back(u);
            }
            for (; j <= n; j++) {
                if(ans.count(j)) continue;
                res.push_back(j);
            }
            if(!d) break;
            int idx = -1;
            for (int id = 0; id < n; id++) {
                if(res[id] == res[l - 1] - 1) idx = id;
            }
            dbg(res, d, idx);
            assert(idx != -1);
            swap(res[idx], res[l + d - 2]);
            break;
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