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



// B. Swaps
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given two arrays a and b of length n. Array a contains each odd integer from 1 to 2n in an arbitrary order, and array b contains each even integer from 1 to 2n in an arbitrary order.

// You can perform the following operation on those arrays:

// choose one of the two arrays
// pick an index i from 1 to n−1
// swap the i-th and the (i+1)-th elements of the chosen array
// Compute the minimum number of operations needed to make array a lexicographically smaller than array b.
// For two different arrays x and y of the same length n, we say that x is lexicographically smaller than y if in the first position where x and y differ, the array x has a smaller element than the corresponding element in y.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104).

// The first line of each test case contains a single integer n (1≤n≤105) — the length of the arrays.

// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤2n, all ai are odd and pairwise distinct) — array a.

// The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤2n, all bi are even and pairwise distinct) — array b.

// It is guaranteed that the sum of n over all test cases does not exceed 105.

// Output
// For each test case, print one integer: the minimum number of operations needed to make array a lexicographically smaller than array b.

// We can show that an answer always exists.

// Example
// inputCopy
// 3
// 2
// 3 1
// 4 2
// 3
// 5 3 1
// 2 4 6
// 5
// 7 5 9 1 3
// 2 4 6 10 8
// outputCopy
// 0
// 2
// 3
// Note
// In the first example, the array a is already lexicographically smaller than array b, so no operations are required.

// In the second example, we can swap 5 and 3 and then swap 2 and 4, which results in [3,5,1] and [4,2,6]. Another correct way is to swap 3 and 1 and then swap 5 and 1, which results in [1,5,3] and [2,4,6]. Yet another correct way is to swap 4 and 6 and then swap 2 and 6, which results in [5,3,1] and [6,2,4].


/**
 * Author: Johan Sannemo, pajenegod
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Range Minimum Queries on an array. Returns
 * min(V[a], V[a + 1], ... V[b - 1]) in constant time.
 * Usage:
 *  RMQ rmq(values);
 *  rmq.query(inclusive, exclusive);
 * Time: $O(|V| \log |V| + Q)$
 * Status: stress-tested
 */
// #pragma once

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

const ll tasz = 1e6 + 7;
ll even[tasz];
ll evenIdx[tasz];
ll oddIdx[tasz];
ll odd[tasz];
// ll c[tasz];




void solve() {
    ll n;
    cin >> n;
    f0r(i,n){
        cin>>odd[i];
        oddIdx[odd[i]] = i;
    }
    f0r(i,n){
        cin>>even[i];
        evenIdx[even[i]] = i;
    }
    vl v;
    f0r(i,n){
        v.pb(evenIdx[2 * i + 2]);
    }
    RMQ rmq(v);
    ll ans = INF;
    f0r(i,n){
        ll oddCst = oddIdx[2 * i + 1];
        ll evenCst = rmq.query(i,n);
        ans = min(ans, oddCst + evenCst);
    }
    cout<<ans<<endl;
}


int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;

    fix(15);

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