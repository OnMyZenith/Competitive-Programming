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


// Because multiset.erase(ele) will erase all occurances of ele!!
template <class T, class U> bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    t.erase(it); return true;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    // sort(a.begin(), a.end());
    multiset<ll> final(a.begin(), a.end());
    queue<ll> q; q.push(sum);
    while(!q.empty()) {
        ll v = q.front(); q.pop();
        if(v == 0) {
            cout << "NO\n";
            return;
        }
        auto it = final.find(v);
        if(it != final.end()) {
            final.erase(it);
        } else {
            if(final.lower_bound(v) == final.begin() || (int)q.size() > (int)final.size()) {
                cout << "NO\n";
                return;
            }
            q.push(v / 2);
            q.push((v + 1) / 2);
        }
    }
    cout << (final.empty() ? "YES\n" : "NO\n");
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