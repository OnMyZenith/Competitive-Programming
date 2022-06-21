/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n = 3;
    vector<int> k(3);
    for (int i = 0; i < n; i++) cin >> k[i];
    vector<set<int>> s(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[i]; j++) {
            int x; cin >> x; s[i].insert(x);
        }
    }
    vector<int> a;
    for (int i = 0; i < n; i++) {
        for (auto &e : s[i]) {
            a.push_back(e);
        }
    }
    int N = 0; for (int i = 0; i < n; i++) N += (int)s[i].size();
    int mn = N - (int)s[0].size();
    for (int i = 1; i < n; i++) mn = min(mn, N - (int)s[i].size());
    cout << min((int)a.size() - lis(a), mn) << '\n';

    return 0;
}