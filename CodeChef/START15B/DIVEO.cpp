#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

vector<ll> primeFactors(ll n) {
    vector<ll> f;
    while (n % 2 == 0) {
        f.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            f.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        f.push_back(n);
    return f;
}
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll score = 0;
    vector<ll> f = primeFactors(n);
    ll cnt_2 = 0, cnt_odd = 0;
    for (ll i : f)
        if (i == 2) cnt_2++;
        else
            cnt_odd++;
    if (a == 0 && b > 0) {
        score += cnt_odd * b;
    } else if (a == 0 && b < 0) {
        if (!cnt_2)
            score += b;
    } else if (a > 0 && b == 0) {
        score += cnt_2 * a;
    } else if (a < 0 && b == 0) {
        if (cnt_2)
            score += a;
    } else if (a > 0 && b < 0) {
        score += cnt_2 * a;
        if (!cnt_2)
            score += b;
    } else if (a < 0 && b > 0) {
        score += cnt_odd * b;
        if (cnt_2)
            score += a;
    } else if (a < 0 && b < 0) {
        if (cnt_2)
            score += a;
        else
            score += b;
    } else if (a > 0 && b > 0) {
        score += cnt_odd * b;
        score += cnt_2 * a;
    }
    cout << score << '\n';
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