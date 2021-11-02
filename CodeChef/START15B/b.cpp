/*input

*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define mod 1000000007

// templates
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define sz(x) (int)x.size()
#define po(x, y) fixed << setprecision(y) << x
#define ss(s) scanf(" %[^\n]%*c", s)
#define ps(s) printf("%s\n", s)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void nl() { printf("\n"); }
void sc(int &n) { scanf("%d", &n); }
void sc(ll &n) { scanf("%lld", &n); }
void sc(char &n) { scanf(" %c", &n); }
void _print(ll t) { printf("%lld ", t); }
void _print(int t) { printf("%d ", t); }
void _print(string t) { cout << t; }
void _print(char t) { printf("%c", t); }
void _print(lld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
    cout << "{";
    _print(p.F);
    cout << ",";
    _print(p.S);
    cout << "}";
}
template <class T>
void _print(vector<T> v) {
    cout << "vec->[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(set<T> v) {
    cout << "set->[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(multiset<T> v) {
    cout << "multiset->[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
    cout << "map->[ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

const ll inf = (ll)1e15 + 10;
const int N = (int)1e6 + 10;

void solve() {
    ll n, L, R;
    sc(n), sc(L), sc(R);
    vector<ll> A(n), B;
    for (int i = 0; i < n; ++i) {
        sc(A[i]);
    }
    sort(all(A));
    B = A;
    reverse(all(B));
    auto conc = [&](ll a, ll b) { return stoll(to_string(a) + to_string(b)); };
    auto sol = [&](ll U) {
        int p = 0;
        ll ans = 0;
        for (auto e : B) {
            while (p < n && conc(e, A[p]) < U)
                p++;
            ans += p;
        }
        return ans;
    };
    R++;
    ll ans = sol(R) - sol(L);
    _print(ans);
    nl();
}

int main() {
    //#ifndef ONLINE_JUDGE
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    //#endif
    int t = 1;
    sc(t);
    while (t--) {
        solve();
    }
    return 0;
}