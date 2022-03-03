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


template <class T> void remDupf(vector<T> &v) { sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), end(v)); }

vector<int> allDivisors(int n)
{
    // Vector to store half of the divisors
    vector<int> v; v.reserve((int)sqrt(n) + 1);
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
 
            // check if divisors are equal
            if (n / i == i)
                v.emplace_back(i);
                // printf("%d ", i);
            else {
                v.emplace_back(i);
                // printf("%d ", i);
 
                // push the second divisor in the vector
                v.emplace_back(n / i);
            }
        }
    }
 
    // The vector will be printed in reverse
    // for (int i = v.size() - 1; i >= 0; i--)
    //     printf("%d ", v[i]);
    return v;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<bool> pres(n + 1);
    for (auto &u : a) {
        cin >> u;
    }
    remDupf(a);
    if((int)a.size() < n) {
        cout << "NO\n"; return;
    }

    int have = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] > n && !have) {
            have = a[i];
        } else if(a[i] <= n) pres[a[i]] = 1;
    }

    if(count(pres.begin(), pres.end(), true) == n) {
        cout << "YES " << n + 1 << '\n';
        return; 
    }

    auto sol = [&](int m) -> bool {
        if(m <= n) return false;
        vector<bool> pres2(n + 1);
        for (int i = 0; i < n; i++) {
            int v = a[i];
            if(v > n) v %= m;

            if(v > n || !v || pres2[v]) return false;

            pres2[v] = 1;
        }
        return true;
    };

    for (int i = 1; i <= n; i++) {
        if(!pres[i]) {
            int m = have - i;
            vector<int> all = allDivisors(m);
            for (auto &one : all) {
                if(sol(one)) {
                    cout << "YES " << one << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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