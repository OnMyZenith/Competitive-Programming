/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if(count(s.begin(), s.end(), 'b') != count(t.begin(), t.end(), 'b') || count(s.begin(), s.end(), 'a') != count(t.begin(), t.end(), 'a')) {
        cout << "NO\n";
        return;
    }

    int _b = (int)count(s.begin(), s.end(), 'b');
    int _a = (int)count(s.begin(), s.end(), 'a');
    int _c = (int)count(s.begin(), s.end(), 'c');

    if (_b == 0) {
        cout << (s == t ? "YES" : "NO") << '\n';
        return;
    }


    vector<int> sab(_b), sbc(_b), sb_af_a(_a), sb_bef_c(_c);
    vector<int> tab(_b), tbc(_b), tb_af_a(_a), tb_bef_c(_c);

    for (int i = 0, sa = 0, sb = 0, tb = 0, ta = 0, j1 = 0, j2 = 0, j3 = 0, j4 = 0; i < n; i++) {
        if (s[i] == 'b') {
            sab[j1++] = sa;
        } else if (s[i] == 'a') sa++;

        if (s[i] == 'c') {
            sb_bef_c[j3++] = sb;
        } else if (s[i] == 'b') sb++;

        if (t[i] == 'c') {
            tb_bef_c[j4++] = tb;
        } else if (t[i] == 'b') tb++;

        if (t[i] == 'b') {
            tab[j2++] = ta;
        } else if (t[i] == 'a') ta++;
        // dbg(i, j1, j2);
    }

    // for (int i = n - 1, sc = 0, sb = 0, tb = 0, tc = 0, j1 = _b - 1, j2 = _b - 1, j3 = _a - 1, j4 = _a - 1; i >= 0; i--) {
    //     if (s[i] == 'b') {
    //         sbc[j1--] = sc;
    //     } else if (s[i] == 'c') sc++;

    //     if (s[i] == 'a') {
    //         sb_af_a[j3--] = sb;
    //     } else if (s[i] == 'b') sb++;

    //     if (t[i] == 'a') {
    //         tb_af_a[j4--] = tb;
    //     } else if (t[i] == 'b') tb++;

    //     if (t[i] == 'b') {
    //         tbc[j2--] = tc;
    //     } else if (t[i] == 'c') tc++;
    //     // dbg(i, j1, j2);
    // }
    string s1, t1;
    for (int i = 0; i < n; i++) {
        if(s[i] != 'b') {
            s1 += s[i];
        }
        if(t[i] != 'b') {
            t1 += t[i];
        }
    }

    bool pass = s1 == t1;
    for (int i = 0; i < _b; i++) {
        pass &= sab[i] >= tab[i];
        // pass &= sbc[i] >= tbc[i];
    }

    // for (int i = 0; i < _a; i++) {
    //     pass &= tb_af_a[i] <= sb_af_a[i];
    // }
    dbg(pass);

    for (int i = 0; i < _c; i++) {
        pass &= tb_bef_c[i] <= sb_bef_c[i];
    }

    // dbg(pass);
    cout << (pass ? "YES" : "NO") << '\n';
}

// void solve() {
//     int n; cin >> n;
//     string s, t; cin >> s >> t;
//     vector<bool> val(n, 1);
//     vector<int> posb, posa, posc;
//     for (int i = 0; i < n; i++) {
//         if(s[i] == 'a') posa.push_back(i);
//         else if(s[i] == 'b') posb.push_back(i);
//         else posc.push_back(i);
//     }
//     bool fail = 0;
//     for (int i = 0, j = 0, a = 0, b = 0, c = 0; i < n && j < n; j++) {
//         if(s[i] == t[j]) val[i++] = 0;
//         else if(t[j] == 'a') {
//             fail = 1;
//             break;
//         } else if(t[j] == 'b') {
//             if(b == (int)posb.size()) {
//                 fail = 1;
//                 break;
//             }

//             val[posb[b]] = 0;
//             b++;
//         } else {
//             if(a == (int)posa.size()) {
//                 fail = 1;
//                 break;
//             }
//             val[posa[a]] = 0;
//             a++;
//         } 
//     }
// }


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