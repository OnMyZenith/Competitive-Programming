// Z-function
// Z[i] is the length of the longest string that is, a prefix of s and a prefix of the suffix of s starting at i.
vector<int> z_function(const string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);

        while (z[i] + i < n && s[z[i] + i] == s[z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
    }
    return z;
}
