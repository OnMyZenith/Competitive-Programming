#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> poss;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i += 2) {
            vector<int> temp;
            if (2 * i != n) {
                for (int j = 1; j <= i; j++)
                    temp.push_back(-1);
                for (int j = i + 1; j <= n; j++)
                    temp.push_back(1);
                sort(temp.begin(), temp.end());
                do {
                    poss.push_back(temp);
                } while (next_permutation(temp.begin(), temp.end()));
            }
        }
        cout << poss.size();
    }

    return 0;
}