#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int removeD(int &n, int d, int cnt) {
    map<int, int> freq;
    for (int i = 0; i < 9; i++)
        freq[i] = 0;
    int tmp = n;
    while (tmp) {
        freq[tmp % 10]++;
        tmp /= 10;
    }
    if (freq[d] == 0) return cnt;
    else {
        int trailing = 0;
        tmp = n;
        int i = 0;
        while (tmp % 10 != d) {
            trailing += (tmp % 10) * ((int)pow(10, i));
            tmp /= 10;
            i++;
        }
        int dig = 0;
        tmp = trailing;
        while (tmp) {
            dig++;
            tmp /= 10;
        }
        n = n - trailing + (int)pow(10, dig);
        cnt += (int)pow(10, dig) - trailing;
        return removeD(n, d, cnt);
    }
}

void solve() {
    int n, d;
    cin >> n >> d;
    cout << removeD(n, d, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}