/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())

using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#define chk(...) 007
#endif

const long double PI = 3.14159265358979323846L;
const long long LINF = 2e18L + 007;
const int IINF = 2e9 + 007;
const int MOD = 1e9 + 007; // 998244353;
const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB

vector<vector<int>> reG(int n, int m, bool bi = 1) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        if(bi) adj[v].push_back(u);
    }
    return adj;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj = reG(n, m, 0);
    int k; cin >> k;
    vector<int> p(k);
    for (auto &a : p) {
        cin >> a; a--;
    }
    queue<int> q, q2; q.push(p.back());
    vector<int> vis(n,0); vis[p.back()] = 1;
    vector<int> dist(n); int dis = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for (auto &a : adj[v]) {
            if (vis[a]) {
                if (dis == dist[a]) {
                    vis[a] = 2;
                }
            } else {
                vis[a] = 1;
                dist[a] = dis;
                q2.push(a);
            }
        }
        if(q.empty()) swap(q,q2), dis++;
    }
    int wrong = 0, diff = 0;
    for (int i = 0; i < k - 1; i++)  {
        int curr = p[i], next = p[i + 1];
        if(dist[next] != dist[curr] - 1) wrong++;
        else if(vis[curr] == 2) diff++;
    }
    cout << wrong << " " << wrong + diff << '\n';
}

int main() {

    vamos;

    int TT = 1;
    // cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve();
    }

    return 0;
}