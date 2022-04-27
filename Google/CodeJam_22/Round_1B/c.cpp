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

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);

vector<vector<int>> all(8);

void f(int x) {
    string s = "00000000";
    for (int i = 0; i < 30; i++)
        if ((x >> i) & 1) s[i] = '1';
    cout << s << endl;
}

void solve(int _TC) {
    int n;
    cout << "00000000" << endl;
    cin >> n;

    while ((n != 8) && (n != 0)) {
        int x = all[n][rand(0, (int)all[n].size() - 1)];
        f(x);
        cin >> n;
        if (n == -1) exit(0);
    }
    if (n == 8) {
        cout << "11111111" << endl;
        cin >> n;
        assert(!n);
    }
}

int main() {
    vamos;

    for (int i = 1; i < (1 << 8) - 1; i++) {
        all[pct(i)].push_back(i);
    }

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}