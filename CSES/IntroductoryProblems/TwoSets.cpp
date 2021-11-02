#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 4 == 0) {
        cout << "YES\n";
        cout << n / 2 << '\n';
        for (int i = 1; i <= n; i += 4)
            cout << i << " " << i + 3 << " ";
        cout << '\n'
             << n / 2 << '\n';
        for (int i = 2; i <= n; i += 4)
            cout << i << " " << i + 1 << " ";
        cout << '\n';
    } else if ((n + 1) % 4 == 0) {
        cout << "YES\n";
        cout << (n + 1) / 2 - 1 << '\n';
        for (int i = 1; i < (n + 1) / 4; i++)
            cout << i << " " << n + 1 - i << " ";
        cout << 3 * (n + 1) / 4 << '\n'
             << (n + 1) / 2 << '\n';
        for (int i = ((n + 1) / 4) + 1; i < (n + 1) / 2; i++)
            cout << i << " " << n + 1 - i << " ";
        cout << (n + 1) / 4 << " " << (n + 1) / 2 << '\n';
    } else
        cout << "NO\n";
    return 0;
}