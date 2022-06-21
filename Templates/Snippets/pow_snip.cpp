// Calculate x^y Fast
template <class T> T powfun(T a, long long b) { T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r; }
