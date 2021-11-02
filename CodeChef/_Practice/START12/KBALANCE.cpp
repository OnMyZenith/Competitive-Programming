#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, count = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j * k + i < s.length();) {
                if (s[j * k + i] == '1') {
                    j++;
                    if (j * k + i < s.length() && s[j * k + i] == '1')
                        while (j * k + i < s.length() && s[j * k + i] == '1')
                            j++;
                    else if (j * k + i >= s.length())
                        count++;
                    else {
                        count++;
                        j++;
                        while (j * k + i < s.length() && s[j * k + i] == '1')
                            j++;
                    }
                } else
                    j++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}