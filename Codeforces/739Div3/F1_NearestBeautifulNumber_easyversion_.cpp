#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<ll> s1, s2; // Set of all 1 and 2 digit numbers
    ll x;

    for (int i = 1; i < 10; i++) {
        ll num = 0;
        for (unsigned int numberOfdigits = 1; numberOfdigits < 10; numberOfdigits++) {
            num = i + num * 10;
            s1.insert(num); //s has every single dig no. form 1 ,2 ...11 , 22...to 999999999 81 total digits as 10 to power 9 is upper constraint which is a 2 digit no.
        }
    }

    vector<int> digits;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (unsigned int numberOfdigits = 2; numberOfdigits < 10; numberOfdigits++) {
                int spaces = numberOfdigits - 2;
                for (int n = 0; n <= spaces; n++) {
                    digits.push_back(i);
                    digits.push_back(j);
                    int temp1 = n, temp2 = spaces - n;
                    while (temp1--) {
                        digits.push_back(i);
                    }
                    while (temp2--) {
                        digits.push_back(j);
                    }

                    sort(digits.begin(), digits.end());

                    do {
                        ll num = 0;
                        for (auto t : digits)
                            num = num * 10 + t;
                        s2.insert(num);
                    } while (next_permutation(digits.begin(), digits.end()));

                    digits.clear();
                }
            }
        }
    }
    set<ll> result;
    set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), inserter(result, result.end()));
    result.insert(1000000000);
    result.erase(0);
    s2 = result;

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        if (k == 1) {
            for (auto i : s1) {
                if (i >= n) {
                    x = i;
                    break;
                }
            }
        }

        if (k == 2) {
            for (auto i : s2) {
                if (i >= n) {
                    x = i;
                    break;
                }
            }
        }

        cout << x << "\n";
    }

    return 0;
}