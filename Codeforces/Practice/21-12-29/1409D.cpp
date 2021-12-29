#include <bits/extc++.h>
using namespace std;

#define vamos ios_base::sync_with_stdio(false);
#define fix(prec) cout << setprecision(prec) << fixed;
using str = string;
using ll = long long;

#define each(i,s) for(auto &i:s)
string x;
int n;
void f(str s){
    auto cnt = [&](){int c = 0;each(i,s)c+=i-'0';return c;};
    int c1 = cnt();
    
    if(c1<=n) return;
    
    while(s.back()=='0'){ s.pop_back();x='0'+x;}
    
    char xx = (10 - (s.back() -'0'))+'0';

    x=xx+x; ll r = stoll(s); r+=xx-'0'; r/=10;

    s = to_string(r);

    f(s);
}
void solve() {
    str s; cin>>s>>n;;x.clear(); f(s); if(x.empty()) cout<<0<<'\n';else cout<<x<<'\n';
}

int main() {

    vamos;


    cin.tie(nullptr);

    fix(15);

    int TT = 1;
    cin >> TT;
    while(TT--)solve();

    return 0;
}