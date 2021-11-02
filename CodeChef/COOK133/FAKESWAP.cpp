#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, p;
        cin >> s >> p;
        int i;
        for (i = 0; i < n; i++)
            if (s[i] != p[i]) break;
        if (i == n) cout << "YES\n";
        else {
            for (i = 0; i < n - 1; i++)
                if (p[i] != p[i + 1]) break;
            if (i == n - 1) cout << "NO\n";
            else
                cout << "YES\n";
        }
    }

    return 0;
}