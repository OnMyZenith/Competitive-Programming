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

// Not Finished
void solve() {
    int n; cin >> n;
    vector<int> a(n), pre(n + 1);
    vector<pair<int, int>> res, new_res;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
        if(a[i] > 0) {
            res.push_back({i, i});
        }
    }

    bool f = 1;

    while(f) {
        f = 0;
        new_res.clear();

        int m = (int)res.size();

        if(res.front().first && pre[res[0].second + 1] > 0) {
            new_res.push_back({0, res[0].second});
            f = 1;
        } else if(pre[res[0].second + 1] == 0 && res[0].first > res[0].second - res[0].first + 1) {
            new_res.push_back({0, res[0].second});
            f = 1;
        }
        dbg(f);
        bool l_change = 0;
        for (int i = 1 + f; i < m - 1; i++) {
            int l1 = res[i - 1].first;
            int l2 = res[i].first;
            int l3 = res[i + 1].first;
            int r1 = res[i - 1].second;
            int r2 = res[i].second;
            int r3 = res[i + 1].second;

            if(pre[r2 + 1] - pre[l1] > pre[r3 + 1] - pre[l2] && pre[r2 + 1] - pre[l1] >= 0) {
                if(pre[r2 + 1] - pre[l1] > 0 || (pre[r2 + 1] - pre[l1] == 0 && l2 - r1 - 1 > r1 - l1 + 1 + r2 - l2 + 1)) {
                    new_res.push_back({l1, r2});
                    f = 1, i++;
                } else {
                    new_res.push_back({l1, r1});
                }
            } else if (pre[r2 + 1] - pre[l1] <= pre[r3 + 1] - pre[l2] && pre[r3 + 1] - pre[l2] >= 0) {
                if(pre[r3 + 1] - pre[l2] > 0 || (pre[r3 + 1] - pre[l2] == 0 && l3 - r2 - 1 > r2 - l2 + 1 + r3 - l3 + 1)) {
                    new_res.push_back({l1, r1});
                    new_res.push_back({l2, r3});
                    f = 1, i += 2;
                } else {
                    new_res.push_back({l1, r1});
                }
            } else {
                new_res.push_back({l1, r1});
            }
            if(i >= m - 1) l_change = 1;
        }
        dbg(f);
        if(!l_change) {
            if(res.back().second < m - 1 && pre[n] - pre[res.back().first] > 0) {
                new_res.push_back({res.back().first, n - 1});
                f = 1;
            } else if(pre[n] - pre[res.back().first] == 0 && n - res.back().second - 1 > res.back().second - res.back().first + 1) {
                new_res.push_back({res.back().first, n - 1});
                f = 1;
            } else {
                new_res.push_back(res.back());
            }
        } else {
            new_res.push_back(res.back());
        }

        dbg(res);
        dbg(new_res);
        

        res = new_res;
        f = 0;
    }

    int ans = -n;

    for (auto &[x, y] : res) {
        ans += y - x + 1;
    }

    cout << ans << '\n';



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