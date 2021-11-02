#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int m, n;
    cin >> m;
    int c[m];
    for (int i = 0; i < m; i++)
        cin >> c[i];
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
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