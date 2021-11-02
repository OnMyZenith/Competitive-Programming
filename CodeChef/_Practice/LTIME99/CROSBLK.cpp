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
        int a[n];
        vector<int> jumps;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--) {
            int temp = a[i];
            jumps.push_back(i);
            while (i >= 0 && temp >= a[i - 1])
                i--;
        }
        if (!jumps[jumps.size() - 1] == 0 && a[jumps[jumps.size() - 1]] == a[0]) jumps.push_back(0);

        if (jumps[jumps.size() - 1] == 0) cout << jumps.size() - 1 << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}