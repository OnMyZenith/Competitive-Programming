#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")

using ll = long long;

void solve() {
    int x;
    cin >> x;
    cout << int(x ^ 1) << " " << x << " " << int(x ^ 2) << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while (TT--)
        solve();

    return 0;
}