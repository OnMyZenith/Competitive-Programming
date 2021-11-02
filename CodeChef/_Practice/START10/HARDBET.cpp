#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b && a < c) cout << "Draw\n";
        if (b < a && b < c) cout << "Bob\n";
        if (c < b && c < a) cout << "Alice\n";
    }

    return 0;
}