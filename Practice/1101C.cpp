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



void solve() {
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> point(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> point[2 * i].first.first >> point[2 * i + 1].first.first;
        point[2 * i].first.second = -1;
        point[2 * i + 1].first.second = 1;  // so that after sorting end comes after begin
        point[2 * i].second = point[2 * i + 1].second = i + 1;
    }
    sort(point.begin(), point.end());
    set<int> ans, tmp; int c = 0; bool skip = 0;
    for (auto &[P, id] : point) {
        auto &[p, dir] = P;
        c += dir;
        tmp.insert(id);
        if(!c) {
            skip = !skip;
            if(!skip) {
                for (auto &u : tmp) {
                    ans.insert(u);
                }
            }
            tmp.clear();
        }
    }
    if(ans.empty() || (int)ans.size() == n) {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if(ans.count(i)) cout << 1 << " \n"[i == n];
        else cout << 2 << " \n"[i == n];
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