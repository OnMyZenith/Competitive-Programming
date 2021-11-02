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

ll n, m, k, q, l, r, t, tmp, x, y, z;
const ll template_array_size = 1e6 + 7;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, str;
ll ans, res, cnt;

bool vis[template_array_size];
ll no_of_Neighbours[template_array_size];
vl g[template_array_size];


ll cnt_vis = 0, alwd_neigh = 0;
ll fin[template_array_size];

void dfs(ll i){
    for(auto neigh: g[i]){
        if (vis[neigh]) continue;
        no_of_Neighbours[neigh]--;
        if(no_of_Neighbours[neigh]<=alwd_neigh){
            vis[neigh] = 1, fin[neigh] = tmp--, cnt_vis++;
            dfs(neigh);
        }
    }
}

void solve() {
    cin >> n >> m;
    tmp = n;
    f0r(i, n) vis[i]=0, g[i].clear(), no_of_Neighbours[i] = 0, fin[i]=0;
    f0r(i, m) { 
        cin >> x >> y;
        x--, y--;
        g[x].pb(y), g[y].pb(x);
        no_of_Neighbours[x]++, no_of_Neighbours[y]++;
    }

    cnt_vis = 0, alwd_neigh = 0;
    while(cnt_vis<n){
        f0r(i, n) {
            if (!vis[i] && no_of_Neighbours[i] <= alwd_neigh){
                vis[i] = 1, fin[i] = tmp--, cnt_vis++;
                dfs(i);
            }
        }
        alwd_neigh++;
    }

    res = 0;
    f0r(i, n) { 
        cnt = 0; 
        for(ll j: g[i])
            if (fin[i] > fin[j]) cnt++;
        res = max(res, cnt);
    }
    cout << res << '\n';
    ao(fin, n);
}


int main() {

    #ifdef asr
        auto begin = chrono::high_resolution_clock::now();
    #endif

    fix(15)

    vamos

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