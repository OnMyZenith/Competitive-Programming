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


string printRLE(string s)
{
    string r;
    for (int i = 0; s[i] != '\0'; i++) {
 
        // Counting occurrences of s[i]
        int count = 1;
        while (s[i] == s[i + 1]) {
            i++;
            count++;
        }
        r += s[i];
        r += to_string(count);
        // cout << s[i] << count << " ";
    }
    return r;
    // cout << endl;
}

void solve() {
    int n; string s; cin >> n >> s;
    int m; cin >> m;
    set<char> p;
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        p.insert(c);
    }


    string r = s;
    for (int i = 0; i < n; i++) if(p.count(s[i])) r[i] = '1'; else r[i] = '0';
    auto res = printRLE(r);
    dbg(res);

    reverse(r.begin(), r.end());
    if(r.find('1') == r.npos) {
        cout << "0\n";
        return;
    }
    int ans = 0, dup = 0;
    for (int i = r.find('1'); i < n; i++) {
        if(r[i] == '0') ans++;
        else {
            for (int j = i; j < i + ans; j++) {
                if(r[i] == '0') continue;
                else break;
            }
            ans++;
        }
    }



    // int l = 0;
    // for (int i = 0; i < n; i++) {
    //     if(!a[i] || !i) {
    //         int l0 = 1;
    //         i++;
    //         for (int j = i; j < n; j++, l0++, i++) {
    //             if(a[j]) {
    //                 i--;
    //                 l = max(l, l0);
    //                 break;
    //             }
    //         }
    //     }
    // }
    // dbg(l);

    // dbg(a);
    // for (int i = n - 1; i >= 0; i--) {
    //     if(p.count(s[i])) {
    //         ans = i;
    //         break;
    //     }
    // }
    // if(ans == 0) {
    //     cout << "0\n";
    //     return;
    // }
    // for (int i = 0; i < ans; i++) {
    //     if(p.count(s[i])) dup++;
    // }
    // dbg(dup, ans);
    // cout << ans - dup + !!(ans != dup) << '\n';

    // for (int i = 1; i < n; i++) {
    //     if(p.count(s[i])) {
    //         i++;
    //         for (int j = i + 1; j < n; j++, i++) {
    //             if(p.count(s[j])) {
    //                 ans = max(ans, j - i - 1);
    //                 i--;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // cout << ans << '\n';
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