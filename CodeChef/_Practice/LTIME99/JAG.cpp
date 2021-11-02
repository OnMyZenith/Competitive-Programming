#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    ll id[n];
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        id[i] = weight - i;
    }
    bool allSame = true;
    int one = id[0];
    for (int i : id)
        if (i != one) {
            allSame = false;
            break;
        }
    if (allSame) cout << n << '\n';
    else
        cout << 1 << '\n';
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