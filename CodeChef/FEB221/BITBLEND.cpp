/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

void solve() {
    int n; cin >> n;
    vector<int> a(n); int o = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]&1) o = i;
    }

    vector<pair<int,int>> a01, a10;
    bool d01 = 0, d10 = 0;

    // should be 010101...
    if((a[0]&1) && (a[1]&1)){ // is 11....
        a01.push_back({1,2});
        for (int i = 2; i < n; i++) {
            if(i&1){    // should be 1
                if(!(a[i]&1)) a01.push_back({i+1,2});
            }else{      // should be 0
                if(a[i]&1) a01.push_back({i+1,2});
            }
        }
        d01 = 1;
    }else if((a[0]&1) && !(a[1]&1)){    // is 10....
        for (int i = 2; i < n; i++) {
            if(i&1){    // should be 1
                if(!(a[i]&1)) a01.push_back({i+1,1});
            }else{      // should be 0
                if(a[i]&1) a01.push_back({i+1,1});
            }
        }
        a01.push_back({2,1});
        a01.push_back({1,2});
        d01 = 1;
    }else if(!(a[0]&1) && (a[1]&1)){    // is 01....
        for (int i = 2; i < n; i++) {
            if(i&1){    // should be 1
                if(!(a[i]&1)) a01.push_back({i+1,2});
            }else{      // should be 0
                if(a[i]&1) a01.push_back({i+1,2});
            }
        }
        d01 = 1;
    }else if(o!=-1) {    // is 00....
        a01.push_back({2,o+1});
        for (int i = 2; i < n; i++) {
            if(i&1){    // should be 1
                if(!(a[i]&1)) a01.push_back({i+1,2});
            }else{      // should be 0
                if(a[i]&1) a01.push_back({i+1,2});
            }
        }
        d01 = 1;
    }
    
    // should be 1010...
    if((a[0]&1) && (a[1]&1)){ // is 11....
        a10.push_back({2,1});
        for (int i = 2; i < n; i++) {
            if(i&1){    // should be 0
                if(a[i]&1) a10.push_back({i+1,1});
            }else{      // should be 1
                if(!(a[i]&1)) a10.push_back({i+1,1});
            }
        }
        d10 = 1;
    }else if(!(a[0]&1) && (a[1]&1)){    // is 01....
        for (int i = 2; i < n; i++) {
            if(i&1){    // should be 0
                if(a[i]&1) a10.push_back({i+1,2});
            }else{      // should be 1
                if(!(a[i]&1)) a10.push_back({i+1,2});
            }
        }
        a10.push_back({1,2});
        a10.push_back({2,1});
        d10 = 1;
    }else if((a[0]&1) && !(a[1]&1)){    // is 10....
        for (int i = 2; i < n; i++) {
            if(i&1){    // should be 0
                if(a[i]&1) a10.push_back({i+1,1});
            }else{      // should be 1
                if(!(a[i]&1)) a10.push_back({i+1,1});
            }
        }
        d10 = 1;
    }else if(o!=-1) {    // is 00....
        a10.push_back({1,o+1});
        for (int i = 2; i < n; i++) {
            if(i&1){    // should be 0
                if(a[i]&1) a10.push_back({i+1,1});
            }else{      // should be 1
                if(!(a[i]&1)) a10.push_back({i+1,1});
            }
        }
        d10 = 1;
    }
    if(d10 && d01){
        a01 = (((int)a10.size()) < ((int)a01.size())?a10:a01);
        cout << ((int)a01.size()) << '\n';
        for (auto &u : a01) {
            cout << u.first << " " << u.second << '\n';
        }
    }else if(d01){
        cout << ((int)a01.size()) << '\n';
        for (auto &u : a01) {
            cout << u.first << " " << u.second << '\n';
        }
    }else if(d10){
        swap(a01, a10);
        cout << ((int)a01.size()) << '\n';
        for (auto &u : a01) {
            cout << u.first << " " << u.second << '\n';
        }
    }else{
        cout << "-1\n";
    }
    dbg(a01,a10);
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve();
    }

    return 0;
}