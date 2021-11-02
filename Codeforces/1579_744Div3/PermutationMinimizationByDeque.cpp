#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    deque<int> q;
    q.push_back(p[0]);
    for (int i = 1; i < n; i++)
        if (p[i] > q[0]) q.push_back(p[i]);
        else
            q.push_front(p[i]);
    for (auto i : q)
        cout << i << " ";
    cout << '\n';
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