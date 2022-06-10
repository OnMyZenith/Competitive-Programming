/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    vector<bool> send(n, 1);
    send[0] = send[1] = 0;
    int N = n;
    while (N > 2) {
        send[N - 1] = 0;
        int sq = (int)sqrt(N);
        if (sq * sq < N) sq++;
        N = sq;
    }
    vector<int> rem;
    int vv = (int)count(send.begin(), send.end(), 0);
    cout << n - vv + 2 * (vv - 2) << '\n';
    for (int i = n - 1; i >= 0; i--) {
        if(send[i]) cout << i + 1 << " " << n << '\n';
        else rem.push_back(i + 1);
    }
    // dbg(rem);
    for (int i = 0; i < (int)rem.size() - 2; i++) {
        cout << rem[i] << " " << rem[i + 1] << '\n';
        cout << rem[i] << " " << rem[i + 1] << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}