#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    ll tot_n = 0;
    vector<pair<int, int>> soc;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        soc.push_back(make_pair(tmp, i));
    }
    sort(soc.begin(), soc.end());
    for (ll i = 0; i < n ; i++)
        tot_n += soc[i].first;
    queue<ll> leftq, rightq;
    ll k = 0, i = 0, j = 0;
    for (; i < tot_n / 2; k++) {
        for (j = 0; j < soc[k].first && i < tot_n / 2; j++, i++) {
            leftq.push(soc[k].second);
        }
        if (!(i < tot_n / 2)) break;
    }
    while (i < tot_n){
        for (; j < soc[k].first && i < tot_n; j++, i++) {
            rightq.push(soc[k].second);
        }
        j = 0;
        k++;
    }

    vector<pair<int, int>> res;
    while(!(rightq.empty() || leftq.empty())&&rightq.front()!=leftq.front()){
        res.push_back({leftq.front() + 1, rightq.front() + 1});
        leftq.pop(), rightq.pop();
    }

    cout << res.size() << '\n';

    for(auto i: res)
        cout << i.first << " " << i.second << '\n';
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