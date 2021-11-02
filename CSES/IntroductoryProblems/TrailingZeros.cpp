#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int res = 0;
    int div = 5;
    while (n / div) {
        res += n / div;
        div *= 5;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}