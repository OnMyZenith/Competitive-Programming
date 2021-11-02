#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    cout << unique(a.begin(), a.end()) - a.begin()  << '\n';
    return 0;
}