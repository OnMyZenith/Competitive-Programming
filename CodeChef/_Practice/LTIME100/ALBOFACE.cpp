#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool hasControl(ll n, bool turnAlice) {
    if (n == 0) return !turnAlice;
    else if (n % 4 == 0)
        return turnAlice;
    else if (n & 1)
        return hasControl(n - 1, !turnAlice);
    else
        return hasControl(n / 2, !turnAlice);
}

void solve() {
    ll n;
    cin >> n;
    if (hasControl(n, true)) cout << "ALICE\n";
    else
        cout << "BOB\n";
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