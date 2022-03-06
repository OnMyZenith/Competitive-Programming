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
    int x, y, z, id;
};

long double dist(point &a, point &b) {
    long double d = sqrt((long double) (a.x - b.x) * (a.x - b.x) + (long double) (a.y - b.y) * (a.y - b.y) + (long double) (a.z - b.z) * (a.z - b.z));
    return d;
}

int main() {
    vamos;

    int n; cin >> n;
    vector<point> points(n);
    int cnt = 1;
    for (auto &[x, y, z, id] : points) {
        cin >> x >> y >> z; id = cnt++;
    }
    sort(points.begin(), points.end(), [&](point &a, point &b){
        return a.x < b.x;
    });
    vector<int> to_rem(n);
    vector<vector<point>> points_same_x;
    for (int i = 0; i < n;) {
        point a = points[i++];
        to_rem[i - 1] = 1;
        vector<point> tmp = {a};
        while(i < n && points[i].x == a.x) tmp.push_back(points[i]), to_rem[i++] = 1;
        if((int)tmp.size() > 1) points_same_x.push_back(tmp);
        else to_rem[i - 1] = 0;
    }
    vector<point> points_diff_x;
    for (int i = 0; i < n; i++) {
        if(!to_rem[i]) points_diff_x.push_back(points[i]);
    }
    for (auto &gp : points_same_x) {
        sort(gp.begin(), gp.end(), [&](point &a, point &b){
            if(a.y != b.y) return a.y < b.y;
            return a.z < b.z;
        });
        for (auto &[x, y, z, id] : gp) {
            dbg(x,y,z);
            // cout << x << " " << y << " " << z << '\n';
        }
        cnt = (int)gp.size();
        for (int i = 0; i < (int)gp.size() - 1; i += 2) {
            cout << gp[i].id << " " << gp[i + 1].id << '\n';
            cnt -= 2;
        }
        if(cnt) points_diff_x.push_back(gp.back());
    }
    sort(points_diff_x.begin(), points_diff_x.end(), [&](point &a, point &b){
        return a.x < b.x;
    });
    for (int i = 0; i < (int)points_diff_x.size() - 1; i += 2) {
        cout << points_diff_x[i].id << " " << points_diff_x[i + 1].id << '\n';
    }
    return 0;
}