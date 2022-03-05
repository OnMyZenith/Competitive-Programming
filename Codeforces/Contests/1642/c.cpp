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
    int n, x; cin >> n >> x;
    vector<ll> a(n);
    multiset<ll> prime, div;
    for (auto &u : a) {
        cin >> u;
        if(u % x) prime.insert(u);
        else div.insert(u);
    }
    int rem = 0;
    for (auto &u : prime) {
        auto it = div.find(u * x);
        if(it != div.end()) {
            div.erase(it); rem++;
        }
    }
    for (auto it = div.begin(); it != div.end(); it++){
        auto itx = div.find((*it) * x);
        if(itx != div.end()){
            div.erase(itx); rem++;
        }
    }

    cout << prime.size() + div.size() - rem << '\n';
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