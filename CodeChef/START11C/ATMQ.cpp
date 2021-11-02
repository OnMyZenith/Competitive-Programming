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
        int a[2][n];
        for (int i = 0; i < n; i++)
            cin >> a[0][i];
        for (int i = 0; i < n; i++)
            a[1][i] = i;
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n - 1; j++) {
                if (a[0][j] < a[0][j + 1]) {
                    int t1, t2;
                    t1 = a[0][j];
                    t2 = a[1][j];
                    a[0][j] = a[0][j + 1];
                    a[1][j] = a[1][j + 1];
                    a[0][j + 1] = t1;
                    a[1][j + 1] = t2;
                }
            }
        }
        int res[n];
        for (int i = 0; i < n; i++)
            res[a[1][i]] = i + 1;
        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }

    return 0;
}