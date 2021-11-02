#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 1;
    int m = 1000000007;
    for (int i = 0; i < n; i++) {
        res *= 2;
        res %= m;
    }
    cout << res << '\n';

    return 0;
}