#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;

    string smpl;
    for (int i = 0; i < n; i++)
        smpl += "0";

    vector<string> res;
    res.push_back(smpl);

    for (int i = 1; i <= n; i++) {
        for (int k = (int)pow(2, i - 1) - 1; k >= 0; k--) {
            string tmp = res[k];
            tmp[n - i] = '1';
            res.push_back(tmp);
        }
    }
    for (string i : res)
        cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}