/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// #ifndef asr_debug
// #pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
// #endif

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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


int disliked[500007];

mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); // mt19937 rng(61378913);
// e.g. shuffle(permutation.begin(), permutation.end(), rng);


int main(int argc, char **argv) {

#ifdef asr_time
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    int n; cin >> n;
    unordered_map<string, int> mp;
    unordered_map<int, string> find_by_id;
    vector<pair<vector<string>, vector<string>>> p(n);
    for (auto &[likes, dislikes] : p) {
        int x; cin >> x;
        likes.resize(x);
        for (auto &ing : likes) {
            cin >> ing;
            mp[ing];
        }
        cin >> x;
        dislikes.resize(x);
        for (auto &ing : dislikes) {
            cin >> ing;
            mp[ing];
        }
    }
    int tot_ing = 0;
    for (auto &[item, idx] : mp) {
        find_by_id[tot_ing] = item;
        idx = tot_ing++;
    }
    vector<pair<hash_set<int>, hash_set<int>>> per(n);

    for (int i = 0; i < n; i++) {
        auto &[likes, dislikes] = p[i];
        for (auto &ing : likes) {
            per[i].first.insert(mp[ing]);
        }
        for (auto &ing : dislikes) {
            per[i].second.insert(mp[ing]);
        }
    }
    // for (auto &P : per) {
    //     for (auto it = P.second.begin(); it != P.second.end(); it++){
    //         disliked[*it]++;
    //     }
    // }
    // vector<int> ING(tot_ing);
    // iota(ING.begin(), ING.end(), 0);
    // sort(ING.begin(), ING.end(), [&](int i, int j){return disliked[i] > disliked[j];});

    // auto like_ok = [&](int i, int per_id) ->bool{
    //     int tot = (int)per[per_id].first.size(), cnt = 0;
    //     for (int j = i; j < tot_ing; j++) {
    //         int ing = ING[j];
    //         if(per[per_id].first.find(ing) != per[per_id].first.end()) cnt++;
    //     }
    //     return cnt == tot;
    // };
    // auto dislike_ok = [&](int i, int per_id)->bool{
    //     for (int j = i; j < tot_ing; j++) {
    //         int ing = ING[j];
    //         if(per[per_id].second.find(ing) != per[per_id].second.end()) return false;
    //     }
    //     return true;
    // };
    // auto ok = [&](int i, int per_id) -> bool {
    //     return like_ok(i, per_id) && dislike_ok(i, per_id);
    // };

    // int best = 0, res = -1;
    // for (int i = 0; i < tot_ing; i++) {
    //     int cnt = 0;
    //     for (int j = 0; j < n; j++) {
    //         if(ok(i, j)) cnt++;
    //     }
    //     if(ckmax(best, cnt)) res = i;
    // }

    // cout << tot_ing - res << " ";
    // for (int j = res; j < tot_ing; j++) {
    //     int i = ING[j];
    //     cout << find_by_id[i] << " \n"[j == tot_ing - 1];
    // }

    //Rand code
    auto oneInsideTwo = [&](hash_set<int> &one, hash_set<int> &two) ->bool{
        for (auto &e : one) {
            if(two.find(e) == two.end()) return false;
        }
        return true;
    };

    auto oneOutsideTwo = [&](hash_set<int> &one, hash_set<int> &two) ->bool{
        for (auto &e : one) {
            if(two.find(e) != two.end()) return false;
        }
        return true;
    };

    auto sim = [&](hash_set<int> &ing) -> int {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += oneInsideTwo(per[i].first, ing) && oneOutsideTwo(per[i].second, ing);
        }
        return cnt;
    };

    vector<int> ING2(tot_ing);
    iota(ING2.begin(), ING2.end(), 0);
    hash_set<int> bs;
    int best = 0;
    for (int i = 0; i < 1e9; i++) {
        shuffle(ING2.begin(), ING2.end(), rng);
        ll c = (ll)rng() % (tot_ing + 1);
        hash_set<int> poss(ING2.begin(), ING2.begin() + c);
        if(ckmax(best, sim(poss))){
            bs = poss;
            freopen(argv[1], "w", stdout);
            cout << (int)bs.size() << " ";
            bool f = 0;
            for (auto &in : bs) {
                if(f) cout << " ";
                cout << find_by_id[in];
                f = 1;
            }
            cout << endl;
            fclose(stdout);
            dbg(best);
            dbg(poss);
        }
    }

    dbg(best);
    // cout << (int)bs.size() << " ";
    // bool f = 0;
    // for (auto &i : bs) {
    //     if(f) cout << " ";
    //     cout << find_by_id[i];
    //     f = 1;
    // }
    // cout << '\n';
    // //Rand code

#ifdef asr_time
    auto end = chrono::high_resolution_clock::now();
    cerr << setprecision(2) << fixed;
    cerr << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}