// Index(int) of upper_bound in a sorted vector
// Check result against SIZE of vector
template <class T> int upbf(vector<T> &a, const T &b) { return int(upper_bound(a.begin(), a.end(), b) - begin(a)); }
