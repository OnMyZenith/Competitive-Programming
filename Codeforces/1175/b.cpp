/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int N = 1e5 + 7;
const ll MX = 1ll << 32;
ll vals[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    ll ans = 0; string str; bool fail = 0;
    stack<ll> st; st.push(1);
    for (int i = 0, x, curr = 0; i < n; i++) {
        cin >> str;
        if (str[0] == 'f')
            cin >> x;

        if (fail) {
            continue;
        } else if (str[0] == 'a') {
            ans += st.top();
        } else if (str[0] == 'f') {
            st.push(min(MX, st.top() * x));
        } else if (str[0] == 'e') {
            st.pop();
        }
        if (ans > UINT32_MAX) fail = 1;
    }
    cout << (fail ? "OVERFLOW!!!" : to_string(ans)) << '\n';
    return 0;
}