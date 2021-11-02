#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    string s;
    cin >> s;
    int diff = 0;
    for (size_t i = 0; i < s.length();) {
        if (s[i] == '0') {
            diff++;
            i++;
            while (i < s.length() && s[i] == '0')
                i++;
        } else {
            diff++;
            i++;
            while (i < s.length() && s[i] == '1')
                i++;
        }
    }
    if (s[0] == '1')
        cout << diff - 1 << '\n';
    else
        cout << diff << '\n';
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