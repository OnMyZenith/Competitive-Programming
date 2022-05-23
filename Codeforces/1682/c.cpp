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



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    hash_map<int, int> f;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    // vector<int> one, both;
    int one = 0, both = 0;
    for (auto &[e, fr] : f) {
        if(fr >= 2) {
            // both.push_back(e);
            both++;
        } else {
            // one.push_back(e);
            one++;
        }
    }

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    if(!one) both--;
    else one--;

    cout << (both * 2 + one) / 2 + 1 << '\n';


    // sort(both.begin(), both.end());
    // sort(one.begin(), one.end());


    // if(both.empty() || one.empty()) {
    //     if(both.empty()) one.pop_back();
    //     else both.pop_back();
    //     cout << (int)one.size() / 2 + (int)both.size() + 1 << '\n';
    //     return;
    // }

    // int h = 1;
    // bool bal = 1;
    // if(!both.empty() && !one.empty()) {
    //     if(both.back() > one.back()) both.pop_back();
    //     else one.pop_back();
    // }

    // while(!both.empty() && !one.empty()) {
    //     if(both.back() > one.back()) {
    //         both.pop_back();
    //         h++;
    //     }
    //     else {
    //         one.pop_back();
    //         bal = !bal;
    //         h += bal;
    //     }
    // }

    // h += ((int)one.size() + !bal) / 2 + (int)both.size();

    // cout << h << '\n';
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