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
    vector<vector<pair<string, int>>> allsame(26);
    vector<pair<char, char>> be(n);
    vector<bool> allsamebool(n);
    vector<int> totcnt(26);
    vector<vector<int>> cntinword(n, vector<int>(26));
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int j = 0; j < n; j++)  {
        auto &u = v[j];
        for (auto &ch : u) {
            totcnt[ch - 'A']++;
            cntinword[j][ch - 'A']++;
        }
        if(count(u.begin(), u.end(), u.front()) == (int)u.size()) {
            allsame[u.front() - 'A'].push_back({u, j});
            allsamebool[j] = 1;
        }
        vector<int> c(26);
        for (int i = 0; i < (int)u.size(); i++)  {
            if(c[u[i] - 'A'] == 0 || u[i - 1] == u[i]) c[u[i] - 'A']++;
            else {
                cout << "Case #" << _TC << ": " << "IMPOSSIBLE\n";
                return;
            }
        }
        be[j].first = u.front();
        be[j].second = u.back();
    }

    vector<bool> taken(n);
    string res;
    vector<string> gp(26);
    vector<int> beg(26, -1);
    vector<int> end(26, -1);
    bool fail = 0;
    for (int i = 0; i < n; i++) {
        if(!allsamebool[i]) {
            if(end[v[i].back() - 'A'] != -1) fail = 1;
            if(beg[v[i].front() - 'A'] != -1) fail = 1;
            end[v[i].back() - 'A'] = i;
            beg[v[i].front() - 'A'] = i;
        } else {
            gp[v[i].front() - 'A'] += v[i];
            taken[i] = 1;
        }
    }
    vector<bool> seen(26);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)v[i].size(); j++)  {
            auto &ch = v[i][j];
            if(ch != be[i].first && ch != be[i].second) {
                if(!seen[ch - 'A'] || v[i][j - 1] == ch) {
                    seen[ch - 'A'] = 1;
                } else fail = 1;
            }
        }
    }
    if(fail) {
        cout << "Case #" << _TC << ": " << "IMPOSSIBLE\n";
        return;
    }

    res.clear();
    vector<bool> gpused(26);
    for (int i = 0; i < 26; i++) {
        if(beg[i] != -1 && end[i] == -1) {
            char c = v[beg[i]].back();
            if(!gpused[i]) res += gp[c - 'A'];
            gpused[c - 'A'] = 1;
            if(!gpused[c - 'A']) res += v[beg[i]];
            taken[beg[i]] = 1;
            while((int)res.size() != accumulate(totcnt.begin(), totcnt.end(), 0)) {
                c = res.back();
                res += gp[c - 'A'];
                gpused[c - 'A'] = 1;
                if(beg[c - 'A'] != -1) res += v[beg[c - 'A']], taken[beg[c - 'A']] = 1;
            }
            break;
        }
    }



    if(res.empty()) {
        for (int i = 0; i < 26; i++) {
            if(beg[i] == -1 && end[i] == -1) {
                // char c = v[beg[i]].front();
                if(!gpused[i]) res += gp[i];
                gpused[i] = 1;
                // res += v[beg[i]];

                while((int)res.size() != accumulate(totcnt.begin(), totcnt.end(), 0)) {
                    int curr = (int)res.size();
                    char c = res.back();
                    if(!gpused[c - 'A']) res += gp[c - 'A'];
                    gpused[c - 'A'] = 1;
                    if(beg[c - 'A'] != -1) res += v[beg[c - 'A']], taken[beg[c - 'A']] = 1;
                    if((int)res.size() == curr) {
                        for (int k = 0; k < 26; k++) if(gp[k].size() && !gpused[k]) {
                            res += gp[k];
                            gpused[k] = 1;
                            break;
                        }
                    }
                }
                break;
            }
        }

    }






    // for (int i = 0; i < n; i++) {
    //     res.clear();
    //     vector<int> currcnt(26);
    //     vector<bool> taken(n);
    //     res += v[i];
    //     int done = 1;
    //     for (int k = 0; k < 26; k++) currcnt[k] += cntinword[i][k];
    //     taken[i] = 1;
    //     for (auto &[s, id] : allsame[res.back() - 'A']) {
    //         if(!taken[id]) {
    //             taken[id] = 1;
    //             done++;
    //             for (int k = 0; k < 26; k++) currcnt[k] += cntinword[id][k];
    //             res += s;
    //         }
    //     }
    //     bool did = 1;
    //     while(done != n && did) {
    //         did = 0;
    //         for (int j = 0; j < n; j++) {
    //             if(taken[j] == 0 && (res.back() == be[j].first || currcnt[res.back() - 'A'] == totcnt[res.back() - 'A'])) {
    //                 if(currcnt[be[j].first - 'A'] && res.back() != be[j].first) continue;
    //                 res += v[j];
    //                 for (int k = 0; k < 26; k++) currcnt[k] += cntinword[j][k];
    //                 taken[j] = 1;
    //                 done++;
    //                 for (auto &[s, id] : allsame[res.back() - 'A']) {
    //                     if(!taken[id]) {
    //                         taken[id] = 1;
    //                         done++;
    //                         for (int k = 0; k < 26; k++) currcnt[k] += cntinword[id][k];
    //                         res += s;
    //                     }
    //                 }
    //                 did = 1;
    //                 break;
    //             }
    //         }
    //     }
    //     if(done == n) {
    //         cout << "Case #" << _TC << ": ";
    //         cout << res << '\n';
    //         return;
    //     }

    // }
    // vector<bool> taken(n);
    // vector<bool> tried(n);
    // int done = 0;
    // for (int i = 0; i < n; i++) {
    //     if(tried[i]) continue;
        
    //     vector<int> currcnt(26);
    //     fill(taken.begin(), taken.end() , 0);
    //     if(cntinword[i][v[i].front() - 'A'] == totcnt[v[i].front() - 'A'] || allsamebool[i]) {
    //         tried[i] = 1;
    //         res.clear();
    //         res += v[i];
    //         for (int k = 0; k < 26; k++) currcnt[k] += cntinword[i][k];
    //         taken[i] = 1;
    //         done = 1;
    //         bool did = 1;
    //         while(done != n && did) {
    //             did = 0;
    //             if(currcnt[res.back() - 'A'] == totcnt[res.back() - 'A']) {
    //                 for (int j = 0; j < n; j++) {
    //                     if(!taken[j]) {
    //                         if(cntinword[i][v[i].front() - 'A'] == totcnt[v[i].front() - 'A'] || allsamebool[i]) {

    //                         }

    //                         did = 1;
    //                     }
    //                 }
    //             }
    //         }
    //         if(done == n) break;
    //     }

    // }








    cout << "Case #" << _TC << ": " << res << "\n";

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