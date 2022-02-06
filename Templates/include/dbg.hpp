#include "easyIO.hpp"

#ifndef ___DBG
#define ___DBG 1

void DBG() { cerr << "]" << endl; }
template <class T, class... U > void DBG(const T &t, const U &...u) {
    cerr << to_string(t);
    if (sizeof...(u)) cerr << ", ";
    DBG(u...);
}
// chk -> fake assert
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
// #define chk(...) \
//     if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" << __FUNCTION__ << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << '\n', exit(0);

#endif // ___DBG