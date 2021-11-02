#include <bits/stdc++.h>

using namespace std;

char triangle(const string &row) {
    size_t sz = row.size();
    if (sz == 1) return row[0];
    map<char, int> mp;
    mp['R'] = 0, mp['G'] = 0, mp['B'] = 0;

    for (size_t i = 0; i < sz - 1; i++) {
        if (row[i] == row[i + 1]) {
            mp[row[i]]++;
            continue;
        }
        mp[row[i]]--;
        mp[row[i + 1]]--;
    }

    cout << row << "\n";
    if ((mp['R'] > mp['B'] && mp['R'] > mp['G']) || (mp['G'] != 0 && mp['G'] == mp['B']))
        return 'R';
    if ((mp['B'] > mp['R'] && mp['B'] > mp['G']) || (mp['G'] != 0 && mp['G'] == mp['R']))
        return 'B';
    if ((mp['G'] > mp['B'] && mp['G'] > mp['R']) || (mp['R'] != 0 && mp['R'] == mp['B']))
        return 'G';
    return '0';
}

int main() {
    // cout << triangle("RBGGRBGBRRRRRGGRRGGGGBGGGBGGBGRBBRGGRRBRGBRBBBRRGBGRGBBBGBGGRGGBBRBBRGRBGBGGGBBBBRRRRRGBBRBRRRRBGBRGGRGRBGBGRGGBGRGBRRBRRBRRBGRRGRRBGBRBRBRBGBBBBRRRRBGGBBGGRBRBRGBRRRBGRBRGBBBRGBRBBRGGBGBRRRRBGGBBGGGBGBGRGRGRRBRBBGRBBGRGBBRGRBRBGBBBGGRRBBGGBBRBGBGBGBRRGGGBGBBBGBGBGBRBGBRRBRBRRGBGBRRGGGGBBGGGGRGRRBBBBBRGRRGBRBGRBGGGGRGRBGGGBRBBRGBBGRGGGGRBRBRBGRGBRGRGBRRGRBBBRBBGRGRBBGRRGRBBRBRBGRRGRRRBRBGRBRBRBBRGGRBRGRRRBGBGGRBBGBBGRRGRGRGGRGRBBRBGRRGRGGGGGGGBGRRGRBRBRGGGRBGRRRGGBGGRBRBGBRRRRBRGBRGRBBBBBRBRGGGRBRBBGGRRBGBRGBBGRGBRGGBBGBBBGGGGBRGGBBBGGGBRGBBBRGBBBBGGGGRGRBBBBGGBRGGBRGBBRBGGRGGRGRGRGRBBBBRRRBRGRGRGGGGGRBGBGRBRRBGRRRBBRRRRRRGGBGBGBGBGBGRGGRBRBRRBGRRGGRBBGRRGRGBRBBBGGBRRRRRRGGGRRGRGGBGRGGGBRGRRBRBRRRGGGRBRBRGBGGGRBBGGBRRBRGBBGRRBGBGBBRRRGBBRGGGRGRGRGBRGBRGRRGRBGBBGRRGBBGBRRGBGBGBGGRRGRRGBGRBRRGRRGGRGRGRRBBRBRRGBRBRRBRBBGBBGGBBRBRRBGRGGRBGGBBBBRRRBRGGBRBRGGRRGGRBRRGGGRRBBRGBRBBGRGRRBBRGBGGRBBBRRRBGGRGRRRRBBGRGBRGGGBGRGRGGRBBGBBRBBBBRBGBRBRGGBBGRGBRRBGRRRRBGBRRBBRBGBBBGRRRBRGBBGRRGRGBGGBRGBGRGRRRBRGGGGBGBGGBBBRRRBRGGBRRGGRRGGBBBRRGBRBBGGBRGRGGRBGGGGGGRRBRGBBGBRRRGBBBGBBRRRGRRRGBBRGRRRGBRGGRBGRRGGBRGBRGRBGGRBRBRBRGBGGRRBBBGRBBGGRBGRGBGBRGRGGRRRBRGGGRRGBBGBRGGRRRBBRRBRBBBGGBGGRGBBGRRRGBRGRRBGGGGGBGBBGGGBGBGGRGGBBGRGGGBGBBGRGBBGGGGRRBRGBBRGGGRRRGBBRGGBGBGRBRBRBGGBRRBGRBBGGBRGGBGBBRGGBBGBGGGRRBRGBBBBBGBRGBRRGGBRGGGBBRGRBBRRRGGBBGRGRBRGBRBRBGBGRRGBBBRGRGBRBRRGBGGRGGBRBBGGRRRGGGGRBGBBBGBRBBBBGRBBGBGRGRRBGRBBBRGGRRRRRRRRRRBGRBBRBRGRRGRGRBGBGBGGGBGBRRBRRBBGBBBGRBBGGRRGBBGGRRBGBBGBBGRRRRBRRRBGBBRRBRBBBRGBGGGGGRBGGRBBGBRBBBRBBRBGGGBGRGBBRRGBBRGRGGRBRRBRGBBRRGRGGRRBGBBGRRGBBRGRGGGBRRBBGBRGRGGBGBBBGGBBRRRBGGRRRBBGGBRBGGGRBBRBGRGRBGGBRGBGRGBGRBRGBRGRBRRRBGBBGGBGRRGRBRBRGBRRBRGGGRGBGRBRGBBRGRGGGRBBBRRGBRGGGGRRBRRRRRGBBBBRBGRGRRRBRBRGBRRBBGRGGRBGRRRRRRGRBGBBBRGRBRGRGBBRGBBBRGGRBBRRBGRBGRBGGGGGBGBRRGRGGRGBGBBBGRBGRRRGGBBBBGGGBGRRRGGRBRBRBBBGRBBRRRBBRGBBGRGRGGBRRRRBBBRGBRRRGBGGRGGGRRRGRBRRGBRBRRGBRBBGGRBBRRGGBBBRBRBBRRBGRRGGGRGBRGGGGRRBGBRGGRBRRGGRRGRRBGBRBBRRRGGBBRBGBRBBRGBRRGBGRRRRBBGBGBRBGBBGBGBRGBBBGBRBGRGBRGBRGRRRRRRBBRGRGRRRRRBGBBRGRBRGGRGRBBGBBBGRBRRRRGGRBRBBRGGGGBRRGBGRRRBRBBRBBGRGRGBRBBRRGBBBBRRRRBRRBGGBRBGRGGGBRBRBBRRRRRRBRGRGGGRGBBGRGRBRBRRRRGBBBRRBRGGGRBGGBGRGGBRBRBGRRBRGRGGBBBGRRRBRGGBRRRBGRRGRBRGGBBBBGGBRRGGGGBBRRBGGRGBRGGGBGBRRBRRRGBBRRRGRBGRGGBBGGBBRBRBRRBBRRBRBRRBRGGRGBBBGBBBRBGRGBGBRGBGBBBBBRBRGRBRGGRBGRRBRBBBBGBRRGGBGGBGGGBBGBRBGGRBGRGRRGBRRGRGGBGBGRBRGBRBGGRBRRGBGRBBGBRBGGRBBGRRGBRBGGRRRRBGGGGRGGBBRBRRBRBGBRBGRRBBBBBRRGBBRGBGBBBGRBGBRGRRBBBRRGRBGBGGBGGBRRGBRGGRRBRRBGGBRGBGRBGGBRRGGGGGBBBBGGGBBGGGRBRGGBRGBRBBGRGRGBBRRBRGGGGRGBBBBBGGGBBGRBRGBBBRBRGRRBGBGRBRRBBBGRRGRRRRBBRBGBRRRGRGGRRRGGGBRRBRGGGRGBRBGGGRBRGBBBRGRGGGBBRRRGRRBBRGBGRRRRRBRBGBBRGRGRGGGRGBGBBGBBBGBGBRGRBBRGBRGGRRBRGGGRRRRGGBGGBRBBRRBRRGBRGGGBBGRRBGGGGBBRBGGBBGGRBRGRGGRRBBRGGRRGBGRGGRBGBRRBBGBBBRBGGRBBBRRGGRGRRGBGRGBBGRGBGRGRBGBGGGRGBGRRBBGBGRGGGRRGGBRBGBRRRRBBRRGBBGRGGGBRRRGBBRGRBBGRGBGBBGGBGRBGBRRBBBBBGRRGRGBGGRGBRRRRBBRGBRBRRBRGRBRBRGRBRRRGBGGBBGRBGBRGBBBGRBBRGRRRBGBBGBGGGBBGBBRRGBBBGBRBGBBGBRGGGGGGRBBGRGRBBBBGGBRBGRBGBBRRRBBBRGRRGRBGBRRGBRGRRGRBBRRBRGRGRRRRBBGGRGRBGGBRBRGRGGBGBGBRBRBRRBGRBRBBBRRRGBGGRRGBBGGGRGBBGGRRBRGGGRBRRBGRGRGGRRRBBBBBGGBRRGGRGBGBGRBBRRBGRGRGBBRBBBBGBGBRBRRRRBRGGBGGRGGGRBBRBGBBRGGRGRRGGGRGGRGBGRGGGRRRRBRBGRGBBBRGRGGBBGGGGRGRRGBBGRBGRGGBBRBGGBGBGBBBRGRBGRRBGRBBRBGRRRBBGGGBBRRRBBBRRGGBGBGRBGBRRGGGBGGGRGGRBGGBRGRGRBRGGBGGGBBBRGBRRGBGRRBRRGRRBGRRGGBRGBBRGBRBRRRGBRRRGRRBGGBGRRGGBBGGGGBRGBRBRBGRBBRGBBRRRGGRGGBRGGBRRGRBGGBBRGBRGRGRBBGGRBGBGBGBRRBGBRGGBGGRRGRGBRBBRRGGRBRBGGBBRRBRRGGRRRGRBBBGRGRRGBGBBRGGGBBGBBGRRRGRGRGRRGBGBRBGRGRRGRBRBGRBGBBGRGBGGGRBBBGBBRRBBBBGBRBBGRGGBGRBRRBBBBBRBRBGBGBGRBRRBRBBGRRRBRGBGGBGGGBRRGGBBGGRGBRGRBRGRGBRBGRGBRRRRBGRGBRGBBRGBRBBGRBBGBRGRGRRGRGBRBBBBRGGRGBRBBRGRBRBBGGRRBRBBGBRGBBGRGRGRGBRGBGGRRGBBRRRBGBBGBRBBRGRBBBBRGGGRBRRRBGBRGRBRRBGBRGBGRRRBBRRRGBBBRRRRGGRRGBGBBBRRGBGBRBBBRGGBRRBGRRBBGBRRBGRBBRBRRGRGRGGGBBGBBGGGGRGRRGGRRBRBRRRGGBBRRRGBGBBGRGBBBGRRRBGGBGRBBGRBGRBGGRGBRGBGRBRBGBBGGGBRRRRBBGGGGRRGGBRBGRRGRBRGGGBBBBGRBBGGGBRRGGGRGRRBRRRRRGGGRGBGRGGRRBRBRRRGBGBRGBBBGRRGRBGRGGGBBGRRRRRRGGBGBBBBBBBRGBRGBGBGRGRRBRRRBGBGRGBGGGRGBBBRBBBBGGRGBGBBBGRGBBBRGBGRGBBGBGGGBRGGBGGBRRBRGRGBRBRGBBBGGBRGBGRGRBRRGGBBRBBGRGRRGRRRRRBGGBBRGRBBRBBGBRRBRRRGBBBRRRBGBBRRGGRRBRRBRRRBGBGBBRGBRRGRBRBGBRGGGBBRRRRRGGGBRRBGRRRGGBRGRBBBRGGBGGBGGRBRBRGBGRGBGBGRBGGRGGBBBBGRGBBBBGGGBRBGRRRBBGRRRGRBBRGBBBRRBBGBGRRGRBBRRRGRRGGRRGBRBGGGBGRGGGRRGBBGBBBRBRBBBRRRBRGGBBRGGRBRGGGRRRBBBBRBRRRRRGRBGRGGRBRBBGBBBRRRGRRGRRGRGBGBRBGBBRGRRGBBBRBGGRBRRRGRGRGRRBBRGBGBRRRBGGGRBRBBBGGRBBGGBBBRGBRRBGRRRGRGRBBBBGRBGBRRBBBBBBBRBRGBBGBBRGRGRRBRBBRGBRGGRBRBBBGGRBGRGGRRBBGRBGGBGGRRBRGRRGBBBGGBGBRRBGRGGBBRBRGRRBBBBRBBRBBBBGBRGRRRBGBRBBGGRBBRBGRBBRRBGBBRRGRBGGBGRBGBBGGGGGGGBRGBRGGGGGBBRRBGBBRBBBRBGGRRRRGRRRRGGRGRGRRGGRGRBBGBGBBRGBGBRBRGGRRRGBRRRGGBGBRGGBGGGRBRGRRGRGRGBGBGGRGGRRGBGBGBGRGRRRGBGBGRRBBBGBRBGBGGRRRGBBGGBGBRGRRGRBBRBGGRGBRBBBGRBBBBGRGGGRBGBRRBBBGBGRBRBRRBBGRRGBBRGRBRBBGGRBGRBRBGRBGGBRRBGGRRRRGBGGRRGGBGBGGGBRRRBBGBRBBGRRBBRGGGBGRRGBGGGBBBRRBBRGBRRGBBGBGBRRBBRRRBRBRRBRBBRGBGRGBRGBBRGGRBRRBGRGRRRGRRGBBRGRGGBBRRGRBRBRBRRRGRGBGGRBGGBBBBBGRGRGRBBBBBBRBRRGGBRBRGBRBRRBBBGRGBBBBGGGGGGGGBBBGRRRGBGGBGGBGRRRBBRGGGGRGRGBRGRBGRRRRBGGRBGGRGGBGGGRGRGBGGBRGBBGBRBGBGGRRBRRRGBBBBRGRGRBRBRGRBGRGRGRGBBBBBRBGRBRBBBRGBBBRBBRRRRBGBRRBBBGBRRRRRGGRRGGGGBGGGBGGBGRBBRGGRRBRGBRBBBRRGBGRGBBBGBGGRGGBBRBBRGRBGBGGGBBBBRRRRRGBBRBRRRRBGBRGGRGRBGBGRGGBGRGBRRBRRBRRBGRRGRRBGBRBRBRBGBBBBRRRRBGGBBGGRBRBRGBRRRBGRBRGBBBRGBRBBRGGBGBRRRRBGGBBGGGBGBGRGRGRRBRBBGRBBGRGBBRGRBRBGBBBGGRRBBGGBBRBGBGBGBRRGGGBGBBBGBGBGBRBGBRRBRBRRGBGBRRGGGGBBGGGGRGRRBBBBBRGRRGBRBGRBGGGGRGRBGGGBRBBRGBBGRGGGGRBRBRBGRGBRGRGBRRGRBBBRBBGRGRBBGRRGRBBRBRBGRRGRRRBRBGRBRBRBBRGGRBRGRRRBGBGGRBBGBBGRRGRGRGGRGRBBRBGRRGRGGGGGGGBGRRGRBRBRGGGRBGRRRGGBGGRBRBGBRRRRBRGBRGRBBBBBRBRGGGRBRBBGGRRBGBRGBBGRGBRGGBBGBBBGGGGBRGGBBBGGGBRGBBBRGBBBBGGGGRGRBBBBGGBRGGBRGBBRBGGRGGRGRGRGRBBBBRRRBRGRGRGGGGGRBGBGRBRRBGRRRBBRRRRRRGGBGBGBGBGBGRGGRBRBRRBGRRGGRBBGRRGRGBRBBBGGBRRRRRRGGGRRGRGGBGRGGGBRGRRBRBRRRGGGRBRBRGBGGGRBBGGBRRBRGBBGRRBGBGBBRRRGBBRGGGRGRGRGBRGBRGRRGRBGBBGRRGBBGBRRGBGBGBGGRRGRRGBGRBRRGRRGGRGRGRRBBRBRRGBRBRRBRBBGBBGGBBRBRRBGRGGRBGGBBBBRRRBRGGBRBRGGRRGGRBRRGGGRRBBRGBRBBGRGRRBBRGBGGRBBBRRRBGGRGRRRRBBGRGBRGGGBGRGRGGRBBGBBRBBBBRBGBRBRGGBBGRGBRRBGRRRRBGBRRBBRBGBBBGRRRBRGBBGRRGRGBGGBRGBGRGRRRBRGGGGBGBGGBBBRRRBRGGBRRGGRRGGBBBRRGBRBBGGBRGRGGRBGGGGGGRRBRGBBGBRRRGBBBGBBRRRGRRRGBBRGRRRGBRGGRBGRRGGBRGBRGRBGGRBRBRBRGBGGRRBBBGRBBGGRBGRGBGBRGRGGRRRBRGGGRRGBBGBRGGRRRBBRRBRBBBGGBGGRGBBGRRRGBRGRRBGGGGGBGBBGGGBGBGGRGGBBGRGGGBGBBGRGBBGGGGRRBRGBBRGGGRRRGBBRGGBGBGRBRBRBGGBRRBGRBBGGBRGGBGBBRGGBBGBGGGRRBRGBBBBBGBRGBRRGGBRGGGBBRGRBBRRRGGBBGRGRBRGBRBRBGBGRRGBBBRGRGBRBRRGBGGRGGBRBBGGRRRGGGGRBGBBBGBRBBBBGRBBGBGRGRRBGRBBBRGGRRRRRRRRRRBGRBBRBRGRRGRGRBGBGBGGGBGBRRBRRBBGBBBGRBBGGRRGBBGGRRBGBBGBBGRRRRBRRRBGBBRRBRBBBRGBGGGGGRBGGRBBGBRBBBRBBRBGGGBGRGBBRRGBBRGRGGRBRRBRGBBRRGRGGRRBGBBGRRGBBRGRGGGBRRBBGBRGRGGBGBBBGGBBRRRBGGRRRBBGGBRBGGGRBBRBGRGRBGGBRGBGRGBGRBRGBRGRBRRRBGBBGGBGRRGRBRBRGBRRBRGGGRGBGRBRGBBRGRGGGRBBBRRGBRGGGGRRBRRRRRGBBBBRBGRGRRRBRBRGBRRBBGRGGRBGRRRRRRGRBGBBBRGRBRGRGBBRGBBBRGGRBBRRBGRBGRBGGGGGBGBRRGRGGRGBGBBBGRBGRRRGGBBBBGGGBGRRRGGRBRBRBBBGRBBRRRBBRGBBGRGRGGBRRRRBBBRGBRRRGBGGRGGGRRRGRBRRGBRBRRGBRBBGGRBBRRGGBBBRBRBBRRBGRRGGGRGBRGGGGRRBGBRGGRBRRGGRRGRRBGBRBBRRRGGBBRBGBRBBRGBRRGBGRRRRBBGBGBRBGBBGBGBRGBBBGBRBGRGBRGBRGRRRRRRBBRGRGRRRRRBGBBRGRBRGGRGRBBGBBBGRBRRRRGGRBRBBRGGGGBRRGBGRRRBRBBRBBGRGRGBRBBRRGBBBBRRRRBRRBGGBRBGRGGGBRBRBBRRRRRRBRGRGGGRGBBGRGRBRBRRRRGBBBRRBRGGGRBGGBGRGGBRBRBGRRBRGRGGBBBGRRRBRGGBRRRBGRRGRBRGGBBBBGGBRRGGGGBBRRBGGRGBRGGGBGBRRBRRRGBBRRRGRBGRGGBBGGBBRBRBRRBBRRBRBRRBRGGRGBBBGBBBRBGRGBGBRGBGBBBBBRBRGRBRGGRBGRRBRBBBBGBRRGGBGGBGGGBBGBRBGGRBGRGRRGBRRGRGGBGBGRBRGBRBGGRBRRGBGRBBGBRBGGRBBGRRGBRBGGRRRRBGGGGRGGBBRBRRBRBGBRBGRRBBBBBRRGBBRGBGBBBGRBGBRGRRBBBRRGRBGBGGBGGBRRGBRGGRRBRRBGGBRGBGRBGGBRRGGGGGBBBBGGGBBGGGRBRGGBRGBRBBGRGRGBBRRBRGGGGRGBBBBBGGGBBGRBRGBBBRBRGRRBGBGRBRRBBBGRRGRRRRBBRBGBRRRGRGGRRRGGGBRRBRGGGRGBRBGGGRBRGBBBRGRGGGBBRRRGRRBBRGBGRRRRRBRBGBBRGRGRGGGRGBGBBGBBBGBGBRGRBBRGBRGGRRBRGGGRRRRGGBGGBRBBRRBRRGBRGGGBBGRRBGGGGBBRBGGBBGGRBRGRGGRRBBRGGRRGBGRGGRBGBRRBBGBBBRBGGRBBBRRGGRGRRGBGRGBBGRGBGRGRBGBGGGRGBGRRBBGBGRGGGRRGGBRBGBRRRRBBRRGBBGRGGGBRRRGBBRGRBBGRGBGBBGGBGRBGBRRBBBBBGRRGRGBGGRGBRRRRBBRGBRBRRBRGRBRBRGRBRRRGBGGBBGRBGBRGBBBGRBBRGRRRBGBBGBGGGBBGBBRRGBBBGBRBGBBGBRGGGGGGRBBGRGRBBBBGGBRBGRBGBBRRRBBBRGRRGRBGBRRGBRGRRGRBBRRBRGRGRRRRBBGGRGRBGGBRBRGRGGBGBGBRBRBRRBGRBRBBBRRRGBGGRRGBBGGGRGBBGGRRBRGGGRBRRBGRGRGGRRRBBBBBGGBRRGGRGBGBGRBBRRBGRGRGBBRBBBBGBGBRBRRRRBRGGBGGRGGGRBBRBGBBRGGRGRRGGGRGGRGBGRGGGRRRRBRBGRGBBBRGRGGBBGGGGRGRRGBBGRBGRGGBBRBGGBGBGBBBRGRBGRRBGRBBRBGRRRBBGGGBBRRRBBBRRGGBGBGRBGBRRGGGBGGGRGGRBGGBRGRGRBRGGBGGGBBBRGBRRGBGRRBRRGRRBGRRGGBRGBBRGBRBRRRGBRRRGRRBGGBGRRGGBBGGGGBRGBRBRBGRBBRGBBRRRGGRGGBRGGBRRGRBGGBBRGBRGRGRBBGGRBGBGBGBRRBGBRGGBGGRRGRGBRBBRRGGRBRBGGBBRRBRRGGRRRGRBBBGRGRRGBGBBRGGGBBGBBGRRRGRGRGRRGBGBRBGRGRRGRBRBGRBGBBGRGBGGGRBBBGBBRRBBBBGBRBBGRGGBGRBRRBBBBBRBRBGBGBGRBRRBRBBGRRRBRGBGGBGGGBRRGGBBGGRGBRGRBRGRGBRBGRGBRRRRBGRGBRGBBRGBRBBGRBBGBRGRGRRGRGBRBBBBRGGRGBRBBRGRBRBBGGRRBRBBGBRGBBGRGRGRGBRGBGGRRGBBRRRBGBBGBRBBRGRBBBBRGGGRBRRRBGBRGRBRRBGBRGBGRRRBBRRRGBBBRRRRGGRRGBGBBBRRGBGBRBBBRGGBRRBGRRBBGBRRBGRBBRBRRGRGRGGGBBGBBGGGGRGRRGGRRBRBRRRGGBBRRRGBGBBGRGBBBGRRRBGGBGRBBGRBGRBGGRGBRGBGRBRBGBBGGGBRRRRBBGGGGRRGGBRBGRRGRBRGGGBBBBGRBBGGGBRRGGGRGRRBRRRRRGGGRGBGRGGRRBRBRRRGBGBRGBBBGRRGRBGRGGGBBGRRRRRRGGBGBBBBBBBRGBRGBGBGRGRRBRRRBGBGRGBGGGRGBBBRBBBBGGRGBGBBBGRGBBBRGBGRGBBGBGGGBRGGBGGBRRBRGRGBRBRGBBBGGBRGBGRGRBRRGGBBRBBGRGRRGRRRRRBGGBBRGRBBRBBGBRRBRRRGBBBRRRBGBBRRGGRRBRRBRRRBGBGBBRGBRRGRBRBGBRGGGBBRRRRRGGGBRRBGRRRGGBRGRBBBRGGBGGBGGRBRBRGBGRGBGBGRBGGRGGBBBBGRGBBBBGGGBRBGRRRBBGRRRGRBBRGBBBRRBBGBGRRGRBBRRRGRRGGRRGBRBGGGBGRGGGRRGBBGBBBRBRBBBRRRBRGGBBRGGRBRGGGRRRBBBBRBRRRRRGRBGRGGRBRBBGBBBRRRGRRGRRGRGBGBRBGBBRGRRGBBBRBGGRBRRRGRGRGRRBBR");
    cout << triangle("B");
    return 0;
}