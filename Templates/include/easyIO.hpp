// EasyIO
#ifndef ___EASY_IO
#define ___EASY_IO 1

// INPUT
template <class T, class U> void re(pair<T, U> &p);
template <class T> void re(vector<T> &v);
template <class T, size_t SZ> void re(array<T, SZ> &a);

template <class T>
void re(T &x) { cin >> x; }
void re(double &d) {
    string t;
    re(t);
    d = stod(t);
}
void re(long double &d) {
    string t;
    re(t);
    d = stold(t);
}
template <class T, class... U>
void re(T &t, U &...u) {
    re(t);
    re(u...);
}
template <class T, class U>
void re(pair<T, U> &p) { re(p.first, p.second); }
template <class T>
void re(vector<T> &x) { for (auto &a : x) re(a); }
template <class T, size_t SZ>
void re(array<T, SZ> &x) { for (auto &a : x) re(a); }
template <class T>
void rv(int n, vector<T> &x) {
    x.resize(n);
    re(x);
}

// TO_STRING
string to_string(char c) { return string(1, c); }
string to_string(const char *s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(bool b) {
#ifdef asr_debug
    return b ? "true" : "false";
#else
    return to_string((int)b);
#endif
}
string to_string(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < int(size(v)); i++)
        res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
    string res = "";
    for (int i = 0; i < SZ; i++)
        res += char('0' + b[i]);
    return res;
}
template <class T, class U>
string to_string(pair<T, U> p);
template <class T>
string to_string(T v) { // containers with begin(), end()
#ifdef asr_debug
    bool fst = 1;
    string res = "{";
    for (const auto &x : v) {
        if (!fst) res += ", ";
        fst = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    string res = "";
    for (const auto &x : v) {
        if (!fst) res += " ";
        fst = 0;
        res += to_string(x);
    }
    return res;
#endif
}

template <class T, class U>
string to_string(pair<T, U> p) {
#ifdef asr_debug
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
#else
    return to_string(p.first) + " " + to_string(p.second);
#endif
}

// OUTPUT
template <class T>
void pr(T x) { cout << to_string(x); }
template <class T, class... U>
void pr(const T &t, const U &...u) { // print without spaces
    pr(t);
    pr(u...);
}

void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T &t, const U &...u) { // print with spaces, with newline in the end
    pr(t);
    if (sizeof...(u)) pr(" ");
    ps(u...);
}
#endif // ___EASY_IO
