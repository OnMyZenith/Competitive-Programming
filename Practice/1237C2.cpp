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

struct point {
    int x, y, z, id;
    bool operator<(point &other) {
        return vector<int>{x, y, z} < vector<int>{other.x, other.y, other.z};
    }
    bool same_x(point &other) const {
        return x == other.x;
    }
    bool same_xy(point &other) const {
        return x == other.x && y == other.y;
    }
};

int main() {
    vamos;

    int n; cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        auto &[x, y, z, id] = points[i];
        cin >> x >> y >> z; id = i;
    }
    sort(points.begin(), points.end());
    vector<bool> gone(n);
    for (int i = 0; i < n - 1; i++) {
        if (points[i].same_xy(points[i + 1])) {
            cout << points[i].id + 1 << " " << points[i + 1].id + 1 << '\n';
            gone[i] = gone[i + 1] = 1; i++;
        }
    }
    for (int i = 0; i < n - 1;) {
        if (gone[i]) { i++; continue; }
        int j = i + 1; while (gone[j]) j++;
        if (points[i].same_x(points[j])) {
            cout << points[i].id + 1 << " " << points[j].id + 1 << '\n';
            gone[i] = gone[j] = 1; i = j + 1;
        } else i++;
    }
    for (int i = 0; i < n - 1;) {
        if (gone[i]) { i++; continue; }
        int j = i + 1; while (gone[j]) j++;
        cout << points[i].id + 1 << " " << points[j].id + 1 << '\n';
        gone[i] = gone[j] = 1; i = j + 1;
    }
    return 0;
}