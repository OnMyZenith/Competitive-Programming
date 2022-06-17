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
    vector<int> height(n), slip(n), potential(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        potential[i] = i - height[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> slip[i];
    }

    queue<int> q, q1; q.push(n - 1);
    int curr_enqueued = n - 1, cnt = 0;
    vector<int> p(n);
    p[n - 1] = -1; int l = -1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if(v < 0) break;

        int real_v = v + slip[v];
        for (int i = min(real_v - 1, curr_enqueued - 1); i >= potential[real_v]; i--) {
            q1.push(i); (i >= 0 ? p[i] = v : l = v); curr_enqueued = min(curr_enqueued, i);
        }

        if(q.empty()) cnt++, swap(q1, q);
    }
    if (curr_enqueued >= 0) {
        cout << "-1\n";
    } else {
        cout << cnt << '\n';
        vector<int> path = {-1};
        while (p[l] != -1) path.push_back(l), l = p[l];
        reverse(path.begin(), path.end());
        for (int i = 0; i < (int)path.size(); i++) cout << path[i] + 1 << " \n"[i == (int)path.size() - 1];
    }
    return 0;
}