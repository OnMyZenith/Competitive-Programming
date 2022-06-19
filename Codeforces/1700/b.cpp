/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Returns true if str1 is smaller than str2.
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    while(!str.empty() && str.back() == '0') str.pop_back();
    
    // reverse resultant string
    reverse(str.begin(), str.end());
    
    return str;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<string> poss;
    poss.push_back(string(n, '9'));
    poss.push_back("1" + string(n - 1, '9') + "1");
    poss.push_back("1" + string(n - 1, '0') + "1");
    poss.push_back("1" + string(n - 1, '1') + "1");
    poss.push_back("1" + string(n - 1, '2') + "1");
    poss.push_back("1" + string(n - 1, '3') + "1");
    poss.push_back("1" + string(n - 1, '4') + "1");
    poss.push_back("1" + string(n - 1, '5') + "1");
    poss.push_back("1" + string(n - 1, '6') + "1");
    poss.push_back("1" + string(n - 1, '7') + "1");
    poss.push_back("1" + string(n - 1, '8') + "1");
    poss.push_back("1" + string(n - 1, '9') + "1");

    auto sub = [&](string &a, string &b) -> string {
        return findDiff(a, b);
    };

    for (auto &p : poss) {
        if (sub(p, s).length() == n) {
            cout << sub(p, s) << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}