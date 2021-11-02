#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int marks[3], time[3];
        for (int i = 0; i < 3; i++)
            cin >> time[i];
        for (int i = 0; i < 3; i++)
            cin >> marks[i];

        vector<vector<int>> poss;
        for (int i = 0; i <= 20; i++)
            for (int j = 0; j <= 20; j++)
                for (int k = 0; k <= 20; k++)
                    if (i * time[0] + j * time[1] + k * time[2] <= 240) poss.push_back({i, j, k});
        vector<int> score;
        for (vector i : poss)
            score.push_back(marks[0] * i[0] + marks[1] * i[1] + marks[2] * i[2]);
        int res = 0;
        for (int i : score)
            if (res < i) res = i;
        cout << res << "\n";
    }
    return 0;
}