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

int cnt[200007];
int precnt[200008];

int main() {
    vamos;

    int n, m; cin >> n >> m;
    vector<int> s(n), t(m);
    for (auto &i : s) {
        cin >> i; cnt[i]++;
    }
    for (auto &u : t) {
        cin >> u;
    }
    for (int i = 0; i < 200007; i++) {
        precnt[i + 1] = precnt[i] + cnt[i];
    }
    for (int i = 0; i < m; i++) {
        
    }

    return 0;
}