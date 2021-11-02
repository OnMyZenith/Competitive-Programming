#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    typedef long long ll;

    int t;
    cin >> t;
    long long n;
    while (t--) {
        cin >> n;
        int count = 0;
        long long arr[n];
        map<ll, set<ll>> m;
        for (int i = 1; i <= 40; i++) {
            int temp = i;
            for (int j = 1; j <= temp; j++) {
                while (temp != 1) {
                    cout << temp << "\n";
                    while (!(temp % j)) {
                        temp /= j;
                        if (m[i].find(j) != m[i].end())
                            m[i].insert(j);
                        else
                            m[i].erase(m[i].find(j));
                    }
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        // cout << count << "\n";
        cout << *m[35LL].begin() << "\n";
    }

    return 0;
}