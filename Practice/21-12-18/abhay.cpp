#include <bits/stdc++.h>
using namespace std;
#define abhay_sharma                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define MOD 1000000007
#define endl "\n"
#define int long long
#define ld long double
#define float double
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define MAXN 100005
#define BLOCK 555
#define pii pair<int, int>
const ld r = 1e+9;
int lcm(int a, int b) {
    int temp = a * b;
    int temp1 = __gcd(a, b);
    int ans = temp / temp1;
    return ans;
}
int helper(string c, string mins, string maxs) {
    string check = "";
    int flag1 = 0, flag2 = 0;
    int l1 = mins.length(), l2 = maxs.length();
    // int m=0;
    int x = c.length();
    if (l1 % x != 0 || l2 % x != 0) {
        return 0;
    }
    if (x == 0) {
        return 0;
    }
    int q1 = l1 / x;
    int q2 = l2 / x;
    while (q1--) {
        // cout<<1<<endl;
        check += c;
        // m+=x;
        // cout<<m<<" "<<check<<" ";
    }
    // cout<<endl;
    if (check == mins) {
        flag1 = 1;
    }
    // cout << check << " ";
    check = "";
    // int n=0;
    while (q2--) {
        check += c;
        // n+=x;
        // cout<<n<<" "<<check<<" ";
    }
    if (check == maxs) {
        flag2 = 1;
    }
    // cout << check << endl;
    int ans = flag1 & flag2;
    return ans;
}
int helper1(string c, string x) {
    int count = 0;
    string check = "";
    while (check.length() <= x.length()) {
        check += c;
        count++;
    }
    count--;
    return count;
}
void solve() {
    string s, t;
    cin >> s >> t;
    string maxs, mins;
    int a, b;
    int n1 = s.length(), n2 = t.length();
    if (n1 >= n2) {
        maxs = s;
        mins = t;
        a = n1;
        b = n2;
    } else {
        maxs = t;
        mins = s;
        a = n2;
        b = n1;
    }
    // cout << maxs << " " << mins << endl;
    map<string, int> mp1, mp2;
    string temp1 = "", temp2 = "";
    for (int i = 0; i < a; i++) {
        temp1 += maxs[i];
        mp1[temp1]++;
        // cout << temp1 << endl;
    }
    for (int i = 0; i < b; i++) {
        temp2 += mins[i];
        mp2[temp2]++;
    }
    if (mp1[mins] == 0) {
        // cout << -1 << endl;
        return;
    }
    // cout << "HI" << endl;
    string temp3 = "";
    for (int i = 0; i < b; i++) {
        temp3 += mins[i];
        // cout << temp3 << " " << mp2[temp3] << " ";
        if (mp2[temp3]) {
            // cout << helper(temp3, mins, maxs) << endl;
            if (helper(temp3, mins, maxs)) {
                int x1 = helper1(temp3, mins);
                int x2 = helper1(temp3, maxs);
                int sum = lcm(x1, x2);
                int count1 = 0;
                string temp4 = "";
                while (count1 <= sum) {
                    temp4 += temp3;
                    count1+=temp3.size();
                }
                cout << temp4 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}
signed main() {
    abhay_sharma int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}