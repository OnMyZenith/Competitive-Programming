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

// Check result >= lo
template <class T, class U> T lt(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<bool> pres(n + 1);
    hash_map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
        if(a[i] <= n) pres[a[i]] = 1;
    }

    int mex = lt(0, n, [&](int x){
        int rem = 0;
        for (auto &[num, f] : m) {
            if(num >= x) rem += f;
            else rem += f - 1;
        }
        int req = 0;
        for (int i = 0; i < x; i++) {
            if(!pres[i]) req++;
        }
        dbg(rem, req, x);
        return rem >= req && req <= k;
    });

    int req = 0;
    for (int i = 0; i < mex; i++) {
        if(!pres[i]) req++;
    }
    vector<int> filler;
    for (auto &[num, freq] : m) {
        if(num >= mex) {
            filler.push_back(freq);
        }
    }

    sort(filler.begin(), filler.end());

    int curr = 0;
    vector<int> fin;
    for (int i = 0; i < (int)filler.size(); i++) {
        curr += filler[i];
        if(curr >= req) {
            fin.assign(filler.begin() + i, filler.end());
            fin.front() = curr - req;
            break;
        }
    }

    int ans = (int)fin.size(), create_piles = k - req;

    for (int i = 0; i < (int)fin.size(); i++) {
        if(create_piles >= fin[i]) {
            ans--;
            create_piles -= fin[i];
        } else break;
    }
    dbg(fin, mex);
    cout << ans << '\n';
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