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



int main() {
    vamos;

    int n; cin >> n;
    vector<int> exit_time(n);
    vector<int> a(n), b(n);
    for (auto &u : a) {
        cin >> u; u--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
        exit_time[b[i]] = i;
    }
    int ans = 0;
    set<int> seen;
    for (int i = 0, j = 0; i < n && j < n;)  {
        if(seen.count(a[i])) {i++; continue;}

        if(a[i] == b[j]) i++, j++;
        else ans++, seen.insert(b[j]), j++;
    }
    cout << ans << '\n';


    return 0;
}