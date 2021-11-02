#include <bits/stdc++.h>
using namespace std;

const int LGN = 20;
const int N = 1000005;

int z[N << 1], len1[N], len2[N], maxi[LGN][N], lg2[N];

inline void computeZArray(string s){
	int n = (int)s.size();
	
	z[0] = 0;
	for(int i = 1, l = 0, r = 0; i < n; i++){
		z[i] = 0;
		if(i <= r){
			z[i] = min(r - i + 1, z[i - l]);
		}
		while(i + z[i] < n && s[i + z[i]] == s[z[i]])z[i]++;
		if(i + z[i] - 1 > r){
			l = i; r = i + z[i] - 1;
		}
	}
}

void solve(){
	string s1, s2, t;
	cin >> s1 >> s2 >> t;

	int m = (int)t.size();
	int n1 = (int)s1.size();
	int n2 = (int)s2.size();

	{
		computeZArray(s1 + '#' + t);
		for(int i = 0; i < m; i++){
			len1[i] = z[i + n1 + 1];
		}
	}

	{
		computeZArray(s2 + '#' + t);
		for(int i = 0; i < m; i++){
			len2[i] = z[i + n2 + 1];
		}
	}
	
	for(int i = 0; i < m; i++){
		maxi[0][i] = i + len2[i] - 1;
	}
	for(int k = 1; k < LGN; k++){
		for(int i = 0; i < m; i++){
			maxi[k][i] = maxi[k - 1][i];
			if(i + (1 << (k - 1)) < m){
				maxi[k][i] = max(maxi[k][i], maxi[k - 1][i + (1 << (k - 1))]);
			}
		}
	}
	lg2[1] = 0;
	for(int i = 2; i <= m; i++){
		lg2[i] = lg2[i >> 1] + 1;
	}
	
	long long ans = 0;
	for(int i = 0; i < m; i++){
		if(len1[i] == 0){
			ans += len2[i];
			continue;
		}else if(i + len1[i] == m){
			ans += len1[i];
			continue;
		}
		int lo = i + 1, hi = i + len1[i], k = lg2[len1[i]];
		ans += max({i + len2[i] - 1, maxi[k][lo], maxi[k][hi - (1 << k) + 1]}) - i + 1;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}

	return 0;
}