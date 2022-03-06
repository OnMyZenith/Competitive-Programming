#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int stu_day[1000][5];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> stu_day[i][j];
    bool poss = true;
    bool found = false;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            poss = true;
            int i_day = 0, j_day = 0, both_days = 0;
            for (int k = 0; k < n; k++) {
                if (stu_day[k][i] && !(stu_day[k][j]))
                    i_day++;
                else if (stu_day[k][j] && !(stu_day[k][i]))
                    j_day++;
                else if (stu_day[k][j] && stu_day[k][i])
                    both_days++;
                else {
                    poss = false;
                    break;
                }
            }
            if (poss && abs(i_day - j_day) <= both_days) {
                found = true;
                cout << "YES\n";
                break;
            }
        }
        if (found) break;
    }
    if (!found) cout << "NO\n";
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