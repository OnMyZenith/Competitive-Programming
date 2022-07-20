/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    int n = (int)A.size();
    vector<int> tmp(n + 1);
    iota(tmp.begin(), tmp.end(), 1);
    set<int> s(tmp.begin(), tmp.end());

    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) s.erase(A[i]);
    }

    return *s.begin();
}



int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    



    return 0;
}
