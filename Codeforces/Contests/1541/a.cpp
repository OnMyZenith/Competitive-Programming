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

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}



void solve() {
    int n; cin >> n;
    if(!(n & 1)) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        for (int i = 0; i + 1 < n; i+=2) {
            swap(a[i], a[i + 1]);
        }
        ov(a);
        return;
    }
    cout << "3 1 2" << " ";
    vector<int> a(n - 3);
    iota(a.begin(), a.end(), 4);
    for (int i = 0; i + 1 < n - 3; i+=2) {
        swap(a[i], a[i + 1]);
    }
    ov(a);
    cout << '\n';
    
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