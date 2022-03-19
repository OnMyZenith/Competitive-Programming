#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// #define int long long
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626
#define gc getchar_unlocked
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)
#define sf(f) scanf("%f",&f)
#define slf(f) scanf("%llf", &f)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define pc(c) printf("%c\n", c)
#define ps(s) printf("%s\n", s)
#define pf(f) printf("%f\n", f)
#define plf(f) printf("%llf\n", f)
#define prec(n) fixed << setprecision(n)
#define ffor(i, j, k, in) for (int i=j; i<k; i+=in)
#define rfor(i, j, k, in) for (int i=j; i>=k; i-=in)
#define mem(a, b) memset(a, (b), sizeof(a))
#define lbound(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ubound(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define readArray(a, n) for (int i=0; i<n; i++) cin >> a[i]
#define spc " " 
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define br printf("\n")
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mpii;
typedef map<string,int> mpsi;
typedef set<string> sets;
typedef multiset<int> mseti;
typedef multiset<string> msets;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define sz(a) int((a).size()) 
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))

/****** Some Constants ***********************/
#define EPS 1e-9
#define inf (int) 1e9
#define llinf (ll) 1e18
#define MOD 1000000007
#define read(type) readInt<type>()
#define IN(A, B, C) assert( B <= A && A <= C)
/**********************************************/

/****** Bitwise operations Helper *************/
#define sqr(n) (n*n)
inline int two(int n) { return 1 << n; } 
inline int test(int n, int b) { return (n>>b)&1; } 
inline void set_bit(int & n, int b) { n |= two(b); } 
inline void unset_bit(int & n, int b) { n &= ~two(b); } 
inline int last_bit(int n) { return n & (-n); } 
/**********************************************/

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
/**********************************************/

/****** Template of printing 1d and 2d vector *********/
template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << "\n";
}

template<typename T>
void print2dVector(const T& t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}
/******************************************************/

/****** Global Declaration *********/
// const int N = 200005;
const int N = 1;
int f[N], invf[N];
int spf[N];

const int dx4[] = {-1, 0, 1, 0}; 
const int dy4[] = { 0, 1, 0,-1}; 
 
const int dx8[] = {-1, 0, 1, 0, -1,-1, 1, 1}; 
const int dy8[] = { 0, 1, 0,-1, -1, 1,-1, 1}; 
/***********************************/

/****** Useful Functions ******************************/
int gcd(int a, int b) 
{    
    return b ? gcd(b, a%b) : a;
}

int power(int a,int b)
{
    if(b==0)
        return 1;
    else
    {
        int x=power(a,b/2);
        int y=(x*x)%MOD;
        if(b%2)
            y=(y*a)%MOD;
        return y;
    }
}

int inverse(int a)
{
    return power(a, MOD-2);
}

int ncr(int n, int r)
{
    if(n<0 || r<0 || n<r)
        return 0;
    int ans=f[n];
    ans=(ans*invf[r])%MOD;
    ans=(ans*invf[n-r])%MOD;
    return ans;
}

void precomputeFactorials()
{
    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=(f[i-1]*i)%MOD;
    for(int i=0;i<N;i++)
        invf[i]=inverse(f[i]);
}

void precomputeSPF()
{
    for(int i=0;i<N;i++)
        spf[i]=i;
    for(int i=2;i<N;i++)
    {
        if(spf[i]==i)
        {
            for(int j=2*i;j<N;j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}

void precompute()
{
    // precomputeFactorials();
    // precomputeSPF();
}

int count_bits(int n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n/=2;
    }
    return c;
}

bool isPrime(int n)//O(sqrt(n))
{      
    if(n<2) return false; 
    for(int i=2; i*i<=n; i++) 
        if(n%i==0) return false; 
    return true; 
} 

bool isPowerTwo(int x)
{ 
    return (x && !(x & (x-1))); 
};                                             

bool isSubstring(string s1, string s2)
{ 
    if(s1.find(s2) != string::npos) return true; 
    return false; 
} 
/******************************************************/

/* ========== YOUR CODE HERE ========= */

void solution() {
    ll n;
    cin >> n;

    ll a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll op1 = b[0] - a[0], op2 = 0;
    ll res1 = 0, res2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (op1 + op2 < b[i] - a[i])
        {
            op2 += ((b[i] - a[i]) - op1 - op2);
        }
        else if (op1 + op2 > b[i] - a[i])
        {
            op1 -= (op1 + op2 - (b[i] - a[i]));
        }

        if (op1 < 0 || op2 > (b[n - 1] - a[n - 1]))
        {
            res1 = -1;
            res2 = 0;
            break;
        }

        res1 = max(res1, op1);
        res2 = max(res2, op2);
    }

    ll res = res1 + res2;

    cout << res << endl;
}

/* ========== YOUR CODE HERE ========= */

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--) 
    {
        solution();
    }
    return 0;
}