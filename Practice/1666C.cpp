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

struct point{
    int x, y;
    bool operator<(point & p){
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
};

int main() {
    vamos;

    vector<point> p(3);
    
    for (int i = 0; i < 3; i++) cin >> p[i].x >> p[i].y;
    sort(p.begin(), p.end());

    cout << "3\n";

    if(abs(p[1].y - p[0].y) + abs(p[1].y - p[2].y) == abs(p[0].y - p[2].y)) {
        dbg("2");
        cout << p[0].x << " " << p[0].y << " " << p[0].x << " " << p[1].y << '\n';
        cout << p[0].x << " " << p[1].y << " " << p[2].x << " " << p[1].y << '\n';
        cout << p[2].x << " " << p[2].y << " " << p[2].x << " " << p[1].y << '\n';
    } else if (abs(p[2].y - p[0].y) + abs(p[2].y - p[1].y) == abs(p[0].y - p[1].y)) {
        dbg("3");
        cout << p[0].x << " " << p[0].y << " " << p[0].x << " " << p[2].y << '\n';
        cout << p[0].x << " " << p[2].y << " " << p[2].x << " " << p[2].y << '\n';
        cout << p[1].x << " " << p[1].y << " " << p[1].x << " " << p[2].y << '\n';
    } else {
        dbg("1");
        cout << p[1].x << " " << p[1].y << " " << p[1].x << " " << p[0].y << '\n';
        cout << p[2].x << " " << p[0].y << " " << p[0].x << " " << p[0].y << '\n';
        cout << p[2].x << " " << p[2].y << " " << p[2].x << " " << p[0].y << '\n';
    }


    return 0;
}