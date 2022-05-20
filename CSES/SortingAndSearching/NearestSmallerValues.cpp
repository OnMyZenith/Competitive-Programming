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

    int n; cin >> n; 
    vector<int> a(n + 1);
    vector<int> st = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while(a[st.back()] >= a[i]) st.pop_back();
        cout << st.back() << " \n"[i == n];
        st.push_back(i);
    }

    return 0;
}