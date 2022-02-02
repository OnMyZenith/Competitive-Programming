// Floor Divide
template <class T> T fdivf(T &a, T &b) { return a / b - ((a ^ b) < 0 && a % b); }
