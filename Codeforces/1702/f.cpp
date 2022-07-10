/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Because multiset.erase(t) will erase all occurances of t!!
template <class T, class U> bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    t.erase(it); return true;
}

void solve() {
    int n; cin >> n;
    multiset<int> a, b;
    for (int i = 0, x; i < n; i++) cin >> x, a.insert(x);
    for (int i = 0, x; i < n; i++) cin >> x, b.insert(x);

    vector<int> torema;
    for (auto &ele : a) {
        if (erase(b, ele)) torema.push_back(ele);
    }
    for (auto &ele : torema) {
        assert(erase(a, ele));
    }
    torema.clear();
    vector<int> _a;
    for (auto ele : a) {
        while (ele % 2 == 0) ele /= 2;
        _a.push_back(ele); 
    }
    a.clear();
    
    vector<int> _b;
    for (auto ele : b) {
        while (ele % 2 == 0) ele /= 2;
        _b.push_back(ele); 
    }
    b.clear();

    for (auto &u : _a) {
        a.insert(u);
    }

    for (auto &u : _b) {
        b.insert(u);
    }

    for (auto &ele : a) {
        if (erase(b, ele)) torema.push_back(ele);
    }
    for (auto &ele : torema) {
        assert(erase(a, ele));
    }
    torema.clear();

    bool poss = 1;
    for (auto ita = a.rbegin(); ita != a.rend() && poss; ++ita) {
        int tar = *ita;
        auto it = b.lower_bound(tar);
        if (it == b.end()) {
            poss = 0; break;
        } else if (tar != *it) {
            bool f = 0;
            for (int fac = 2; tar * fac <= *b.rbegin(); fac *= 2) {
                auto lo = b.lower_bound(tar * fac);
                auto hi = b.upper_bound(tar * fac + fac - 1);
                // dbg(tar);
                if (lo != hi) {
                    f = 1;
                    b.erase(--hi);
                    break;
                }
            }
            if (!f) {
                poss = 0;
                break;
            }
        }
    }

    cout << (poss ? "YES" : "NO") << '\n';

    dbg(a);
    dbg(b);

    // sort(_a.begin(), _a.end());
    // sort(_b.begin(), _b.end());
    // dbg(_a);
    // dbg(_b);

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}