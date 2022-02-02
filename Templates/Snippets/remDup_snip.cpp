template <class T> void remDupf(vector<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); }
