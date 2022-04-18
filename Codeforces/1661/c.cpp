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

template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int x = *max_element(a.begin(), a.end());
    int days = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int v = x - a[i];
        days += 2 * (v / 3);
        dbg(v);
        v %= 3;
        cnt1 += v == 1;
        cnt2 += v == 2;
    }
    dbg(cnt1, cnt2, days);
    if(cnt1 == cnt2) {
        days += 2 * cnt1;
    } else if (cnt1 > cnt2) {
        days += 2 * cnt2;
        cnt1 -= cnt2;
        days += cnt1 * 2 - 1;
    } else {
        days += 2 * cnt1;
        cnt2 -= cnt1;
        days += 4 * (cnt2 / 3);
        cnt2 %= 3;
        if(cnt2 == 1) days += 2;
        else if(cnt2 == 2) days += 3;
    }
    cout << days << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}