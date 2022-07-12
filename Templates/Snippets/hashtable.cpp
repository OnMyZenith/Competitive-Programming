// PBDS hash table with custom hash, faster than unordered map and set by 3x, uses 1.5x more memory
#include <bits/extc++.h>
using namespace __gnu_pbds;

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }

    // // Comment everything above for this to work
    // // Won't work with debug flags
    // static __uint128_t splitmix64(__uint128_t x) {
    //     // http://xorshift.di.unimi.it/splitmix64.c
    //     x += 0x9e3779b97f4a7c15 * 0x9e3779b97f4a7c15;
    //     x = (x ^ (x >> 60)) * 0xbf58476d1ce4e5b9 * 0xbf58476d1ce4e5b9;
    //     x = (x ^ (x >> 57)) * 0x94d049bb133111eb * 0x94d049bb133111eb;
    //     return x ^ (x >> 62);
    // }
    // __uint128_t operator()(__uint128_t x) const {
    //     static const __uint128_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    //     return splitmix64(x + FIXED_RANDOM);
    // }
};

template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;
