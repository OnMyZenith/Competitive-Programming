#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long arr[n], moves = 0;

    cin >> arr[0];

    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        if (arr[i - 1] > arr[i]) {
            moves += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout << moves;

    return 0;
}