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
    int n; cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += bool((a[i] == 0) && ++a[i]);
    }
    set<int> remaining(a.begin(), a.end());

    vector<pair<int, vector<int>>> all = {{a[0], {a[0]}}};
    remaining.erase(a[0]);

    map<int, int> rank;
    rank[a[0]] = a[0];
    while (remaining.size()) {
        auto &[id, vec] = all.back();

        vector<int> to_remove;
        for (auto &e : remaining) {
            if (e & id) {
                to_remove.push_back(e);
                vec.push_back(e);
                if (id | e) id |= e;
            }
        }
        for (auto &e : to_remove) {
            remaining.erase(e);
        }
        if (!to_remove.empty()) {
            to_remove.clear();
        } else if(remaining.size()) {
            all.push_back({*remaining.begin(), {*remaining.begin()}});
            remaining.erase(*remaining.begin());
        }
    }
    int best = cnt;
    set<int> to_fix;
    for (auto &[id, vec] : all) {
        best += !(id & 1);
        if (!(id & 1)) to_fix.insert(id);
    }
    dbg(all);
    // dbg(cnt);
    // dbg(best);

    vector<int> res;
    for (int i = 0; i < n; i++) {
        bool found = 0;
        for (auto &[id, vec] : all) {
            for (auto &e : vec) {
                if (e == a[i]) {
                    if (!(id & 1)) {
                        if(to_fix.count(id)) {
                            ++a[i];
                            to_fix.erase(id);
                        }
                        found = 1;
                        break;
                    }
                }
            }
            if(found) break;
        }
    }
    cout << best << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
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