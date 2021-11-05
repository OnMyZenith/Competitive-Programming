#pragma GCC optimize("Ofast")
// #pragma GCC target("fma")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string path;
int poss = 0;
vector<bool> mp(49, true);

// void printGrid(vector<bool> mp) {
//     for (ll i = 0; i < 7; i++)
//         for (ll j = 0; j < 7; j++)
//             cout << mp[i * 7 + j]<<" \n"[j==6];
//     cout << '\n';
// }

void driver(int prevPos, int moveNo) {
    mp[prevPos] = false;
    // printGrid(mp);
    if (prevPos == 42) {
        if (moveNo == 48) {
            poss++;
        }
    } else {

        if (((path[moveNo] == '?' || path[moveNo] == 'U') && prevPos > 6 && mp[prevPos - 7]) && !((prevPos < 14 || (!mp[prevPos - 14])) && (prevPos % 7) > 0 && (prevPos % 7) < 6 && mp[prevPos - 7 - 1] && mp[prevPos - 7 + 1])) driver(prevPos - 7, moveNo + 1);
        if (((path[moveNo] == '?' || path[moveNo] == 'D') && prevPos < 42 && mp[prevPos + 7]) && !((prevPos > 34 || (!mp[prevPos + 14])) && (prevPos % 7) > 0 && (prevPos % 7) < 6 && mp[prevPos + 7 - 1] && mp[prevPos + 7 + 1])) driver(prevPos + 7, moveNo + 1);
        if (((path[moveNo] == '?' || path[moveNo] == 'L') && (prevPos % 7) > 0 && mp[prevPos - 1]) && !(((prevPos % 7) < 2 || (!mp[prevPos - 2])) && prevPos > 6 && prevPos < 42 && mp[prevPos - 1 - 7] && mp[prevPos - 1 + 7])) driver(prevPos - 1, moveNo + 1);
        if (((path[moveNo] == '?' || path[moveNo] == 'R') && (prevPos % 7) < 6 && mp[prevPos + 1]) && !(((prevPos % 7) > 4 || (!mp[prevPos + 2])) && prevPos > 6 && prevPos < 42 && mp[prevPos + 1 - 7] && mp[prevPos + 1 + 7])) driver(prevPos + 1, moveNo + 1);
    }
    mp[prevPos] = true;
}

int main() {
#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin >> path;
    driver(0, 0);
    cout << poss << '\n';

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}