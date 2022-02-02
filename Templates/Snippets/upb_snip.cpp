template <class T> int upbf(vector<T> &a, const T &b) { return int(upper_bound(all(a), b) - begin(a)); }
