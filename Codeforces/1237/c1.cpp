/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// #ifndef asr_debug
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

struct point{
    int x, y, z;
};

long double dist(point &a, point &b) {
    long double d = sqrt((long double) (a.x - b.x) * (a.x - b.x) + (long double) (a.y - b.y) * (a.y - b.y) + (long double) (a.z - b.z) * (a.z - b.z));
    return d;
}

int main() {
    vamos;

    int n; cin >> n;
    vector<point> points(n);
    for (auto &[x, y, z] : points) {
        cin >> x >> y >> z;
    }
    vector<bool> gone(n);
    for (int i = 0; i < n; i++) {
        if(gone[i]) continue;
        long double dis = 1e9; int p = -1;
        for (int j = 0; j < n; j++) {
            if(gone[j] || j == i) continue;
            if(ckmin(dis, dist(points[i], points[j]))){
                p = j;
            }
        }
        cout << i + 1 << " " << p + 1 << '\n';
        gone[i] = 1;
        gone[p] = 1;
    }

    return 0;
}