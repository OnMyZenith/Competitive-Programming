#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a <= (c); ++a)
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
#define sz(x) ((long long) x.size())
#define trav(a,x) for (auto& a : x)
#define lb lower_bound
#define ub upper_bound
#define eq equal_range
#define endl '\n'



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

template<typename X, typename Y> X& remin(X& x, const Y& y) { return x = (y < x) ? y : x; }
template<typename X, typename Y> X& remax(X& x, const Y& y) { return x = (x < y) ? y : x; }
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }


mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
/* shuffle(permutation.begin(), permutation.end(), rng); */


const long double eps = 1e-7;
const ld PI = 3.14159265358979323846;
const ll INF = 1e18 + 7;
const ll MOD = 1e9 + 7;
// const ll INF = 1e9 + 7;
// const ll MOD = 998244353;
// ll MOD;





const ll tasz = 1e6 + 7;
ll a[tasz];
// ll b[tasz];
// ll c[tasz];


// set<ll> v1, v2;
vl v1, v2;

ll num,cnt;

bool usedJ, usedL;

void makeDig(ll j,ll l){
    bool prev_usedJ = usedJ, prev_usedL = usedL;
    if(num>9&&usedL&&usedJ) v2.pb(num);
    if (cnt > 10) return;
    cnt++;
    ll tmp = num;
    
    num = 10 * tmp + j;
    usedJ = true;
    makeDig(j, l);
    usedJ = prev_usedJ;

    num = 10 * tmp + l;
    usedL = true;
    makeDig(j, l);
    usedL = prev_usedL;

    num = tmp;
    cnt--;
}

void solve() {
    // #warning: Switch to the Global larger array size after debugging
    ll n, k;
    cin >> n >> k;
    string s = to_string(n);
    set<char> used;
    ll idx = -1;
    f0r(i,sz(s)){
        if (sz(used) == k){
            idx = i;
            break;
        }
        used.insert(s[i]);
    }
    ll left = 0;
    f1r(i,idx,sz(s)){
        left = 10 * left + (s[i] - '0');
    }
    s = s.substr(0, idx + 1);
    s += to_string(v1[lb(all(v1), left)-v1.begin()]);
    cout << s << endl;
    
    // if (k == 1) cout << v1[lb(all(v1), n) - v1.begin()] << endl;
    // // else cout << v2[lb(all(v2), n) - v2.begin()] << endl;
    // else cout << min(v2[lb(all(v2), n) - v2.begin()], v1[lb(all(v1), n) - v1.begin()]) << endl;
}


int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

    f1r(i,1,9){// no. of dig
        f1r(j,1,9){// the dig
            ll t = 0;
            f0r(l,i){
                t = t * 10 + j;
            }
            v1.pb(t);
        }
    }
    f1r(i,1,9){// no. of dig
        f1r(j,0,9){// the 1stdig
            f1r(l,j+1,9){// the 2nd dig
                makeDig(j, l);
            }
        }
    }
    v2.pb(INF);
    v1.pb(1111111111);
    sort(all(v2));
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