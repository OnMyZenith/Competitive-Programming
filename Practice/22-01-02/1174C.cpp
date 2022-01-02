#include <bits/stdc++.h>

using namespace std;
const int _ = 1e5 + 7;
bool prime[_];
int fact[_];
int res[_];

void SieveOfEratosthenes() {
    int n = _ - 1;
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.

    memset(prime, true, _ * sizeof(bool));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true) {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p) {
                fact[i] = p;
                prime[i] = false;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    SieveOfEratosthenes();
    map<int, int> mp;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) mp[i];
    }
    int idx = 1;
    for (auto &[i, j] : mp)
        j = idx++;

    for (int i = 2; i <= n; i++) {
        if (prime[i]) res[i] = mp[i];
        else {
            res[i] = mp[fact[i]];
            mp[i] = res[i];
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << res[i] << " \n"[i == n];
        assert(res[i] != 0);
    }
    return 0;
}