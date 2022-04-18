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

// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{ 
    stack<char> s;
    char x;
 
    // Traversing the Expression
    for (int i = 0; i < (int)expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }
 
        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;
 
        switch (expr[i]) {
        case ')':
             
            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
 
    // Check Empty Stack
    return (s.empty());
}

void solve() {
    int n; string s; cin >> n >> s;
    int c0 = count(s.begin(), s.end(), '0'); int c1 = n - c0;
    if(s.back() != '1' || s.front() != '1' || (c0 & 1)) {
        cout << "NO\n";
        return;
    }
    string s1 = "(", s2 = "(";
    for (int i = 0, ac0 = 0, ac1 = 1; i < n; i++) {
        if(s[i] == '0') {
            if(ac0 < c0 / 2) s1 += 
        }
    }
    for (int i = 1, cnt1 = 1, cnt2 = 1; i < n; i++) {
        if(s[i] == '0') {
            if(cnt1 > cnt2) {
                s1 += ')'; cnt1--;
                s2 += '('; cnt2++;
            } else {
                s2 += ')'; cnt2--;
                s1 += '('; cnt1++;
            }
        } else {
            if((cnt1 > suff[i] && cnt2 > 0) || (cnt1 > 0 && cnt2 > suff[i])) {
                s1 += ')'; cnt1--;
                s2 += ')'; cnt2--;
            } else {
                s1 += '('; cnt1++;
                s2 += '('; cnt2++;
            }
        }
    }
    dbg(s1, s2);
    if(areBracketsBalanced(s1) && areBracketsBalanced(s2)) {
        cout << "YES\n";
        cout << s1 << '\n';
        cout << s2 << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    vamos;


    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}