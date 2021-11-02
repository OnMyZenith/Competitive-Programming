// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define pb push_back
#define vamos {ios_base::sync_with_stdio(false);cin.tie(nullptr);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<ld> qd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;

typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vd> vvd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

const long double eps = 1e-7;
const ld PI = 3.14159265358979323846;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// ll MOD;

// ll n, m, k, q, l, r, t, tmp, x, y, z;
const ll template_array_size = 1e6 + 7;
ll a[template_array_size];
// string s, str;
// ll ans, res, cnt;

void solve() {
    ll n;
    cin >> n;
    ll oddcnt_1 = n / 2, evencnt_0 = n / 2;
    if (n % 2 == 1) evencnt_0++;
    vl odd_1(oddcnt_1);
    vl even_0(evencnt_0);
    vl odd_1_sum(oddcnt_1);
    f0r(i, n) {
        cin >> a[i];
        if (i % 2 == 1) odd_1[i / 2] = a[i]; //1s 1,3,5
        else
            even_0[i / 2] = a[i]; //0s, 0 ,2, 4
    }
    if (n == 1){ 
        cout << a[0] << '\n'<<0<<'\n';
        return;
    }
    sort(all(odd_1));
    sort(all(even_0));
    reverse(all(even_0));
    ll od = 0;
    ll ev = 0;
    f0r(i, n) {
        if (i % 2 == 0) cout << even_0[ev++] << " ";
        else
            cout << odd_1[od++] << " ";
    }
    cout << '\n';
    reverse(all(odd_1));
    odd_1_sum[0] = odd_1[0];
    f1r(i, 1, oddcnt_1) odd_1_sum[i] = odd_1_sum[i - 1] + odd_1[i];
    ll res = 0;
    reverse(all(odd_1_sum));
    if (n % 2 == 1) evencnt_0--;
    f0r(i, evencnt_0) res += even_0[i] * odd_1_sum[i];
    cout << res << '\n';
}

int main() {

    #ifdef asr
        auto begin = chrono::high_resolution_clock::now();
    #endif

    vamos

    fix(15)

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    #ifdef asr
        auto end = chrono::high_resolution_clock::now();
        cout << setprecision(2) << fixed;
        cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count()*1000 << " ms" << endl;
    #endif

    return 0;
}