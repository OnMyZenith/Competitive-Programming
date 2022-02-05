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

const int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1}; // URDL
const char dir[4] = {'U', 'R', 'D', 'L'};
inline int moveIdx(char c){
    for (int i = 0; i < 4; i++) {
        if(dir[i] == c) return i;
    }
    return -1;
}


void solve() {
    string s; cin >> s;
    pair<int,int> obs = {1e9,1e9};
    auto next = [&](pair<int,int> v, char c)->pair<int,int>{
        int i = moveIdx(c);
        pair<int,int> u = {v.first + dx[i], v.second + dy[i]};
        if (u == obs) return v;
        return u;
    };

    set<pair<int,int>> path;
    pair<int,int> v = {0, 0}, block = {0, 0};
    for (auto &u : s) {
        v = next(v, u);
        path.insert({v});
    }
    for (auto &p : path) {
        obs = p; v = {0,0};
        for (auto &u : s) {
            v = next(v, u);
        }
        if(v == make_pair(0,0)) {block = p; break;}
    }
    cout << block.first << " " << block.second << '\n';
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