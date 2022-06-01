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

int LOG = 32;
int up[int(2e5 + 7)][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> up[i][0], up[i][0]--;
    }
    vector<pair<int, int>> Q(q);
    int K = 0;
    for (auto &[v, k] : Q) {
        cin >> v >> k;
        v--; K = max(K, k);
        if(k & 1) v = up[v][0];
    }

    LOG = 32 - (__builtin_clz(K)) + 1;
    for (int lvl = 1; lvl < LOG; lvl++) {
        for (int v = 0; v < n; v++) {
            up[v][lvl & 1] = up[up[v][!(lvl & 1)]][!(lvl & 1)];
        }
        for (int i = 0; i < q; i++) {
            if((Q[i].second >> lvl) & 1) Q[i].first = up[Q[i].first][lvl & 1];
        }
        
    }

    for (int i = 0; i < q; i++)  {
        auto [v, k] = Q[i];
        cout << ++v << " \n"[i == q - 1];
    }

    return 0;
}