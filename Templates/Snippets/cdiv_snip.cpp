template <class T> T cdivf(T &a, T &b) { return a / b + ((a ^ b) > 0 && a % b); }
