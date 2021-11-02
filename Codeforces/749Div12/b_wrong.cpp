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
ll parent[template_array_size];



void solve() {
    cin >> n >> m;
    f0r(i, n) vis[i] = 0, parent[i] = -1;
    f0r(i, m) a[i] = 0, b[i] = 0, c[i] = 0;
    f0r(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--, c[i]--;
    }
    parent[a[0]] = a[0];
    vpl edges;
    map<pair<ll, ll>, vl> pa;
    f0r(i,m){
        x = b[i], y = c[i];
        if (x > y) swap(x, y);
        pa[{x, y}].pb(a[i]);
    }
    for(auto v: pa){
        if(v.ss.size()>1){
            for (ll i = 0; i < v.ss.size() - 1; i++){
                edges.pb({v.ss[i], v.ss[i + 1]});
                parent[v.ss[i + 1]] = v.ss[i];
                vis[v.ss[i]] = 1, vis[v.ss[i + 1]] = 1;
            }
        }
        if(v.ss.size()){
            if(parent[v.ss[0]] == -1 || parent[v.ff.ff] == -1){ 
                edges.pb({v.ss[0], v.ff.ff});
                parent[v.ff.ff] = v.ss[0];
            }
            if(parent[v.ss[0]] == -1 || parent[v.ff.ss] == -1){ 
                edges.pb({v.ss[0], v.ff.ss});
                parent[v.ff.ss] = v.ss[0];
            }
        }
    }
    f0r(i,m){
        if(parent[a[i]]==-1 || parent[b[i]] ==-1){ 
            edges.pb({a[i], b[i]});
            parent[b[i]] = a[i];
        }
        if(parent[a[i]]==-1 || parent[c[i]] ==-1) {
            edges.pb({a[i], c[i]});
            parent[c[i]] = a[i];
        }
    }
    
    f0r(i, n) 
        if(parent[i]==-1){
            edges.pb({a[0], i});
            parent[i] = 0;
    }

    for(auto p:edges){
        cout << p.ff+1 << " " << p.ss+1 << '\n';
    }
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