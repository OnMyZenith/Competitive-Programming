/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int _ = 307;
double p[_][_][_];
double ex[_][_][_];

int main() {
    vamos;
    int n; cin >> n;
    vector<int> f(3), a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    // p[a][b][c] -> Probability of getting to a->1s, b->2s, and c->3s;
    // ex[a][b][c] -> expected number of ops to get to a->1s, b->2s, and c->3s;


    

    return 0;
}