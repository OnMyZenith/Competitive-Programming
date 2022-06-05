// Bit Opertations
constexpr int pct(int x) { return __builtin_popcount(x); }                                      // # of bits set
constexpr int log_2(int x) { return x > 0 ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int log_2_ceil(int x) { return log_2(x) + int(pct(x) != 1); }                         // Ceil of log_2(x);
constexpr int enveloping_pow_2(int x) { return x > 0 ? 1 << log_2_ceil(x) : 0; }                // 16->16, 13->16, (x<=0)->0; Smallest number that's a power of 2, that's not smaller than x
