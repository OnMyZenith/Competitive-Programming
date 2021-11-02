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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int res[n];
        int j = 0;
        bool theresEven = false, theresOdd = false;
        for (int i = 0; i < n; i++)
            if (a[i] % 2) {
                theresOdd = true;
                res[j] = a[i];
                j++;
            }
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0) {
                theresEven = true;
                res[j] = a[i];
                j++;
            }
        if (theresEven && theresOdd)
            for (int i = 0; i < n; i++)
                cout << res[i] << " ";
        else
            cout << -1;
        cout << "\n";
    }

    return 0;
}