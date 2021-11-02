#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        pair<int, int> one;
        cin >> one.first >> one.second;
        edges.push_back(one);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}