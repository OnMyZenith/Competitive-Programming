#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> inc, dec;

    for (int i = 0; i < n - 1; i++)
        if (a[i] <= a[i + 1]) {
            int start = i;
            while (i < n - 1 && a[i] <= a[i + 1])
                i++;
            inc.push_back(make_pair(start, i));
        }
    for (int i = 0; i < n - 1; i++)
        if (a[i] >= a[i + 1]) {
            int start = i;
            while (i < n - 1 && a[i] >= a[i + 1])
                i++;
            dec.push_back(make_pair(start, i));
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