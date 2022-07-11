// Manacher's Algorithm
// Manacher's Algorithm for all odd palindromic substirngs in O(n);
vector<int> manacher_odd(string s) {
    int n = (int)s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

// Returns an int array of length 2n - 1, where
// Odd idx represents Even length palindromes with length = v[i], start = (i + 1) / 2 - v[i] / 2;
// Even idx represents Odd length palindromes with length = v[i], start = (i + 1) / 2 - v[i] / 2;
vector<int> manacher(const string &s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");

    for (int i = 1; i < (int)res.size() - 1; i++) {
        res[i] /= 2;
        if (i & 1) res[i] = res[i] * 2 - 1;
        else res[i] *= 2;
    }
    return vector<int>(begin(res) + 1, end(res) - 1);
}
