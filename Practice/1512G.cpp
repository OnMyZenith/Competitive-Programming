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

int sum_of_div[(int)1e7 + 7];
int fin[(int)1e7 + 7];
int fact[(int)1e7 + 7];

int main() {
    vamos;

    int n_max = 1e7 + 1;

    fact[1] = 1;
    for (int i = 4; i < n_max; i += 2) fact[i] = 2;
    for (int i = 3; i * i < n_max; i += 2) {
        if(!fact[i]) {
            for (int j = i * i; j < n_max; j += 2 * i) {
                fact[j] = i;
            }
        }
    }
    sum_of_div[1] = 1;
    for (int i = 2; i < n_max; i++) {
        if(!fact[i]) {
            sum_of_div[i] = i + 1;
        } else {
            int j = i;
            while(j % fact[i] == 0) j /= fact[i];

            sum_of_div[i] = sum_of_div[i / fact[i]] + sum_of_div[j] * (i / j);
        }
    }

    for (int i = 0; i < n_max; i++) {
        if(sum_of_div[i] > 1e7) continue;
        if(!fin[sum_of_div[i]]) fin[sum_of_div[i]] = i;
    }

    int TT = 1;
    cin >> TT;
    while(TT--) {
        int c; cin >> c;
        cout << (fin[c] ? fin[c] : -1) << '\n';
    }

    return 0;
}