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
        if (n == 1) cout << 3 << "\n";
        else {
            cout << 1;
            for (int i = 0; i < n - 2; i++)
                cout << 0;
            cout << 5 << "\n";
        }
    }
    return 0;
}