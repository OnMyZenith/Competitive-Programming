// Confirm if deletion from set/multiset was successful
// Because multiset.erase(t) will erase all occurances of t!!
template <class T, class U> bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    t.erase(it); return true;
}