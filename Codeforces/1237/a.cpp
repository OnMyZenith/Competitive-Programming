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

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

template <class T> T fdivf(T &a, T b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T> T cdivf(T &a, T b) { return a / b + ((a ^ b) > 0 && a % b); }


int main() {
    vamos;

    int n;
    cin >> n; 
    vector<int> a(n);
    bool f = 1;
    for (auto &u : a) {
        cin >> u;
        if(!(u & 1)) {u /= 2; continue;}

        if(f) u = fdivf(u, 2);
        else u = cdivf(u, 2);
        f = !f;
    }

    ov(a);


    return 0;
}