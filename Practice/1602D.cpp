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


int main() {
    vamos;

    int n; cin >> n;
    vector<int> height(n), slip(n);
    for (auto &u : height) {
        cin >> u;
    }
    for (auto &u : slip) {
        cin >> u;
    }
    
    queue<int> q, q2; q.push(n-1); vector<bool> vis(n); vis[n-1] = 1;
    vector<int> par(n), slipFrom(n); par[n-1] = -1;
    int jmps = 1; int ex = -1;
    while(!q.empty()){
        int v = q.front(); q.pop();

        for (int i = 1; i <= height[v]; i++) {
            int tmp_u = v - i;
            if(tmp_u < 0) {ex = v; break;}

            int u = tmp_u + slip[tmp_u];

            if (!vis[u]) {
                vis[u] = 1;
                par[u] = v;
                slipFrom[u] = tmp_u;
                q2.push(u);
            }
        }

        if(ex!=-1) break;
        if(q.empty()) swap(q,q2), jmps++;
    }
    dbg(vis);
    if(ex==-1) {cout << "-1\n"; return 0;}

    cout << jmps << '\n';
    vector<int> path;
    while(ex!=n-1){
        path.push_back(ex);
        ex = par[ex];
    }
    reverse(path.begin(), path.end());
    for (auto &u : path) {
        cout << slipFrom[u] + 1 << " ";
    }
    cout << "0\n";
    return 0;
}