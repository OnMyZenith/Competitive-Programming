#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    string t;
    cin >> t;
    if (t.length() == 1) {
        cout << -1 << '\n';
        cout << t << " " << t << '\n';
        return;
    }
    set<char> letters;
    for (int i = 0; i < t.length(); i++)
        letters.insert(t[i]);
    int cnt = letters.size();
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