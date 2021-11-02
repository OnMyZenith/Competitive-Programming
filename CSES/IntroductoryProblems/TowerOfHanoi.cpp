#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt_prev = 1, cnt_next = 1;
    vector<pair<int, int>> prev = {(make_pair(1, 3))}, next = {(make_pair(1, 3))};
    for (int i = 2; i <= n; i++) {
        cnt_next = 2 * cnt_prev + 1;
        cnt_prev = cnt_next;
        next.clear();
        for (size_t j = 0; j < prev.size(); j++) {
            pair<int, int> tmp = prev[j];
            if (tmp.first == 2) tmp.first = 3;
            else if (tmp.first == 3)
                tmp.first = 2;
            if (tmp.second == 2) tmp.second = 3;
            else if (tmp.second == 3)
                tmp.second = 2;
            next.push_back(tmp);
        }
        next.push_back(make_pair(1, 3));
        for (size_t j = 0; j < prev.size(); j++) {
            pair<int, int> tmp = prev[j];
            if (tmp.first == 2) tmp.first = 1;
            else if (tmp.first == 1)
                tmp.first = 2;
            if (tmp.second == 2) tmp.second = 1;
            else if (tmp.second == 1)
                tmp.second = 2;
            next.push_back(tmp);
        }
        prev = next;
    }
    cout << cnt_next << '\n';
    for (auto i : next)
        cout << i.first << " " << i.second << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}