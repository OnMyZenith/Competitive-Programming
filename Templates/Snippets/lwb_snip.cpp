// Index(int) of lower_bound in a sorted vector
// Check result against SIZE of vector
template <class T> int lwbf(vector<T> &a, const T &b) { return int(lower_bound(all(a), b) - begin(a)); }
