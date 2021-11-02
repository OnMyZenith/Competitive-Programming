#include <iostream>

using namespace std;

int main() {
    int res = 200000;
    int cnt = 0;
    while (res) {
        cnt++;
        res >>= 1;
    }
    cout << cnt << '\n';
    return 0;
}