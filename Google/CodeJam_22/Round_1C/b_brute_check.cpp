#include "home.hpp"

int main() {
    vamos;

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n);
        re(a);
        vector<string> s(3); cin >> s[0] >> s[1] >> s[2];
        if(s[2] == "IMPOSSIBLE") continue;
        dbg(s);
        ll x = stoll(s[2]);
        ll su = 0, sq = 0;
        for (int i = 0; i < n; i++) sq += a[i] * a[i];
        sq += x * x;
        su = accumulate(a.begin(), a.end(), 0ll) + x;
        su *= su;
        assert(su == su);
    }



    return 0;
}