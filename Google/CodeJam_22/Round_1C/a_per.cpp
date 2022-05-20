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




void solve(int _TC) {
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    auto val = [&](string s) -> bool {
        vector<bool> seen(26);
        for (int i = 0; i < (int)s.size(); i++) {
            if(!seen[s[i] - 'A'] || s[i] == s[i - 1]) {
                seen[s[i] - 'A'] = 1;
                continue;
            }
            return false;
        }
        return true;
    };
    sort(v.begin(), v.end(), [&](string s1, string s2){
        if(s1.front() != s2.front()) return s1.front() < s2.front();
        return s1.back() < s2.back();
    });
    string res;
    for (auto &u : v) {
        res += u;
    }
    if(val(res)) {
        cout << "Case #" << _TC << ": " << res << '\n';
        return;
    }
    res.clear();
    sort(v.begin(), v.end(), [&](string s1, string s2){
        if(s1.front() != s2.front()) return s1.front() > s2.front();
        return s1.back() > s2.back();
    });
    for (auto &u : v) {
        res += u;
    }
    if(val(res)) {
        cout << "Case #" << _TC << ": " << res << '\n';
        return;
    }

    // vector<int> ord(n);
    // iota(ord.begin(), ord.end(), 0);
    // do {
    //     res.clear();
    //     for (int i = 0; i < n; i++) {
    //         res += v[ord[i]];
    //     }
    //     if(val(res)) {
    //         return;
    //     }
    // } while (next_permutation(ord.begin(), ord.end()));







    cout << "Case #" << _TC << ": " << "IMPOSSIBLE\n";

}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}