#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, tot_con = 0;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    deque<int> q;
    q.push_back(p[0]);
    for (int i = 1; i < n; i++) {
        int less_than = 0, greater_than = 0;
        for (int j = 0; j < i; j++)
            if (p[i] < p[j]) less_than++;
        for (int j = 0; j < i; j++)
            if (p[i] > p[j]) greater_than++;
        tot_con += min(greater_than, less_than);
        if (i - less_than > less_than) q.push_back(p[i]);
        else
            q.push_front(p[i]);
    }
    cout << tot_con << '\n';
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