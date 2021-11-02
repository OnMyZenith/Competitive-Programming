#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    ll PowTwo[63];
    PowTwo[0] = 1;
    for (int i = 1; i < 63; i++)
        PowTwo[i] = PowTwo[i - 1] * 2;
    string tmp = to_string(n);
    int noOfDig = tmp.length();

    vector<int> allNums;
    vector<vector<bool>> allUseDig;
    for (int i = 1; i <= noOfDig; i++) {
        vector<bool> useDig;
        for (int j = 0; j < i; j++)
            useDig.push_back(true);
        for (int j = i; j < noOfDig; j++)
            useDig.push_back(false);
        sort(useDig.begin(), useDig.end());
        do {
            allUseDig.push_back(useDig);
        } while (next_permutation(useDig.begin(), useDig.end()));
    }
    for (vector<bool> c : allUseDig) {
        int num = 0;
        for (int j = 0; j < noOfDig; j++)
            if (c[j]) num = num * 10 + (tmp[j] - '0');
        allNums.push_back(num);
    }
    int min_diff = noOfDig + 1;
    for (int num : allNums) {
        for (int i = 0; i < 63; i++) {
            int diff = to_string(PowTwo[i]).length() - to_string(num).length();
            if (diff < 0) continue;
            int one = PowTwo[i] / pow(10, diff);
            if (one != num) continue;
            min_diff = min(min_diff, (noOfDig - (int)to_string(num).length() + diff));
        }
    }
    cout << min_diff << '\n';
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