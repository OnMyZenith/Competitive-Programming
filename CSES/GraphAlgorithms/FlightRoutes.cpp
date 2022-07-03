/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

vector<vector<array<int, 2>>> reGweighted(int n, int m, bool bi = 1) {
    vector<vector<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        adj[u].push_back({v, x});
        if(bi) adj[v].push_back({u, x});
    }
    return adj;
}

template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, m, k; cin >> n >> m >> k;
    auto adj = reGweighted(n, m, 0);
    vector<pqdec<ll>> best(n);
    best[0].push(0);
    pqinc<pair<ll, int>> q; q.push({0, 0});

    while(!q.empty()) {
        auto [d_v, v] = q.top(); q.pop();

        // if (best[v].top() < d_v) continue;
        if ((int)best[v].size() == k && best[v].top() < d_v) continue;

        for (auto &[u, w] : adj[v]) {
            if ((int)best[u].size() < k) {
                best[u].push(d_v + w);
                q.push({d_v + w, u});
            } else if (best[u].top() > d_v + w) {
                best[u].pop();
                best[u].push(d_v + w);
                q.push({d_v + w, u});
            }
        }
    }
    vector<ll> res;
    while (!best[n - 1].empty()) {
        res.push_back(best[n - 1].top());
        best[n - 1].pop();
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " \n"[i == (int)res.size() - 1];
    }
    return 0;
}