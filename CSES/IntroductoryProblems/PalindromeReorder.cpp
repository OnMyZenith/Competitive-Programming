#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    string s;
    cin >> s;
    string res = s;
    int n = s.length();
    map<char, int> freq;
    for (int i = 0; i < n; i++)
        freq[s[i]]++;
    int unique = 0;
    for (auto it = freq.begin(); it != freq.end(); it++)
        if ((*it).second % 2 == 1)
            unique++;
    if (unique > 1) cout << "NO SOLUTION\n";
    else {
        int i = 0;
        for (auto it = freq.begin(); it != freq.end();) {
            if ((*it).second % 2 == 1) {
                res[n / 2] = (*it).first;
                (*it).second--;
            } else {
                for (int j = 0; j < (*it).second / 2; j++) {
                    res[i] = (*it).first;
                    res[n - 1 - i] = (*it).first;
                    i++;
                }
                it++;
            }
        }
        cout << res << '\n';
    }
}

int main() {
    solve();
    return 0;
}