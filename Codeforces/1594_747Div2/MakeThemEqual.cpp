#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    bool case1 = true, case2 = false;
    for (auto i : s)
        if (i != c) case1 = false;
    if (!case1 && s[n - 1] == c) case2 = true;
    if (case1) {
        cout << 0 << '\n';
        return;
    } else if (case2) {
        cout << 1 << '\n';
        // cout << n << '\n';
        return;
    }
    set<int> cPos, prim;
    for (int i = 1; i < n; i++)
        if (s[i] == c) cPos.insert(i + 1);

    int tmp = n;
    while (n % 2 == 0) {
        prim.insert(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            prim.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
        prim.insert(n);
    n = tmp;

    set<int> result;
    set_difference(cPos.begin(), cPos.end(), prim.begin(), prim.end(), inserter(result, result.end()));

    if (result.size() == 0) {
        int d = 0;
        for (int i = 1; i <= n; i++)
            if (n % i != 0) {
                d = i;
                break;
            }
        cout << 2 << '\n';
        // cout << d << " " << n << '\n';
    } else {
        bool poss = true, pp = false;
        int r;
        for (auto it = result.begin(); it != result.end(); it++) {
            poss = true;
            int temp = *it;
            r = *it;
            for (int i = 2; i * temp < n; i++) {
                temp *= i;
                if (result.find(temp) == result.end()) {
                    poss = false;
                    break;
                }
            }
            if (poss) {
                pp = true;
                break;
            }
        }
        if (pp) {
            cout << 1 << '\n';
            // cout << r << '\n';
        } else {
            int d = 0;
            for (int i = 1; i <= n; i++)
                if (n % i != 0) {
                    d = i;
                    break;
                }
            cout << 2 << '\n';
            // cout << d << " " << n << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}