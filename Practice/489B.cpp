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

int main() {
    vamos;

    int n, m; cin >> n;
    std::priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a.push(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x; b.push(x);
    }
    int ans = 0;
    while(!a.empty() && !b.empty()) {
        int x = a.top(), y = b.top();
        a.pop(); b.pop();
        if(x == y || abs(x - y) == 1) ans++;
        else {
            if(x > y) {
                b.push(y);
            } else {
                a.push(x);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}