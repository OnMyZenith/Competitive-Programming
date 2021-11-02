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

// ll n, k, q, l, r, t, tmp, x, y, z;
// const ll template_array_size = 1e6 + 7;
// ll a[template_array_size];
// ll b[template_array_size];
// ll c[template_array_size];
// string s, str;
// ll ans, res, cnt;


void solve() {
    ll n, k;
    cin >> n >> k;
   

}


int main() {

    #ifdef asr
        auto begin = chrono::high_resolution_clock::now();
    #endif

    vamos;

    fix(15);

    set<ll> p2m1, all;
    f1r(i, 1, 20){
        p2m1.insert((ll)pow(2, i)-1);
        all.insert((ll)pow(2, i)-1);
    }

    map<ll, pair<set<ll>,set<ll>>> m;
    m[1] = {{1},{}};
    for (auto i: p2m1){
        if (i == 1) continue;
        set<ll> tm = m[(i + 1) / 2 - 1].ff;
        tm.insert((i + 1) / 2);
        m[i] = {tm, {}};
    }
    ll cnt = 0;

    ll previ = 1;
    for (auto it = p2m1.begin(); it != p2m1.end(); it++){
        set<ll> temp;
        for(auto l_it = all.begin(); ((*it) - 2 * (*l_it)) > previ; l_it++) {
            cout << cnt++ << '\n';
            temp.insert((*it) - 2 * (*l_it));
            set<ll> t1, t2;
            t1 = m[(*it)].ff;
            t2 = m[(*l_it)].ff;
            set<ll> result_sub;
            set_difference(all(t1), all(t2), inserter(result_sub, result_sub.end()));
            m[(*it) - 2 * (*l_it)].ff.insert(all(result_sub));
            m[(*it) - 2 * (*l_it)].ss.insert(all(t2));
        }
        all.insert(all(temp));
        previ = (*it);
    }

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