// KMP
// for s[:i], pi[i] = length of longest proper prefix thats also a suffix, i.e. s[:pi[i] - 1] == s[i - (pi[i] - 1):]
vector<int> prefix_function(const string &s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
