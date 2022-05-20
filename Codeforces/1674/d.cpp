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




void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    if(n == 1) {
        cout << "YES\n";
        return;
    }
    vector<int> c;
    if(n & 1) {
        c.push_back(a.front());
        reverse(a.begin(), a.end());
        a.pop_back();
        reverse(a.begin(), a.end());
        // n--;
    }
    reverse(a.begin(), a.end());

    dbg(a);
    while(a.size() > 1) {
        int x = a.back(); a.pop_back();
        int y = a.back(); a.pop_back();
        c.push_back(min(x, y));
        c.push_back(max(x, y));
        // dbg(x, y);
        // a.push_back(max(x, y));
    }
    if(!a.empty()) c.push_back(a.back());
    bool pass = 1;
    for (int i = 0; i < n - 1; i++) pass &= c[i + 1] >= c[i];
    dbg(c);
    cout << (pass ? "YES" : "NO") << '\n';



}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}