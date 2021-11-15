#include <iostream>
#include <vector>
#include<cstring>

using namespace std;

string s, ops;
long long W[1000][1000][2];
bool ok[1000][1000][2];


long long ways(int i, int j, bool res) {
    if (ok[i][j][res]) return W[i][j][res];

    for (int k = i; k <= j - 1; k++) {
        long long tLeft = ways(i, k, true), fLeft = ways(i, k, false);
        long long tRight = ways(k + 1, j, true), fRight = ways(k + 1, j, false);
        if (ops[k] == '|') {
            if (res) {
                W[i][j][res] += tLeft * tRight;
                W[i][j][res] += tLeft * fRight;
                W[i][j][res] += fLeft * tRight;
            } else {
                W[i][j][res] += fLeft * ways(k + 1, j, false);
            }
        } else if (ops[k] == '&') {
            if (res) {
                W[i][j][res] += tLeft * tRight;
            } else {
                W[i][j][res] += fLeft * ways(k + 1, j, false);
                W[i][j][res] += tLeft * ways(k + 1, j, false);
                W[i][j][res] += fLeft * tRight;
            }
        } else if (ops[k] == '^') {
            if (res) {
                W[i][j][res] += tLeft * ways(k + 1, j, false);
                W[i][j][res] += fLeft * tRight;
            } else {
                W[i][j][res] += tLeft * tRight;
                W[i][j][res] += fLeft * ways(k + 1, j, false);
            }
        }
    }
    ok[i][j][res] = true;
    return W[i][j][res];
}

int64_t solve(const std::string &str, const std::string &o) {
    s = str, ops = o;
    cout<<s<<'\n';
    cout<<o<<'\n';
    for (int i = 0; i < (int)s.length(); i++)
        W[i][i][true] = (s[i] == 't'), ok[i][i][true] = true, W[i][i][false] = (s[i] == 'f'), ok[i][i][false] = true;
    long long res = ways(0, (int)s.length() - 1, true);

    memset(ok, 0, sizeof(ok[0][0][0]) * 1000 * 1000 * 2);
    memset(W, 0, sizeof(W[0][0][0]) * 1000 * 1000 * 2);
  
    cout<<s<<'\n';
    cout<<o<<'\n';
    cout<<res<<'\n';

    return res;
}

// int main() {
//     cout << solve("tft", "&&") << "\n";
//     cout << solve("tft", "^&") << "\n";
//     cout << solve("ttftff", "|&^&&") << "\n";
//     cout << solve("ttftfftf", "|&^&&||") << "\n";
//     cout << solve("ttftfftft", "|&^&&||^") << "\n";
//     cout << solve("ttftfftftf", "|&^&&||^&") << "\n";
//     return 0;
// }