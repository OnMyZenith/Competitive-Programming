#include <bits/stdc++.h>

using namespace std;
int gcdArr(vector<int> &v, int idx) {
    if (idx == v.size() - 1) return v[idx];
    int a = v[idx];
    int b = gcdArr(v, idx + 1);
    return __gcd(a, b);
}
int main() {
    vector<int> v = {15, 21, 35};
    cout << gcdArr(v, 0);
    return 0;
}