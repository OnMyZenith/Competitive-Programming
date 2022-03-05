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

template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    hash_map<int,int> mp;
    pqinc<pair<int,int>> pq;
    for (auto &u : a) {
        cin >> u;
        mp[u]++;
    }
    int m = (int) mp.size();
    for (auto [ele, freq] : mp) {
        pq.push({freq, ele});
    }
    for (int i = 1; i <= n; i++) {
        cout << max(m, i) << " \n"[i == n];
        // auto [freq, ele] = pq.top();
        // pq.pop();
        // if(freq == 1){
        //     cout << m << " \n"[i == n];
        // } else {
        //     cout << m++ << " \n"[i == n];
        //     pq.push({freq - 1, ele});
        // }
    }
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