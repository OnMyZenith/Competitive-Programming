template <class T> int lwbf(vector<T> &a, const T &b) { return int(lower_bound(all(a), b) - begin(a)); }
