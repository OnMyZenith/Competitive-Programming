/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << "-1\n";
        return;
    }
    set<int> s(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        auto it = s.begin();
        if (*it == a[i]) {
            if ((int)s.size() == 1) {
                b[i] = b[i - 1];
                b[i - 1] = *it;
                break;
            } else {
                it++;
            }
        }
        b[i] = *it;
        s.erase(it);
    }
    ov(b);
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