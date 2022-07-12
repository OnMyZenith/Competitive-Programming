/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int ASZ = 26;
const int MX = 2e6 + 7;

int trie[MX][ASZ];
int endingHere[MX];
int tot = 0;

void add(const string &s) {
    int node = 0;
    for (auto &ch: s) {
        if (trie[node][ch - 'a'] == -1) {
            trie[node][ch - 'a'] = tot++;
        }
        node = trie[node][ch - 'a'];
    }
    endingHere[node]++;
}

int search(const string &word, int node) {
    int ans = 0;
    bool split = 0;
    for (int j = 0; j < (int)word.size(); j++) {
        if (word[j] == '?') {
            for (int i = 0; i < ASZ; i++)
                if (trie[node][i] != -1) ans += search(word.substr(j + 1), trie[node][i]);

            split = 1;
            break;
        }
        node = trie[node][word[j] - 'a'];
        if (node < 0) return 0;
    }
    return (!split ? endingHere[node] : ans);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    memset(trie, -1, ASZ * MX * sizeof(int));
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        add(word);
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        cout << search(s, 0) << '\n';
    }

    return 0;
}