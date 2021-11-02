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
        ll a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        ll max = a[0];
        for (int i = 1; i < n; i++)
            max = max & a[i];
        ll flips = 0;
        vector<int> res;
        for (int j = 29; j >= 0; j--) {
            ll temp = pow(2, j);
            for (int i = 0; i < n; i++) {
                if (a[i] >= temp) a[i] -= temp;
                else if (b[i] >= temp)
                    b[i] -= temp;
                else
            }
        }
    }

    return 0;
}