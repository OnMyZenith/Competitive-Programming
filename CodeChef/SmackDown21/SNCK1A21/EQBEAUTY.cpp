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

// ll m, k, q, l, r, t, tmp, x, y, z;
const ll template_array_size = 1e6 + 7;
// ll a_rev[template_array_size];
// ll sum_a_arev[template_array_size];
// ll diff[template_array_size];
// ll b[template_array_size];
// ll c[template_array_size];
// string s, str;
// ll ans, res, cnt;

ll a[template_array_size];

ll getClosest(ll, ll, ll);
 
// Returns element closest to target in arr[]
ll findClosest(ll arr[], ll n, ll target)
{
    // Corner cases
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];
 
    // Doing binary search
    ll i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;
 
        if (arr[mid] == target)
            return arr[mid];
 
        /* If target is less than array element,
            then search in left */
        if (target < arr[mid]) {
 
            // If target is greater than previous
            // to mid, return closest of two
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1],
                                  arr[mid], target);
 
            /* Repeat for left half */
            j = mid;
        }
 
        // If target is greater than mid
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid],
                                  arr[mid + 1], target);
            // update i
            i = mid + 1;
        }
    }
 
    // Only single element left after search
    return arr[mid];
}
 
// Method to compare which one is the more close.
// We find the closest by taking the difference
// between the target and both values. It assumes
// that val2 is greater than val1 and target lies
// between these two.
ll getClosest(ll val1, ll val2,
               ll target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

ll minCost(ll A[], ll n)
{
    // Initialize cost to 0
    ll cost = 0;
 
    // // Sort the array
    // sort(A, A + n);
 
    // Middle element
    ll K = A[n / 2];
 
    // Find Cost
    for (ll i = 0; i < n; ++i)
        cost += abs(A[i] - K);
 
    // If n, is even. Take minimum of the
    // Cost obtained by considering both
    // middle elements
    if (n % 2 == 0) {
        ll tempCost = 0;
 
        K = A[(n / 2) - 1];
 
        // Find cost again
        for (ll i = 0; i < n; ++i)
            tempCost += abs(A[i] - K);
 
        // Take minimum of two cost
        cost = min(cost, tempCost);
    }
 
    // Return total cost
    return cost;
}


ll arr[template_array_size];
ll distinct_inc_f[template_array_size];
ll distinct_inc_l[template_array_size];

ll INF = 100000 * MOD;
void solve() {
    ll n;
    cin >> n;
    f0r(i, n) cin >> a[i];
    sort(a, a + n);
    vl sum(n);
    sum[0] = a[0];
    f1r(i, 1, n) sum[i] = sum[i - 1] + a[i];
    if(n==2){
        cout << 0 << '\n';
        return;
    }
    if(n==3){
        cout << min(a[1] - a[0], a[2] - a[1]) << '\n';
        return;
    }
    ll res = INF;

    ll f = -1, l = -1;
    f0r(i, n) if (a[i] != a[0]) {
        f = i;
        break;
    }
    f1r(i, f, n) distinct_inc_l[i - f] = a[i];
    f0rd(i, n-1) if (a[i] != a[n-1]) {
        l = i;
        break;
    }
    f0r(i,l+1) distinct_inc_f[i] = a[i];

    ll cst_inc_f = minCost(distinct_inc_f, l+1);
    ll cst_inc_l = minCost(distinct_inc_l, n-(f));

    f0r(i,n - 1){
        ll one = a[i] - a[0];
        ll two = a[n - 1] - a[i + 1];
        if (one && two) res = min(res, abs(one - two));
        else if (one == 0&&two==0) res = 0;
        else if (one == 0) res = min(res, cst_inc_l);
        else if (two == 0) res = min(res, cst_inc_f);
    }


    f0r(i, n - 2) arr[i] = a[i + 1];

    res = min(abs(a[n - 1] - a[0] - a[n - 2] + a[1]),res);
    ll ext = a[n - 1] + a[0];
    f0r(i, n - 2){
        ll b = arr[i];

        if(i>0) arr[i] = arr[i - 1];
        else arr[i] = arr[i + 1];
        
        res = min(abs(findClosest(arr, n - 2, ext - b) - (ext - b)), res);
        arr[i] = b;
    }

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
        // cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count()*1000 << " ms" << endl;
    #endif

    return 0;
}