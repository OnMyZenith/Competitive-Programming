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

    pqinc<pair<ll, int>> q; q.push({0, 0});
    // vector<ll> dis(n, 4e18); dis[0] = 0;
    vector<ll> res; res.reserve(n);
    while(!q.empty()) {
        auto [d_v, v] = q.top(); q.pop();
        if(v == n - 1) res.push_back(d_v);
        if((int)res.size() >= k){
            dbg(res);
            break;
        }

        for (auto &[u, w] : adj[v]) {
            q.push({d_v + w, u});
        }
    }
    dbg(res);
    sort(res.begin(), res.end());
    ov(res, 0, 0, k);
    return 0;
}