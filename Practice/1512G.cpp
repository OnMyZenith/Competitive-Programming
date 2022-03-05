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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

vector<int> trial_division3(int n) {
    vector<int> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (int d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}


int mp[(int)1e7 + 1];

void solve() {
    int n; cin >> n;
    vector<int> f = trial_division3(n);
    sort(f.begin(), f.end());
    vector<pair<int,int>> pfn;
    for (int i = 0; i < (int)f.size(); i++) {
        int cnt = 0, curr = f[i];
        while(i < (int)f.size() && f[i] == curr) i++;
        pfn.push_back({curr, cnt});
    }
    



}

int main() {
    vamos;
#ifdef asr_time
    auto begin = chrono::high_resolution_clock::now();
#endif


    int n = 1e7;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    memset(mp, -1, sizeof(mp));
    mp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if(!is_prime[i]) continue;
        ll x = i;
        while(x <= n) {
            if(mp[(x - 1) / (i - 1)] == -1) mp[(x - 1) / (i - 1)] = 1e9;
            ckmin(mp[(x - 1) / (i - 1)], i);
            x *= i;
        }
    }

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

#ifdef asr_time
    auto end = chrono::high_resolution_clock::now();
    cerr << setprecision(2) << fixed;
    cerr << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}