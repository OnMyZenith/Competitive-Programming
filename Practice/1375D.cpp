/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
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
    vector<int> a(n), f(n + 1);
    set<int> s; s.insert(n);
    for (int i = 0; i < n; i++) cin >> a[i], f[a[i]]++, s.insert(i);
    auto tmp = s;
    for (int i = 0; i < n; i++) {
        s.erase(a[i]);
    }

    vector<int> res;

    int mex = *s.begin();
    while (1) {
        if (mex == n) {
            bool done = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] != j) {
                    res.push_back(j + 1);
                    s.erase(mex);
                    f[a[j]]--;
                    f[mex]++;
                    s.insert(a[j]);
                    a[j] = mex;
                    done = 1;
                    break;
                }
            }
            if (!done) break;
        } else {
            if (!--f[a[mex]]) s.insert(a[mex]);
            s.erase(mex);
            a[mex] = mex;
            f[mex]++;
            res.push_back(mex + 1);
        }
        mex = *s.begin();
    }
    dbg(a);
    cout << (int)res.size() << '\n';
    ov(res);
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