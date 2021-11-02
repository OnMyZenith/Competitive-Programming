#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> freq;
    for (size_t i = 0; i < s.length(); i++)
        freq[s[i]]++;
    if (freq['A'] + freq['C'] == freq['B']) cout << "YES\n";
    else
        cout << "NO\n";
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