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


int dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    vamos;

    int x[3], y[3];
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
    int best = 0; pair<int, int> extremes; int m;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(i == j) continue;
            if(ckmax(best, dis(x[i], y[i], x[j], y[j]))) {
                extremes = {i, j};
                m = 3 - i - j;
            }
        }
    }

    cout << "4\n";

    cout << x[extremes.first] << " " << y[extremes.first] << " " << x[extremes.first] << " " << y[m] << '\n';
    cout << x[m] << " " << y[m] << " " << x[extremes.first] << " " << y[m] << '\n';

    cout << x[extremes.second] << " " << y[extremes.second] << " " << x[extremes.second] << " " << y[m] << '\n';
    cout << x[m] << " " << y[m] << " " << x[extremes.second] << " " << y[m] << '\n';

    return 0;
}