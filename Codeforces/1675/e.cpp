/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

#include <bits/extc++.h>
using namespace __gnu_pbds;

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

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(26);
    vector<int> pos(26, 1e9);
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        ckmin(pos[s[i] - 'a'], i);
    }
    auto less_than = [&](string &s1, string &s2) -> bool {
        for (int i = 0; i < n; i++) {
            if(s1[i] > s2[i]) return false;
            else if(s1[i] < s2[i]) return true;
        }
        return false;
    };
    vector<int> priority(26, 1e9);
    for (int i = 0; i < 26; i++) {
        ckmin(priority[i], pos[i]);
    }
    vector<int> id(26);
    iota(id.begin(), id.end(), 0);
    string ans = s;
    auto _id = id;
    for (int take = 0; take <= 25; take++) {
        int K = min(k, 25);
        id = _id;
        int c = -1, _mx = 1e9;
        for (int i = take + 1; i < 26; i++) {
            if (ckmin(_mx, priority[i])) c = i;
        }
        if (take > K) continue;
        for (int i = 1; i <= take; i++) {
            id[i] = 0;
        }
        K -= take;
        if(c == -1) continue;
        for (int i = max(c - K, 0) + 1; i <= c; i++) {
            id[i] = id[max(c - K, 0)];
        }

        string _s = s;
        for (auto &c : _s) {
            c = char(id[c - 'a'] + 'a');
        }
        if(less_than(_s, ans)) ans = _s;
    }
    cout << ans << '\n';
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