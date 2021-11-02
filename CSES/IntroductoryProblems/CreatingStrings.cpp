#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> all;
    do {
        all.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << all.size() << '\n';
    for (string i : all)
        cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}