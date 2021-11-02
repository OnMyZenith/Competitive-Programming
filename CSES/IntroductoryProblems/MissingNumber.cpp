#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    long long k = n * (n + 1) / 2;
    long long v;
    while (--n) {
        cin >> v;
        k -= v;
    }
    cout << k;

    return 0;
}