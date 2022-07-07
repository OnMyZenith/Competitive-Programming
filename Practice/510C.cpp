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

// Topological Sorting using Kahn’s Algorithm, from Neal's submission https://codeforces.com/contest/1217/submission/66762268
// Note: if there is a cycle, the size of the return will be less than n.
vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = (int)adj.size();
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
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

bool find_cycle(int v, vector<vector<int>> &adj, vector<int> &color, vector<int> &topsort) {
    color[v] = 1;
    for (auto &u : adj[v]) {
        if (color[u] == 1) return 1;
        if (color[u] == 0) if (find_cycle(u, adj, color, topsort)) return 1;
    }
    topsort.push_back(v);
    color[v] = 2;
    return 0;
}

int main() {
    vamos;

    int n, mx = 0; cin >> n;
    vector<string> s(n);
    for (auto &u : s) {
        cin >> u;
        mx = max(mx, (int)u.size());
    }
    vector<set<int>> g(26);
    vector<int> in(26, 0);
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            string s1 = s[i], s2 = s[k];
            int m = (int) max(s1.size(), s2.size());
            for (int j = 0; j < m; j++) {
                if(j == (int)s1.size()) break;
                if(j == (int)s2.size()) {
                    cout << "Impossible\n";
                    return 0;
                }
                if(s1[j] == s2[j]) continue;
                g[s1[j] - 'a'].insert(s2[j] - 'a');
                in[s2[j] - 'a']++;
                break;
            }
        }
    }

    vector<vector<int>> adj(26);
    for (int i = 0; i < 26; i++) {
        for (auto &u : g[i]) {
            adj[i].push_back(u);
        }
    }
    vector<int> color(26);
    vector<int> t;
    for (int i = 0; i < 26; i++) {
        if (color[i] == 0 && find_cycle(i, adj, color, t)) {
            cout << "Impossible\n";
            return 0;
        }
    }
    reverse(t.begin(), t.end());

    // auto t = topological_sort(adj);
    // if ((int)t.size() < 26) {
    //     cout << "Impossible\n";
    //     return 0;
    // }
    for (int i = 0; i < 26; i++) {
        cout << char(t[i] + 'a');
    }
    cout << '\n';
    return 0;
}