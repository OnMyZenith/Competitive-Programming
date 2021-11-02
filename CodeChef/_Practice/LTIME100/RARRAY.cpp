#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> all;
    sort(a, a + n);
    do {
        vector<int> one(a, a + n);
        all.push_back(one);
    } while (next_permutation(a, a + n));

    int cnt = 0;

    for (int i = 0; i < all.size(); i++)
        for (int j = 0; j < n; j++)
            for (int k = j; k < n; k++) {
                vector<int> temp;
                for (int l = j; l <= k; l++)
                    if (a[l] >= j + 1 && a[l] <= k + 1) temp.push_back(a[l]);
                if (temp.size() == 0) cnt++;
                else if (temp.size() == 1)
                    continue;
                else {
                    int last = temp[0];
                    bool inc = true;
                    for (int m = 1; m < temp.size(); m++)
                        if (temp[m] > last) last = temp[m];
                        else {
                            inc = false;
                            break;
                        }
                    if (inc) cnt++;
                }
            }
    cout << cnt << '\n';
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