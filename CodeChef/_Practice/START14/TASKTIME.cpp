#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll c[n], t[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];

    map<int, vector<int>> timeReq;
    for (int i = 0; i < n; i++)
        timeReq[c[i]].push_back(t[i]);
    for (auto it = timeReq.begin(); it != timeReq.end(); it++) {
        sort((*it).second.begin(), (*it).second.end());
    }
    vector<int> ques;
    for (auto it = timeReq.begin(); it != timeReq.end(); it++) {
        ques.push_back((*it).second[0]);
        for (int i = 2; i < (*it).second.size(); i += 2) {
            ques.push_back((*it).second[i] + (*it).second[i - 1]);
        }
    }
    int marks = 0;
    sort(ques.begin(), ques.end());
    for (int i : ques)
        if (i <= k) {
            k -= i;
            marks++;
        }
    cout << marks << '\n';
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