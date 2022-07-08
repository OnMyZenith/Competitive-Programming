/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

vector<array<int, 2>> g;
int n;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to = g[v][0] - 1; to < g[v][1]; to++) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

using ii = pair<int, int>;
template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;


void solve() {
    cin >> n;
    g.clear();
    g.resize(n);
    mt.assign(n, -1);

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];

        if (b[i]) {
            g[i][0] = (i + 1 + b[i]) / (b[i] + 1) + !((i + 1) % (b[i] + 1));
            g[i][1] = (i + 1) / b[i];
        } else
            g[i][0] = i + 2, g[i][1] = n;
    }

    vector<pair<pair<int, int>, int>> window(n);
    for (int i = 0; i < n; i++) {
        window[i].second = i + 1;
        // cin >> window[i].first.first >> window[i].first.second;
        window[i].first.first = g[i][0];
        window[i].first.second = g[i][1];
    }
    sort(window.rbegin(), window.rend());
    dbg(g);
    dbg(window);

    vector<int> ans;
    // priority_queue<ii, vector<ii>, greater<ii>> pq;
    pqinc<ii> pq;
    for (int i = 1; i <= n; i++) {
        while (window.size() > 0 && window.back().first.first <= i) {
            pq.push({window.back().first.second, window.back().second});
            window.pop_back();
        }

        if (pq.empty()) {
            ans.clear();
            break;
        }

        auto [e, idx] = pq.top();
        pq.pop();
        if (i > e) {
            ans.clear();
            break;
        }
        ans.push_back(idx);
    }

    if (ans.size() == 0) {
        assert(0);
    } else {
        // for (const int &p : ans) {
        //     cout << p << ' ';
        // }
        vector<int> per(n);
        // iota(per.begin(), per.end(), 1);

        for (int i = 0; i < n; i++) per[ans[i] - 1] = i;

        for (int i = 0; i < n; i++) cout << per[i] + 1 << " ";

        cout << '\n';
    }

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}