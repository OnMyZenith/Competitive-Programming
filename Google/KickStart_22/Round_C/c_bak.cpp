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
    int n, l; cin >> n >> l;
    vector<int> pos(n + 1), who(l + 1);
    vector<bool> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        who[pos[i]] = i;

        char c;
        cin >> c;
        d[i] = c == '1';
    }
    dbg(pos);
    cout << "Case #" << _TC << ": ";
    int alive = n;
    vector<bool> dead(n + 1);
    auto sim = [&]() -> int{
        vector<int> deadsec;
        for (int i = 1; i <= n; i++) {
            if(dead[i]) continue;
            int prevpos = pos[i];
            if(d[i]) {
                if(who[pos[i] + 1] && d[who[pos[i] + 1]] == 0) {
                    d[who[pos[i] + 1]] = 1;
                    d[i] = 0;
                    pos[i]--;
                } else {
                    pos[i]++;
                }
            } else {
                if(who[pos[i] - 1] && d[who[pos[i] - 1]] == 1) {
                    d[who[pos[i] - 1]] = 0;
                    d[i] = 1;
                    pos[i]++;
                } else {
                    pos[i]--;
                }
            }
            if(pos[i] == 0 || pos[i] == l) {
                dead[i] = 1;
                deadsec.push_back(i);
            } else who[pos[i]] = i;
            who[prevpos] = 0;
        }
        int m = (int)deadsec.size();
        if(!m) return 0;
        sort(deadsec.begin(), deadsec.end());
        for (int i = 0; i < m; i++) {
            cout << deadsec[i];
            if(i == m - 1 && alive == m) cout << '\n';
            else cout << " ";
        }
        return m;
    };


    while(alive) {
        alive -= sim();
    }



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