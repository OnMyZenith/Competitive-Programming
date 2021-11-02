#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, h;
    cin >> n >> h;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m1 = -1, m2 = -1, m1_idx = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > m1) {
            m1 = a[i];
            m1_idx = i;
        }
    for (int i = 0; i < n; i++)
        if (i != m1_idx && a[i] > m2) m2 = a[i];

    bool mx = true;
    int cnt = 0;
    ll sm = m1 + m2;
    while (h > 0) {
        if (h >= sm) {
            cnt = cnt + 2 * (h / sm);
            h %= sm;
        } else {
            if (mx) h -= m1;
            else
                h -= m2;
            mx = !mx;
            cnt++;
        }
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