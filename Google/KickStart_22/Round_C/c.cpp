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

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;



void solve(int _TC) {
    int n, l; cin >> n >> l;
    vector<int> pos(n);
    vector<bool> d(n);
    hash_map<int, int> who_here;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
        pos[i];
        who_here[pos[i]] = i;
        char c;
        cin >> c;
        d[i] = c == '1';
    }
    // dbg(pos);
    cout << "Case #" << _TC << ": ";

    vector<int> rfall(n); iota(rfall.begin(), rfall.end(), 0);
    sort(rfall.begin(), rfall.end(), [&](int i, int j){
        return pos[i] > pos[j];
    });
    auto lfall = rfall;
    sort(lfall.begin(), lfall.end(), [&](int i, int j){
        return pos[i] < pos[j];
    });


    vector<pair<int, int>> all;
    for (auto &[len, ant] : who_here) {
        bool _r = d[ant];
        if(_r) all.push_back({l - len, 1});
        else all.push_back({len, 0});
    }
    sort(all.begin(), all.end());

    assert((int)all.size() == n);

    reverse(rfall.begin(), rfall.end());
    reverse(lfall.begin(), lfall.end());
    dbg(rfall);
    dbg(lfall);
    dbg(all);
    set<int> ded;
    for (int i = 0; i < n; i++) {
        int e = i;
        for (int j = i; j < n && all[j].first == all[i].first; j++) {
            e = j;
        }
        dbg(i, e);
        vector<int> res;
        for (int j = i; j <= e; j++) {
            int poss = -1;
            int ri = all[j].second;
            int _d = (int)ded.size();
            if(ri) {
                while(_d == (int)ded.size()) {
                    poss = rfall.back();
                    rfall.pop_back();
                    ded.insert(poss);
                }
            } else {
                while(_d == (int)ded.size()) {
                    poss = lfall.back();
                    lfall.pop_back();
                    ded.insert(poss);
                }
            }
            res.push_back(poss + 1);
        }
        int m = (int)res.size();
        sort(res.begin(), res.end());
        for (int j = 0; j < m; j++) {
            cout << res[j] << " \n"[(int)ded.size() == n && j == m - 1];
        }
        i = e;
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