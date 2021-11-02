#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long q;
    cin >> q;
    long long k;
    while (q--) {
        cin >> k;

        long long digits = 1;
        while (k > (9 * digits * (long long)(pow(10, digits - 1)))) { // k> 1, 9, 189,.....
            k -= (9 * digits * (long long)(pow(10, digits - 1)));
            digits++;
        }
        if (digits == 1)
            cout << k << "\n";
        else {
            long long add = k / digits;
            long long rem = 0;
            long long posOfDig = k % digits;
            if (posOfDig)
                rem = 1;
            else
                posOfDig = digits;
            long long number = (long long)pow(10, digits - 1) + add - 1 + rem;

            number = number / (long long)pow(10, digits - posOfDig);
            number %= 10;
            cout << number << "\n";
        }
    }

    return 0;
}