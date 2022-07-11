/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif
template<char MIN_CHAR = 'a', int ALPHABET = 26>
struct array_trie {
    struct trie_node {
        array<int, ALPHABET> child;
        int words = 0;

        trie_node() {
            memset(&child[0], -1, ALPHABET * sizeof(int));
        }
    };

    static const int ROOT = 0;

    vector<trie_node> nodes = {trie_node()};

    array_trie(int total_length = -1) {
        if (total_length >= 0)
            nodes.reserve(total_length + 1);
    }

    int get_or_create_child(int node, int c) {
        if (nodes[node].child[c] < 0) {
            nodes[node].child[c] = int(nodes.size());
            nodes.emplace_back();
        }

        return nodes[node].child[c];
    }

    int add(const string &word) {
        int node = ROOT;

        for (char ch : word)
            node = get_or_create_child(node, ch - MIN_CHAR);

        nodes[node].words++;
        return node;
    }

    // Given a string, how many words in the trie are prefixes of the string?
    int count_prefixes(const string &str, bool include_full) {
        int node = ROOT, count = 0;

        for (char ch : str) {
            count += nodes[node].words;
            node = nodes[node].child[ch - MIN_CHAR];

            if (node < 0)
                break;
        }

        if (include_full && node >= 0)
            count += nodes[node].words;

        return count;
    }

    int ways_to_get(const string &str) {
        int node = ROOT;
        for (auto &ch : str) {
            node = nodes[node].child[ch - MIN_CHAR];
            if (node < 0) return 0;
        }
        return nodes[node].words;
    }

    void f(vector<vector<bool>> &poss, const string &s) {
        int n = (int)poss.size();
        vector<bool> ends(n);
        for (int i = 0; i < n; i++) {
            if (i == 0 || ends[i - 1]) {
                int node = ROOT;
                for (int j = i; j < n; j++) {
                    node = nodes[node].child[s[j] - MIN_CHAR];
                    if (node < 0) break;
                    else if (nodes[node].words) {
                        ends[j] = 1;
                        poss[i][j] = 1;
                    }
                }
            }
        }
    }
};

const int MOD = 1e9 + 007; // 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    string s; cin >> s;
    int k; cin >> k;
    array_trie trie;
    for (int i = 0; i < k; i++) {
        string c; cin >> c;
        trie.add(c);
    }
    int n = (int)s.size();
    vector<vector<bool>> poss(n, vector<bool>(n));
    trie.f(poss, s);
    dbg(poss);
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (poss[j][i - 1] && dp[j]) {
                dp[i] += dp[j];
                if (dp[i] >= MOD) dp[i] -= MOD;
            }
        }
    }
    dbg(dp);
    cout << dp[n] << '\n';


    return 0;
}