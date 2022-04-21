/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif



int main() {
    vamos;

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());
    int stop = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if(a[i] != a[i + 1]) {
            stop = i; break;
        }
    }

    int ans = 0, carry = 0, height = a[n - 1];
    int idx = n - 1;

    while(idx > stop) {
        if(a[idx] == height) {idx--; continue;}

        int max_can_take = (k - carry) / (n - idx);

        if (max_can_take > height - a[idx]) {
            carry += (height - a[idx]) * (n - idx);
            height = a[idx++];
        } else if (max_can_take < height - a[idx]) {
            height += max_can_take;
            carry = 0; ans++;
        } else {
            height = a[idx++];
            carry = 0; ans++;
        }
    }
    cout << ans + (carry > 0) << '\n';
    return 0;
}