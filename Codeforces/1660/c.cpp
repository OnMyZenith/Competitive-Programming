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
    string s; cin >> s;
    int n = (int)s.size(), cnt = 0;
    set<char> st;
    for (int i = 0; i < n; i++) {
        if(st.count(s[i])) {
            st.clear();
            cnt--;
        } else if(i < n - 1 && s[i] == s[i + 1]) {
            i++;
            st.clear();
        } else {
            st.insert(s[i]);
            cnt++;
        }
        dbg(st);
    }
    cout << cnt << '\n';



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