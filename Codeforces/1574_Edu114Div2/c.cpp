#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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


// C. Slay the Dragon
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Recently, Petya learned about a new game "Slay the Dragon". As the name suggests, the player will have to fight with dragons. To defeat a dragon, you have to kill it and defend your castle. To do this, the player has a squad of n heroes, the strength of the i-th hero is equal to ai.

// According to the rules of the game, exactly one hero should go kill the dragon, all the others will defend the castle. If the dragon's defense is equal to x, then you have to send a hero with a strength of at least x to kill it. If the dragon's attack power is y, then the total strength of the heroes defending the castle should be at least y.

// The player can increase the strength of any hero by 1 for one gold coin. This operation can be done any number of times.

// There are m dragons in the game, the i-th of them has defense equal to xi and attack power equal to yi. Petya was wondering what is the minimum number of coins he needs to spend to defeat the i-th dragon.

// Note that the task is solved independently for each dragon (improvements are not saved).

// Input
// The first line contains a single integer n (2≤n≤2⋅105) — number of heroes.

// The second line contains n integers a1,a2,…,an (1≤ai≤1012), where ai is the strength of the i-th hero.

// The third line contains a single integer m (1≤m≤2⋅105) — the number of dragons.

// The next m lines contain two integers each, xi and yi (1≤xi≤1012;1≤yi≤1018) — defense and attack power of the i-th dragon.

// Output
// Print m lines, i-th of which contains a single integer — the minimum number of coins that should be spent to defeat the i-th dragon.

// Example
// inputCopy
// 4
// 3 6 2 3
// 5
// 3 12
// 7 9
// 4 14
// 1 10
// 8 7
// outputCopy
// 1
// 2
// 4
// 0
// 2
// Note
// To defeat the first dragon, you can increase the strength of the third hero by 1, then the strength of the heroes will be equal to [3,6,3,3]. To kill the dragon, you can choose the first hero.

// To defeat the second dragon, you can increase the forces of the second and third heroes by 1, then the strength of the heroes will be equal to [3,7,3,3]. To kill the dragon, you can choose a second hero.

// To defeat the third dragon, you can increase the strength of all the heroes by 1, then the strength of the heroes will be equal to [4,7,3,4]. To kill the dragon, you can choose a fourth hero.

// To defeat the fourth dragon, you don't need to improve the heroes and choose a third hero to kill the dragon.

// To defeat the fifth dragon, you can increase the strength of the second hero by 2, then the strength of the heroes will be equal to [3,8,2,3]. To kill the dragon, you can choose a second hero.


const ll tasz = 1e6 + 7;
ll a[tasz];
ll x[tasz];
ll y[tasz];




void solve() {
    ll n, m, sm = 0;
    cin >> n;
    f0r(i, n) cin >> a[i], sm += a[i];
    sort(a, a + n);
    cin >> m;
    f0r(i, m) cin >> x[i] >> y[i];
    f0r(i,m){
        ll ans = 0;
        auto it = lower_bound(a, a + n, x[i]);
        if(it==a+n){
            ans+=x[i]-a[n-1];
            ans += max(0LL, y[i] - sm + a[n - 1]);
        }else{
            ll tmp = max(0LL, y[i] - sm + *it);
            if(it>a){
                auto bit = it;
                bit--;
                // if ((x[i] - *bit < *it - x[i])) 
                it = bit;
            }
            ans += max(x[i] - *it, 0LL);
            ans += max(0LL, y[i] - sm + *it);
            ans =min(tmp,ans);
        }
        cout<<ans<<endl;
    }

}


int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count()*1000 << " ms" << endl;
#endif

    return 0;
}