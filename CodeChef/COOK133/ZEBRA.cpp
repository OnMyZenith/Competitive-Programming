#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, jumps;
        cin >> n >> jumps;
        string a;
        cin >> a;
        vector<int> real;

        char temp;
        int j = 0;
        for (int i = 0; i < n; i++) {
            temp = a[i];
            real.push_back(1);
            while (i < n - 1 && temp == a[i + 1]) {
                real[j]++;
                i++;
            }
            j++;
        }

        if (j < jumps + 1) cout << -1 << "\n";
        else {
            if ((j - jumps - 1) % 2 == 0)
                cout << n << "\n";
            else
                cout << n - real[j - 1] << "\n";
        }
    }
    return 0;
}