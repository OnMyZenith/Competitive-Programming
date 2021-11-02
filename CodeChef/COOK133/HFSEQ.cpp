#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int gcdArr(vector<int> &v, int idx) {
    if (idx == v.size() - 1) return v[idx];
    int a = v[idx];
    int b = gcdArr(v, idx + 1);
    return __gcd(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int nb2;
        if (n % 2) nb2 = n / 2 + 1;
        else
            nb2 = n / 2;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> v;
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0) v.push_back(a[i]);
        if (v.size() < nb2) cout << "NO\n";
        else {
            for (int i = 0; i < v.size(); i++)
                v[i] /= 2;

            // int gc = gcdArr(v, 0);
            // if (gc == 1) cout << "YES\n";
            // else {
            //     while (gc != 1) {
            //         for (auto it = v.begin(); it != v.end();)
            //             if (*it % gc == 0)
            //                 v.erase(it);
            //             else
            //                 it++;
            //         if (v.size() < nb2) {
            //             cout << "NO\n";
            //             break;
            //         }
            //         gc = gcdArr(v, 0);
            //     }
            //     if (v.size() >= nb2) cout << "YES\n";
            // }
        }
    }

    return 0;
}