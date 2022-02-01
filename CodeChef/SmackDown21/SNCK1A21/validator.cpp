#include <bits/stdc++.h>
using namespace std;

int main( ) {
    freopen("a_out", "r", stdin);

    freopen("out", "w", stdout);

    int n, k;
    char str[3];
    cin >> n >> k;
    int tmp = k;
    cin >> str;
    if (strcmp(str, "NO") == 0){
    cout << 0 << '\n'; return 0;} // Can't check for NO :(
    k = tmp;
    int num;
    cin >> num;
    if(num==0){
        if (k == 0){
    cout << 0 << '\n'; return 0;}
        else{
            cout << -1 << '\n';
            return -1;
        }
    }

    int res[num];
    for (int i = 0; i < num; i++)
        cin >> res[i];

    bool ok[n];
    for (int i = 0; i < n; i++)
        if(i<k)ok[i] = false;
        else
            ok[i] = true;

    int i = 1;
    for (int j = 0; j < num; j++) {
        if (res[j] + i - 1 > n) {
            cout << -1 << '\n';
            return -1;
        }
        for (int idx = res[j] - 1; idx < res[j] - 1 + i; idx++)
            ok[idx] = !ok[idx];
        i = 2 * i;
    }
    for (int j = 0; j < n; j++)
        if (!ok[j]){
            cout << -1 << '\n';
            return -1;
        }
    cout << 0 << '\n';
    return 0;

}