#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int x;
    cin >> x;
    int y = 1;
    while (x / ((int)pow(2, y) - 1))
        y++;
    y--;
    cout << (int)pow(2, y) << '\n';
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