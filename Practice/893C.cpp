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

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

int main() {
    vamos;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), cost(n, 1e9 + 7);
    for (auto &u : a) {
        cin >> u;
    }
    union_find UF(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        UF.unite(x, y);
    }
    for (int i = 0; i < n; i++) {
        int par = UF.find(i);
        ckmin(cost[par], a[i]);
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if(cost[i] <= 1e9) res += cost[i];
    }
    cout << res << '\n';
    return 0;
}