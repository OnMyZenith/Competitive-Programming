template <class T> T powf(T a, ll b) { T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r; }
