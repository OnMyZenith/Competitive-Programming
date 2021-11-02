#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string dna;
    cin >> dna;
    long long count = 1;
    long long max = 1;

    for (auto it = dna.begin(); it != dna.end(); it++) {
        while ((it != --dna.end()) && (*it == *(it + 1))) {
            it++;
            count++;
            if (max < count) max = count;
        }
        count = 1;
    }
    cout << max;
    return 0;
}