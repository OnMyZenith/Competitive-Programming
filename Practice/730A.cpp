/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0, x; i < n; i++) {
        cin >> x; mp[-x].push_back(i);
    }
    vector<vector<int>> res;
    while ((int)mp.size() > 1) {
        auto v1 = *mp.begin();
        mp.erase(mp.begin());
        
        if ((int)v1.second.size() == 1) {
            auto v2 = *mp.begin();
            mp.erase(mp.begin());
            
            res.push_back({v1.second.back(), v2.second.back()});
            dbg(v1, v2);
            mp[min(0, v1.first + 1)].push_back(v1.second.back());
            mp[min(0, v2.first + 1)].push_back(v2.second.back());
            v2.second.pop_back();
            for (auto &e : v2.second) {
                mp[v2.first].push_back(e);
            }
        } else if ((int)v1.second.size() == 3) {
            res.push_back(v1.second);
            for (int i = 0; i < 3; i++) 
                mp[min(0, v1.first + 1)].push_back(v1.second[i]);
        } else {
            res.push_back({v1.second[(int)v1.second.size() - 1], v1.second[(int)v1.second.size() - 2]});
            mp[min(0, v1.first + 1)].push_back(v1.second[(int)v1.second.size() - 1]);
            mp[min(0, v1.first + 1)].push_back(v1.second[(int)v1.second.size() - 2]);
            v1.second.pop_back();
            v1.second.pop_back();
            if (!v1.second.empty()) mp[v1.first] = v1.second;
        }
        dbg(mp);
    }
    dbg(mp);
    dbg(res);
    assert((int)res.size() <= 1e4);
    cout << -(mp.begin()->first) << '\n';
    cout << (int)res.size() << '\n';
    for (auto &v : res) {
        string str(n, '0');
        for (auto &pos : v) {
            str[pos] = '1';
        }
        cout << str << '\n';
    }
    return 0;
}