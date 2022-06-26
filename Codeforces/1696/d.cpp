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
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> big = {{a[n - 1], n - 1}}, small = {{a[n - 1], n - 1}};
    vector<int> adj(n);
    for (int i = n - 2; i >= 0; i--) {
        while (!big.empty() && big.back().first < a[i]) big.pop_back();
        while (!small.empty() && small.back().first > a[i]) small.pop_back();

        if (big.empty()) {
            adj[i] = small.front().second;
        } else if (small.empty()) {
            adj[i] = big.front().second;
        } else if (big.back().second < small.back().second) {
            int left = 0, right = (int)big.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (big[mid].second < small.back().second) right = mid;
                else left = mid + 1;
            }
            adj[i] = big[left].second;
        } else {
            int left = 0, right = (int)small.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (small[mid].second < big.back().second) right = mid;
                else left = mid + 1;
            }
            adj[i] = small[left].second;
        }

        small.push_back({a[i], i});
        big.push_back({a[i], i});
    }
    dbg(big, small);
    queue<pair<int, int>> q; q.push({0, 0});
    vector<bool> enque(n); enque[0] = 1;
    dbg(adj);
    while (!q.empty()) {
        auto [v, dis] = q.front(); q.pop();
        if (v == n - 1) {
            cout << dis << '\n';
            return;
        }
        if (!enque[adj[v]]) {
            q.push({adj[v], dis + 1});
            enque[adj[v]] = 1;
        }
    }
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