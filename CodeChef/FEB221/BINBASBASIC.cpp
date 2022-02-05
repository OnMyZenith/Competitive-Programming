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
    int n,k; string s; cin >> n >> k >> s;
    int need = 0, i = 0, j = ((int)s.size()) - 1;
    while(j > i){
        if(s[i++]!=s[j--]) need++;
    }
    if(need == k) cout << "YES\n";
    else if(need > k) cout << "NO\n";
    else if(((int)s.size())&1) cout << "YES\n";
    else{
        if((k-need)&1) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve();
    }

    return 0;
}