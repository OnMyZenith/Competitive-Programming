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
// const ll template_array_size = 1e6 + 7;
// ll a[template_array_size];
// ll b[template_array_size];
// ll c[template_array_size];
// string s, str;
// ll ans, res, cnt;

// Merge procedure to merge two
// vectors into a single vector
vector<ll> merge(vector<ll>& v1, vector<ll>& v2)
{
    ll i = 0, j = 0;
 
    // Final vector to return
    // after merging
    vector<ll> v;
 
    // Loop continues until it reaches
    // the end of one of the vectors
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] <= v2[j]) {
            v.push_back(v1[i]);
            i++;
        }
        else {
            v.push_back(v2[j]);
            j++;
        }
    }
 
    // Here, simply add the remaining
    // elements to the vector v
    for (ll k = i; k < v1.size(); k++)
        v.push_back(v1[k]);
    for (ll k = j; k < v2.size(); k++)
        v.push_back(v2[k]);
    return v;
}
 
// Procedure to build the segment tree
void buildTree(vector<ll>* tree, ll* arr,
               ll index, ll s, ll e)
{
 
    // Reached the leaf node
    // of the segment tree
    if (s == e) {
        tree[index].push_back(arr[s]);
        return;
    }
 
    // Recursively call the buildTree
    // on both the nodes of the tree
    ll mid = (s + e) / 2;
    buildTree(tree, arr, 2 * index, s, mid);
    buildTree(tree, arr, 2 * index + 1, mid + 1, e);
 
    // Storing the final vector after merging
    // the two of its sorted child vector
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}
 
// Query procedure to get the answer
// for each query l and r are query range
ll query(vector<ll>* tree, ll index, ll s,
          ll e, ll l, ll r, ll k)
{
 
    // out of bound or no overlap
    if (r < s || l > e)
        return 0;
 
    // Complete overlap
    // Query range completely lies in
    // the segment tree node range
    if (s >= l && e <= r) {
        // binary search to find index of k
        return (tree[index].size()
                - (lower_bound(tree[index].begin(),
                               tree[index].end(), k)
                   - tree[index].begin()));
    }
 
    // Partially overlap
    // Query range partially lies in
    // the segment tree node range
    ll mid = (s + e) / 2;
    return (query(tree, 2 * index, s,
                  mid, l, r, k)
            + query(tree, 2 * index + 1, mid + 1,
                    e, l, r, k));
}
 
// Function to perform the queries
void performQueries(ll L[], ll R[], ll K[],
                    ll n, ll q, vector<ll> tree[])
{
    for (ll i = 0; i < q; i++) {
        cout << query(tree, 1, 0, n - 1,
                      L[i] - 1, R[i] - 1, K[i])
             << endl;
    }
}


void solve() {
    ll n;
    cin >> n;
    ll a[n];
    f0r(i, n) cin >> a[i];

    vector<ll> tree[4 * n + 1];
    buildTree(tree, a, 1, 0, n - 1);

    ll ans = 0;
    f0r(i,n){
        ll gre = query(tree, 1, 0 , n - 1, 0, i - 1, a[i] + 1);
        ll sma = query(tree, 1, 0 , n - 1, 0, i - 1, a[i]);
        ans += min(i - sma, gre);
    }
    cout << ans << '\n';
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