/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), dir(n), idx(n);
    iota(idx.begin(), idx.end(), 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    char x;
    for (int i = 0; i < n; i++) cin >> x, dir[i] = x == 'R' ? 1 : -1;
    sort(idx.begin(), idx.end(), [&](int &i, int &j) -> bool {
        return a[i] < a[j];
    });
    vector<int> res(n, -1);
{
    stack<array<int, 2>> sl, sr;

    for (int i = n - 1; i >= 0; i--) {
        if (a[idx[i]] & 1) continue;
        if (!dir[idx[i]]) continue;
        if (dir[idx[i]] != -1 && sl.empty()) continue;

        if (dir[idx[i]] == -1) sl.push({i, dir[idx[i]]});
        else {
            assert(dir[idx[i]] == 1);
            auto [id, di] = sl.top();
            assert(di == -1);
            res[idx[id]] = res[idx[i]] = abs(a[idx[i]] - a[idx[id]]) / 2;
            dir[idx[i]] = dir[idx[id]] = 0;
            sl.pop();
        }
    }
    while ((int)sl.size() > 1) {
        auto [id1, di1] = sl.top(); sl.pop();
        auto [id2, di2] = sl.top(); sl.pop();
        dir[idx[id1]] = dir[idx[id2]] = 0;
        res[idx[id1]] = res[idx[id2]] = (a[idx[id1]] + a[idx[id2]]) / 2;
    }

    for (int i = 0; i < n; i++) {
        if (a[idx[i]] & 1) continue;
        if (!dir[idx[i]]) continue;
        if (dir[idx[i]] != 1 && sr.empty()) continue;

        if (dir[idx[i]] == 1) sr.push({i, dir[idx[i]]});
        else {
            assert(dir[idx[i]] == -1);
            auto [id, di] = sr.top();
            assert(di == 1);
            res[idx[id]] = res[idx[i]] = abs(a[idx[i]] - a[idx[id]]) / 2;
            dir[idx[i]] = dir[idx[id]] = 0;
            sr.pop();
        }
    }
    while ((int)sr.size() > 1) {
        auto [id1, di1] = sr.top(); sr.pop();
        auto [id2, di2] = sr.top(); sr.pop();
        dir[idx[id1]] = dir[idx[id2]] = 0;
        res[idx[id1]] = res[idx[id2]] = (2 * m - (a[idx[id1]] + a[idx[id2]])) / 2;
    }

    if (!sr.empty() && !sl.empty()) {
        auto [idl, dil_] = sl.top(); sl.pop();
        auto [idr, dir_] = sr.top(); sr.pop();
        dir[idx[idl]] = dir[idx[idr]] = 0;
        res[idx[idl]] = res[idx[idr]] = (m - a[idx[idr]] + a[idx[idl]] + m) / 2;
    }
}
{
    stack<array<int, 2>> sl, sr;

    for (int i = n - 1; i >= 0; i--) {
        if (!(a[idx[i]] & 1)) continue;
        if (!dir[idx[i]]) continue;
        if (dir[idx[i]] != -1 && sl.empty()) continue;

        if (dir[idx[i]] == -1) sl.push({i, dir[idx[i]]});
        else {
            assert(dir[idx[i]] == 1);
            auto [id, di] = sl.top();
            assert(di == -1);
            res[idx[id]] = res[idx[i]] = abs(a[idx[i]] - a[idx[id]]) / 2;
            dir[idx[i]] = dir[idx[id]] = 0;
            sl.pop();
        }
    }
    while ((int)sl.size() > 1) {
        auto [id1, di1] = sl.top(); sl.pop();
        auto [id2, di2] = sl.top(); sl.pop();
        dir[idx[id1]] = dir[idx[id2]] = 0;
        res[idx[id1]] = res[idx[id2]] = (a[idx[id1]] + a[idx[id2]]) / 2;
    }

    for (int i = 0; i < n; i++) {
        if (!(a[idx[i]] & 1)) continue;
        if (!dir[idx[i]]) continue;
        if (dir[idx[i]] != 1 && sr.empty()) continue;

        if (dir[idx[i]] == 1) sr.push({i, dir[idx[i]]});
        else {
            assert(dir[idx[i]] == -1);
            auto [id, di] = sr.top();
            assert(di == 1);
            res[idx[id]] = res[idx[i]] = abs(a[idx[i]] - a[idx[id]]) / 2;
            dir[idx[i]] = dir[idx[id]] = 0;
            sr.pop();
        }
    }
    while ((int)sr.size() > 1) {
        auto [id1, di1] = sr.top(); sr.pop();
        auto [id2, di2] = sr.top(); sr.pop();
        dir[idx[id1]] = dir[idx[id2]] = 0;
        res[idx[id1]] = res[idx[id2]] = (2 * m - (a[idx[id1]] + a[idx[id2]])) / 2;
    }

    if (!sr.empty() && !sl.empty()) {
        auto [idl, dil_] = sl.top(); sl.pop();
        auto [idr, dir_] = sr.top(); sr.pop();
        dir[idx[idl]] = dir[idx[idr]] = 0;
        res[idx[idl]] = res[idx[idr]] = (m - a[idx[idr]] + a[idx[idl]] + m) / 2;
    }
}
    for (int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}