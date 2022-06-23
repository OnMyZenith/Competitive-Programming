/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Check result against SIZE of vector
template <class T> int lwbf(vector<T> &a, const T &b) { return int(lower_bound(a.begin(), a.end(), b) - begin(a)); }

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> p0, p1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') p0.push_back(i);
        else p1.push_back(i);
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
            if (i < n - 1 && s[i + 1] == '0') cnt++;
        } else {
            int j = lwbf(p1, i);
            if (j == (int)p1.size()) break;
            j = p1[j];
            int len = ++j - i;
            int num = 1;
            dbg(len);
            cnt += len == num;
            for (; j < n && len >= num; j++) {
                num <<= 1;
                num |= s[j] == '1';
                len++;
                cnt += len == num;
            }
        }
    }
    cout << cnt << '\n';
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