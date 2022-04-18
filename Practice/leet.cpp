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


class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int)s.size(), m = (int)p.size(), i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == p[j]) i++, j++;
            else if (p[j] == '.') p[j++] = s[i++];
            else {
                if(p[j] != '*') return false;
                else 
            }


        }
    }
};

int main() {
    vamos;


    return 0;
}