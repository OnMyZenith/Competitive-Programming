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
    string s; cin >> s;
    sort(s.begin(), s.end());
    int n = (int)s.size();
    vector<int> f(26);
    for (auto &c : s) {
        f[c - 'a']++;
    }
    int cnt = !!f[0], consecutive = 0;
    for (int i = 0; i < 25; i++) {
        cnt += !!f[i + 1];
        consecutive += f[i + 1] && f[i];
    }
    if (cnt == 1) {
        cout << s << '\n';
        return;
    }
    if (consecutive == cnt - 1 && cnt <= 3) {
        cout << "No answer\n";
        return;
    }
    vector<char> take;
    for (int i = 0; i < 26; i++) if (f[i]) take.push_back(char(i + 'a'));

    string res; int m = (int)take.size();
    dbg(take);
    for (int i = 0; i + (m + 1) / 2 < m; i++) {
        res += string(f[take[i + (m + 1) / 2] - 'a'], take[i + (m + 1) / 2]);
        res += string(f[take[i] - 'a'], take[i]);
    }
    if (m & 1) {
        if (abs(res.back() - take[m / 2]) != 1) res += string(f[take[m / 2] - 'a'], take[m / 2]);
        else if (abs(res.front() - take[m / 2]) != 1) res = string(f[take[m / 2] - 'a'], take[m / 2]) + res;
        else {
            for (int i = 0; i < (int)res.size() - 1; i++) {
                if (abs(res[i] - take[m / 2]) != 1 && abs(res[i + 1] - take[m / 2]) != 1) {
                    cout << res.substr(0, i + 1) + string(f[take[m / 2] - 'a'], take[m / 2]) + res.substr(i + 1) << '\n';
                    return;
                }
            }
        }
    }
    assert((int)res.size() == n);
    cout << res << '\n';
}

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