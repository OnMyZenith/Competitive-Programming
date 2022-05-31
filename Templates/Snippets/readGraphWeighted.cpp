// Return an adjecency list for a Graph with n nodes and m edges *with weights*
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
