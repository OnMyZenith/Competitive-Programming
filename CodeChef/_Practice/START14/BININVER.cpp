#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    bool going = true;
    while (1) {
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 1) {
                going = false;
                break;
            } else {
                a[i] /= 2;
            }
        if (!going) break;
        cnt++;
    }
    cout << cnt << '\n';
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