/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

vector<vector<int>> reG(int n, int m, bool bi = 1) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        if(bi) adj[v].push_back(u);
    }
    return adj;
}

// Topological Sorting using Kahn’s Algorithm, from Neal's submission https://codeforces.com/contest/1217/submission/66762268
// Note: if there is a cycle, the size of the return will be less than n.
vector<int> topological_sort(const vector<vector<int>> &adj, int lim, vector<int> &a) {
    int n = (int)adj.size();
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (a[i] <= lim && in_degree[i] == 0)
            order.push_back(i);

    int current = 0;

    while (current < (int)order.size()) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m; ll k; cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto adj = reG(n, m, 0);

    int MX = *max_element(a.begin(), a.end());
    int lo = 0, hi = MX + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        vector<vector<int>> adj2(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) continue;
            cnt++;
            for (auto &v : adj[i]) {
                if (a[v] <= mid) adj2[i].push_back(v);
            }
        }
        auto t = topological_sort(adj2, mid, a);
        if ((int)t.size() < cnt) hi = mid;
        else {
            reverse(t.begin(), t.end());
            vector<int> dep(n, 1);
            int ans = 0;
            for (auto &v : t) {
                for (auto &u : adj2[v]) {
                    dep[v] = max(dep[v], dep[u] + 1);
                }
                ans = max(ans, dep[v]);
            }
            if (ans >= k) hi = mid;
            else lo = mid + 1;
        }
    }
    cout << (lo > MX ? -1 : lo) << '\n';


    return 0;
}