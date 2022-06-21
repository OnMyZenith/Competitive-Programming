/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n = 3;
    vector<int> k(3);
    for (int i = 0; i < n; i++) cin >> k[i];
    vector<set<int>> s(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[i]; j++) {
            int x; cin >> x; s[i].insert(x);
        }
    }
    auto res = s;
    set<int> moved, didnt;

    for (int i = 0; i < n - 1; i++) {
        auto &s1 = s[i], &s2 = s[i + 1];
        while (!s1.empty() && !s2.empty()) {
            int x = *s1.rbegin();
            int y = *s2.begin();
            if (x < y) break;
            s1.erase(*s1.rbegin());
            s2.erase(*s2.begin());
            moved.insert(x);
            moved.insert(y);
            s1.insert(y);
            s2.insert(x);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        auto &s1 = s[i], &s2 = s[i + 1];
        while (!s1.empty() && !s2.empty()) {
            int x = *s1.rbegin();
            int y = *s2.begin();
            if (x < y) break;
            s1.erase(*s1.rbegin());
            s2.erase(*s2.begin());
            moved.insert(x);
            moved.insert(y);
            s1.insert(y);
            s2.insert(x);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        auto &s1 = res[i], &s2 = s[i + 1];
        auto it2 = s2.begin();
        auto it1 = s1.lower_bound(*it2);
        int c = 0;
        if (it1 != s1.end() && it2 != s2.end()) {
            while (*it1 == *it2) {
                c++;
                ++it1, ++it2;
                if (it1 == s1.end() || it2 == s2.end()) {
                    if (it2 == s2.end() && it1 != s1.end()) {
                        c = 0;
                    } else {
                        it2 = s2.begin();
                        it1 = s1.lower_bound(*it2);
                        while (it1 != s1.end() && it2 != s2.end()) didnt.insert(*it1), ++it1, ++it2;
                    }
                    break;
                } else if (*it1 != *it2) {
                    c = 0;
                    break;
                }
            }
        }
        cnt += c;
    }

    for (int i = 0; i < n - 1; i++) {
        auto &s1 = s[i], &s2 = res[i + 1];
        auto it2 = s2.begin();
        auto it1 = s1.lower_bound(*it2);
        int c = 0;
        if (it1 != s1.end() && it2 != s2.end()) {
            while (*it1 == *it2) {
                c++;
                ++it1, ++it2;
                if (it1 == s1.end() || it2 == s2.end()) {
                    if (it2 == s2.end() && it1 != s1.end()) {
                        c = 0;
                    } else {
                        it2 = s2.begin();
                        it1 = s1.lower_bound(*it2);
                        while (it1 != s1.end() && it2 != s2.end()) didnt.insert(*it1), ++it1, ++it2;
                    }
                    break;
                } else if (*it1 != *it2) {
                    c = 0;
                    break;
                }
            }
        }
        cnt += c;
    }

    dbg(s);
    dbg(res);
    dbg(moved);
    dbg(didnt);
    dbg(cnt);
    int N = 0; for (int i = 0; i < n; i++) N += (int)res[i].size();
    int mn = N - (int)res[0].size();
    for (int i = 1; i < n; i++) mn = min(mn, N - (int)res[i].size());
    dbg(mn);
    cout << min((int)moved.size() - (int)didnt.size(), mn) << '\n';

    return 0;
}