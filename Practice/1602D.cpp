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


int main() {
    vamos;

    int n; cin >> n;
    vector<int> height(n), slip(n), jumpPoints, potential(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        potential[i] = i + 1 - height[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> slip[i];
        jumpPoints.push_back(slip[i] + i + 1);
    }

    remDupf(jumpPoints);

    vector<int> idx(jumpPoints);
    sort(idx.begin(), idx.end(), [&](int i, int j) {return potential[i - 1] < potential[j - 1];});

    



    return 0;
}