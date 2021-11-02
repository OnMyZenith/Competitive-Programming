#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll num;
        cin >> num;
        map<vector<bool>, ll> m;
        vector<vector<bool>> v{num};

        string str;
        cin >> str;
        for (ll i = 0; i < num; i++) {
            // v[i] = {};
            v.at(i).push_back((bool)(str[i] - 48));
        }
        cin >> str;
        for (ll i = 0; i < num; i++) {
            v.at(i).push_back((bool)(str[i] - 48));
        }

        for (auto i : v) {
            m[i]++;
        }
        ll wildcard = m[{true, true}], pro = m[{false, true}], eng = m[{true, false}], noob = m[{false, false}];
        if (pro > eng) {
            noob += pro - eng;
            if (wildcard > noob) {
                cout << noob + eng + (wildcard - noob) / 2 << "\n";
            } else
                cout << wildcard + eng << "\n";
        } else {
            noob += eng - pro;
            if (wildcard > noob) {
                cout << noob + pro + (wildcard - noob) / 2 << "\n";
            } else
                cout << wildcard + pro << "\n";
        }
    }

    return 0;
}