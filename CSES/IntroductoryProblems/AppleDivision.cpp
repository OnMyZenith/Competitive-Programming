#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int p[n];
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total += p[i];
    }
    vector<vector<bool>> all;
    for (int i = 0; i < n; i++) {
        vector<bool> tmp;
        for (int j = 0; j < i; j++)
            tmp.push_back(false);
        for (int j = i; j < n; j++)
            tmp.push_back(true);
        do {
            all.push_back(tmp);
        } while (next_permutation(tmp.begin(), tmp.end()));
    }
    ll mn = 1e10;
    for (vector<bool> i : all) {
        ll oneSum = 0;
        int k = 0;
        for (bool j : i) {
            oneSum += j * p[k];
            k++;
        }
        mn = min(mn, abs(total - 2 * oneSum));
    }
    cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}