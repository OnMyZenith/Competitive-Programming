#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    ll mex = n;
    for (int i = 0; i <= n; i++)
        if (s.find(i) == s.end()) {
            mex = i;
            break;
        }

    map<int, queue<int>> pos;
    for (int i = 0; i < n; i++)
        pos[a[i]].push(i);

    ll l = 0, h = mex;
    while (l < h) {
        ll eff = 0;
        ll mid = (l + h) / 2;
        vector<pair<int, int>> bases;
        map<int, queue<int>> pos_tmp(pos);
        bool basesRemain = true;
        while (basesRemain) {
            int lft = -1, rght = -1, leftmost;
            for (int i = 0; i <= mid; i++) {
                if (pos_tmp[i].empty()) {
                    basesRemain = false;
                    break;
                }
                int first_occ_of_i = pos_tmp[i].front();
                if (lft == -1) {
                    lft = first_occ_of_i;
                    leftmost = i;
                    rght = first_occ_of_i;
                } else if (lft > first_occ_of_i) {
                    lft = first_occ_of_i;
                    leftmost = i;
                } else if (rght < first_occ_of_i) {
                    rght = first_occ_of_i;
                }
            }
            if (basesRemain) {
                pos_tmp[leftmost].pop();
                bases.push_back({lft, rght});
            }
        }
        vector<pair<int, int>> l_base_r; //l_base_r are count of numbers on left and right of a[]
        if (bases.size())
            l_base_r.push_back({bases[0].first, n - 1 - bases[0].second});
        for (size_t i = 1; i < bases.size(); i++)
            l_base_r.push_back({bases[i].first - bases[i - 1].first - 1, n - 1 - bases[i].second});
        for (auto i : l_base_r)
            eff += (i.first + 1) * (i.second + 1);

        if (n * (n + 1) / 2 - eff >= k) h = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}