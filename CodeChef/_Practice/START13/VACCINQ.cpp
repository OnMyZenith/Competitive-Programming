#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, p, x, y, time = 0;
    cin >> n >> p >> x >> y;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < p; i++)
        if (a[i] == 1) time += y;
        else
            time += x;
    cout << time << '\n';
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