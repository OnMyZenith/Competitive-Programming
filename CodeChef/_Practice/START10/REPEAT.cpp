#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k, s;
        cin >> n >> k >> s;
        cout << (s - n * n) / (k - 1) << "\n";
    }

    return 0;
}