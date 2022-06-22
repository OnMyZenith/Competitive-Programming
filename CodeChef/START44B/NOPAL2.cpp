/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifndef asr_debug
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
#endif

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> mp;
    for (auto &c : s) {
        mp[c]++;
    }
    pqdec<pair<int, char>> heap;
    for (auto &[c, f] : mp) {
        heap.push({f, c});
    }

    char last1 = -1, last2 = -1;
    string res;
    while (!heap.empty()) {
        auto p = heap.top();
        heap.pop();
        if (p.second != last1 && p.second != last2) {
            res += p.second;
            p.first--;
            if (p.first) heap.push(p);
            last2 = last1;
            last1 = p.second;
            continue;
        }

        if (heap.empty()) {
            break;
        }

        auto p2 = heap.top();
        heap.pop();
        if (p2.second != last1 && p2.second != last2) {
            res += p2.second;
            p2.first--;
            if (p2.first) heap.push(p2);
            heap.push(p);
            last2 = last1;
            last1 = p2.second;
            continue;
        }

        if (heap.empty()) {
            break;
        }

        auto p3 = heap.top();
        heap.pop();
        if (p3.second != last1 && p3.second != last2) {
            res += p3.second;
            p3.first--;
            if (p3.first) heap.push(p3);
            heap.push(p2);
            heap.push(p);
            last2 = last1;
            last1 = p3.second;
            continue;
        }
        break;
    }
    if ((int)res.size() == n) {
        cout << "YES\n";
        cout << res << '\n';
        return;
    }
    cout << "NO\n";
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