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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> idx(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
    }
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i]--;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++)
        idx[a[i]].push_back(i);

    if (a.front() != b.front()) {
        cout << "NO\n";
        return;
    }
    vector<int> usable(n);
    for (int i = 0; i < n; i++)
        usable[i] = (int)idx[i].size();

    multiset<int> pulled_back;
    dbg(a);
    dbg(b);
    for (int i = 1, j = 1; i < n && j < n;) {
        // dbg(i, j);
        // auto it = pulled_back.find(a[i]);
        // if (it != pulled_back.end()) {
        //     // usable[a[i]]--;
        //     pulled_back.erase(it), i++;
        //     continue;
        // }
        // dbg(i, j);
        if (a[i] != b[j]) {
            if (a[i - 1] == b[j] && usable[a[i - 1]] > 0) {
                j++;
                usable[a[i - 1]]--;
                pulled_back.insert(a[i - 1]);
                continue;
            }
            auto it = pulled_back.find(a[i]);
            if (it != pulled_back.end()) {
                // usable[a[i]]--;
                pulled_back.erase(it), i++;
                continue;
            } else {
                dbg(a[i], b[j], i, j);
                cout << "NO\n";
                return;
            }
        } else
            usable[a[i]]--, i++, j++;
    }
    cout << "YES\n";
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}