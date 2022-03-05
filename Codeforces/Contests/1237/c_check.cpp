#include "home.hpp"

struct point{
    int x, y, z, id;
};

int main() {
    vamos;

    int n; cin >> n;
    vector<point> points(n);
    int cnt = 1;
    for (auto &[x, y, z, id] : points) {
        cin >> x >> y >> z; id = cnt++;
    }
    vector<bool> gone(n);
    auto clr = [&](int id1, int id2) -> bool {
        for (int i = 0; i < n; i++) {
            if(points[id1 - 1].id - 1 == i || points[id2 - 1].id - 1 == i || gone[i]) continue;
            point a = points[id1 - 1];
            point b = points[id2 - 1];
            point c = points[i];
            if(min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y) && min(a.z, b.z) <= c.z && c.z <= max(a.z, b.z)) return false;
        }
        return true;
    };
    for (int i = 0; i < n / 2; i++) {
        int id1, id2; cin >> id1 >> id2;
        if(!clr(id1, id2)) return -1;
        gone[id1 -1] = gone[id2 - 1] = 1;
    }
    return 0;
}