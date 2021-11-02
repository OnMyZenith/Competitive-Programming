#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define int ll

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF 1e16
#define MOD 1000000007
#define all(x) x.begin(), x.end()

vi z_function(string s) {
    int n = (int) s.length();
    vi z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--){
		string S1, S2, X; cin >> S1 >> S2 >> X; X += "#";
		int n1 = S1.size(), n2 = S2.size(), sz = X.size();

		auto z1 = z_function(S1+'?'+X);
		z1 = vi(z1.begin()+n1+1, z1.end());

		auto z2 = z_function(S2+'?'+X);
		z2 = vi(z2.begin()+n2+1, z2.end());

		// RMQ for b[i] = z2[i]+i
		vvi rmq(sz, vi(22, -INF));
		for(int i = 0; i < sz; i++)
			rmq[i][0] = z2[i]+i;

		for(int j = 1; j < 22; j++)
			for(int i = 0; i+(1<<j) <= sz; i++)
				rmq[i][j] = max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);

		auto rmq_query = [&](int l, int r){
			int j = __lg(r-l+1);
			return max(rmq[l][j], rmq[r-(1<<j)+1][j]);
		};
		// RMQ ends

		int ans = 0;
		for(int L = sz-1; L >= 0; L--){
			int v = L+z1[L];
			int R_L = rmq_query(L, v);
			ans += R_L-L;
		}
		cout << ans << "\n";
	}

	return 0;
}