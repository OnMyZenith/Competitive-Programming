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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    for (auto &u : b) {
        cin >> u;
    }

    int maxa = *max_element(a.begin(), a.end());
    int maxb = *max_element(b.begin(), b.end());

    if(maxa == maxb) {
        cout << "Alice\nBob\n";
        return;
    } else if(maxa > maxb) {
        cout << "Alice\nAlice\n";
        return;
    } else {
        cout << "Bob\nBob\n";
        return;
    }


//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     dbg(a, b);
//     bool al = 0;
//     int i = int(lower_bound(a.begin(), a.end(), b[0]) - a.begin()), j = 0;
//     while(1) {
//         if(al) {
//             while(i < n && a[i] <= b[j]) i++;
//             if(i == n) {
//                 cout << "Bob\n";
//                 goto next;
//             }
//             al = 0;
//         } else {
//             while(j < m && b[j] <= a[i]) j++;
//             if(j == m) {
//                 cout << "Alice\n";
//                 goto next;
//             }
//             al = 1;
//         }
//     }
// next:
//     al = 1;
//     i = 0, j = int(lower_bound(b.begin(), b.end(), a[0]) - b.begin());
//     while(1) {
//         if(al) {
//             while(i < n && a[i] <= b[j]) i++;
//             if(i == n) {
//                 cout << "Bob\n";
//                 return;
//             }
//             al = 0;
//         } else {
//             while(j < m && b[j] <= a[i]) j++;
//             if(j == m) {
//                 cout << "Alice\n";
//                 return;
//             }
//             al = 1;
//         }
//     }
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