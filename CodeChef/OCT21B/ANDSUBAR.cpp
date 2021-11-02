#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt = -1, tmp = n;
    while (tmp) {
        cnt++;
        tmp /= 2;
    }
    if ((n - (int)pow(2, cnt) + 1) < ((int)pow(2, cnt) - (int)pow(2, cnt - 1)))
        cout << ((int)pow(2, cnt) - (int)pow(2, cnt - 1)) << '\n';
    else
        cout << (n - (int)pow(2, cnt) + 1) << '\n';
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