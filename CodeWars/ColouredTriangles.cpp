#include <bits/stdc++.h>

using namespace std;

std::string triangle(std::string row_str) {
    auto start = chrono::steady_clock::now();
    for (size_t length = row_str.size(); length > 1; length--) {
        for (unsigned int i = 0; i <= length - 2; i++) {
            if (row_str[i] == row_str[i + 1]) continue;
            row_str[i] = 219 - row_str[i] - row_str[i + 1];
        }
    }
    row_str.erase(row_str.begin() + 1, row_str.end());
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";
    return row_str;
}
int main() {
    cout << triangle("GRRRBGBRGRRRBGBRGBRBRGBRBRRBBGBGGRBGRBGGBRBBGRBBRRRGBBBRRGRRBGBRGGGGGGGGGGGBGGRBGGGBGRBGGRBGGGGRRGBBRRRGRBGGRBGBRRGGGGGRBRBRRGGRBGRRBRGBRGBRRGRBBGGRRBGRGRRGBBGBGBRRRBGGGRBRBBBGGRBBGGBBBRGBRRBGRRRGRGRBBBBGRBGBRRBBBBBBBRBRGBBGBBRGRGRRBRBBRGBRGGRBRBBBGGRBGRGGRRBBGRBGGBGGRRBRGRRGBBBGGBGBRRBGRGGBBRBRGRRBBBBRBBRBBBBGBRGRRRBGBRBBGGRBBRBGRBBRRBGBBRRGRBGGBGRBGBBGGGGGGGBRGBRGGGGGBBRRBGBBRBBBRBGGRRRRGRRRRGGRGRGRRGGRGRBBGBGBBRGBGBRBRGGRRRGBRRRGGBGBRGGBGGGRBRGRRGRGRGBGBGGRGGRRGBGBGBGRGRRRGBGBGRRBBBGBRBGBGGRRRGBBGGBGBRGRRGRBBRBGGRGBRBBBGRBBBBGRGGGRBGBRRBBBGBGRBRBRRBBGRRGBBRGRBRBBGGRBGRBRBGRBGGBRRBGGRRRRGBGGRRGGBGBGGGBRRRBBGBRBBGRRBBRGGGBGRRGBGGGBBBRRBBRGBRRGBBGBGBRRBBRRRBRBRRBRBBRGBGRGBRGBBRGGRBRRBGRGRRRGRRGBBRGRGGBBRRGRBRBRBRRRGRGBGGRBGGBBBBBGRGRGRBBBBBBRBRRGGBRBRGBRBRRBBBGRGBBBBGGGGGGGGBBBGRRRGBGGBGGBGRRRBBRGGGGRGRGBRGRBGRRRRBGGRGRBGRRBRRRBBBBRRRGGBBGRRRGRBGBRBRRRGRBRRGBRGBGBRBRRGRGGRRRBGRRGRGBRGRRRGBRRGGRBBRRGGGGGGGBRBRGRBBGBBGBGGRGGBGGGRGRGBGGBRGBBGBRBGBGGRRBRRRGBBBBRGRGRBRBRGRBGRGRGRGBBBBBRBGRBRBBBRGBBBRBBRRRRBGBRRBBBGBRRRRRGGRRGGGGBGGGBGGBGRBBRGGRRBRGBRBBBRRGBGRGBBBGBGGRGGBBRBBRGRBGBGGGBBBBRRRRRGBBRBRRRRBGBRGGRGRBGBGRGGBGRGBRRBRRBRRBGRRGRRBGBRBRBRBGBBBBRRRRBGGBBGGRBRBRGBRRRBGRBRGBBBRGBRBBRGGBGBRRRRBGGBBGGGBGBGRGRGRRBRBBGRBBGRGBBRGRBRBGBBBGGRRBBGGBBRBGBGBGBRRGGGBGBBBGBGBGBRBGBRRBRBRRGBGBRRGGGGBBGGGGRGRRBBBBBRGRRGBRBGRBGGGGRGRBGGGBRBBRGBBGRGGGGRBRBRBGRGBRGRGBRRGRBBBRBBGRGRBBGRRGRBBRBRBGRRGRRRBRBGRBRBRBBRGGRBRGRRRBGBGGRBBGBBGRRGRGRGGRGRBBRBGRRGRGGGGGGGBGRRGRBRBRGGGRBGRRRGGBGGRBRBGBRRRRBRGBRGRBBBBBRBRGGGRBRBBGGRRBGBRGBBGRGBRGGBBGBBBGGGGBRGGBBBGGGBRGBBBRGBBBBGGGGRGRBBBBGGBRGGBRGBBRBGGRGGRGRGRGRBBBBRRRBRGRGRGGGGGRBGBGRBRRBGRRRBBRRRRRRGGBGBGBGBGBGRGGRBRBRRBGRRGGRBBGRRGRGBRBBBGGBRRRRRRGGGRRGRGGBGRGGGBRGRRBRBRRRGGGRBRBRGBGGGRBBGGBRRBRGBBGRRBGBGBBRRRGBBRGGGRGRGRGBRGBRGRRGRBGBBGRRGBBGBRRGBGBGBGGRRGRRGBGRBRRGRRGGRGRGRRBBRBRRGBRBRRBRBBGBBGGBBRBRRBGRGGRBGGBBBBRRRBRGGBRBRGGRRGGRBRRGGGRRBBRGBRBBGRGRRBBRGBGGRBBBRRRBGGRGRRRRBBGRGBRGGGBGRGRGGRBBGBBRBBBBRBGBRBRGGBBGRGBRRBGRRRRBGBRRBBRBGBBBGRRRBRGBBGRRGRGBGGBRGBGRGRRRBRGGGGBGBGGBBBRRRBRGGBRRGGRRGGBBBRRGBRBBGGBRGRGGRBGGGGGGRRBRGBBGBRRRGBBBGBBRRRGRRRGBBRGRRRGBRGGRBGRRGGBRGBRGRBGGRBRBRBRGBGGRRBBBGRBBGGRBGRGBGBRGRGGRRRBRGGGRRGBBGBRGGRRRBBRRBRBBBGGBGGRGBBGRRRGBRGRRBGGGGGBGBBGGGBGBGGRGGBBGRGGGBGBBGRGBBGGGGRRBRGBBRGGGRRRGBBRGGBGBGRBRBRBGGBRRBGRBBGGBRGGBGBBRGGBBGBGGGRRBRGBBBBBGBRGBRRGGBRGGGBBRGRBBRRRGGBBGRGRBRGBRBRBGBGRRGBBBRGRGBRBRRGBGGRGGBRBBGGRRRGGGGRBGBBBGBRBBBBGRBBGBGRGRRBGRBBBRGGRRRRRRRRRRBGRBBRBRGRRGRGRBGBGBGGGBGBRRBRRBBGBBBGRBBGGRRGBBGGRRBGBBGBBGRRRRBRRRBGBBRRBRBBBRGBGGGGGRBGGRBBGBRBBBRBBRBGGGBGRGBBRRGBBRGRGGRBRRBRGBBRRGRGGRRBGBBGRRGBBRGRGGGBRRBBGBRGRGGBGBBBGGBBRRRBGGRRRBBGGBRBGGGRBBRBGRGRBGGBRGBGRGBGRBRGBRGRBRRRBGBBGGBGRRGRBRBRGBRRBRGGGRGBGRBRGBBRGRGGGRBBBRRGBRGGGGRRBRRRRRGBBBBRBGRGRRRBRBRGBRRBBGRGGRBGRRRRRRGRBGBBBRGRBRGRGBBRGBBBRGGRBBRRBGRBGRBGGGGGBGBRRGRGGRGBGBBBGRBGRRRGGBBBBGGGBGRRRGGRBRBRBBBGRBBRRRBBRGBBGRGRGGBRRRRBBBRGBRRRGBGGRGGGRRRGRBRRGBRBRRGBRBBGGRBBRRGGBBBRBRBBRRBGRRGGGRGBRGGGGRRBGBRGGRBRRGGRRGRRBGBRBBRRRGGBBRBGBRBBRGBRRGBGRRRRBBGBGBRBGBBGBGBRGBBBGBRBGRGBRGBRGRRRRRRBBRGRGRRRRRBGBBRGRBRGGRGRBBGBBBGRBRRRRGGRBRBBRGGGGBRRGBGRRRBRBBRBBGRGRGBRBBRRGBBBBRRRRBRRBGGBRBGRGGGBRBRBBRRRRRRBRGRGGGRGBBGRGRBRBRRRRGBBBRRBRGGGRBGGBGRGGBRBRBGRRBRGRGGBBBGRRRBRGGBRRRBGRRGRBRGGBBBBGGBRRGGGGBBRRBGGRGBRGGGBGBRRBRRRGBBRRRGRBGRGGBBGGBBRBRBRRBBRRBRBRRBRGGRGBBBGBBBRBGRGBGBRGBGBBBBBRBRGRBRGGRBGRRBRBBBBGBRRGGBGGBGGGBBGBRBGGRBGRGRRGBRRGRGGBGBGRBRGBRBGGRBRRGBGRBBGBRBGGRBBGRRGBRBGGRRRRBGGGGRGGBBRBRRBRBGBRBGRRBBBBBRRGBBRGBGBBBGRBGBRGRRBBBRRGRBGBGGBGGBRRGBRGGRRBRRBGGBRGBGRBGGBRRGGGGGBBBBGGGBBGGGRBRGGBRGBRBBGRGRGBBRRBRGGGGRGBBBBBGGGBBGRBRGBBBRBRGRRBGBGRBRRBBBGRRGRRRRBBRBGBRRRGRGGRRRGGGBRRBRGGGRGBRBGGGRBRGBBBRGRGGGBBRRRGRRBBRGBGRRRRRBRBGBBRGRGRGGGRGBGBBGBBBGBGBRGRBBRGBRGGRRBRGGGRRRRGGBGGBRBBRRBRRGBRGGGBBGRRBGGGGBBRBGGBBGGRBRGRGGRRBBRGGRRGBGRGGRBGBRRBBGBBBRBGGRBBBRRGGRGRRGBGRGBBGRGBGRGRBGBGGGRGBGRRBBGBGRGGGRRGGBRBGBRRRRBBRRGBBGRGGGBRRRGBBRGRBBGRGBGBBGGBGRBGBRRBBBBBGRRGRGBGGRGBRRRRBBRGBRBRRBRGRBRBRGRBRRRGBGGBBGRBGBRGBBBGRBBRGRRRBGBBGBGGGBBGBBRRGBBBGBRBGBBGBRGGGGGGRBBGRGRBBBBGGBRBGRBGBBRRRBBBRGRRGRBGBRRGBRGRRGRBBRRBRGRGRRRRBBGGRGRBGGBRBRGRGGBGBGBRBRBRRBGRBRBBBRRRGBGGRRGBBGGGRGBBGGRRBRGGGRBRRBGRGRGGRRRBBBBBGGBRRGGRGBGBGRBBRRBGRGRGBBRBBBBGBGBRBRRRRBRGGBGGRGGGRBBRBGBBRGGRGRRGGGRGGRGBGRGGGRRRRBRBGRGBBBRGRGGBBGGGGRGRRGBBGRBGRGGBBRBGGBGBGBBBRGRBGRRBGRBBRBGRRRBBGGGBBRRRBBBRRGGBGBGRBGBRRGGGBGGGRGGRBGGBRGRGRBRGGBGGGBBBRGBRRGBGRRBRRGRRBGRRGGBRGBBRGBRBRRRGBRRRGRRBGGBGRRGGBBGGGGBRGBRBRBGRBBRGBBRRRGGRGGBRGGBRRGRBGGBBRGBRGRGRBBGGRBGBGBGBRRBGBRGGBGGRRGRGBRBBRRGGRBRBGGBBRRBRRGGRRRGRBBBGRGRRGBGBBRGGGBBGBBGRRRGRGRGRRGBGBRBGRGRRGRBRBGRBGBBGRGBGGGRBBBGBBRRBBBBGBRBBGRGGBGRBRRBBBBBRBRBGBGBGRBRRBRBBGRRRBRGBGGBGGGBRRGGBBGGRGBRGRBRGRGBRBGRGBRRRRBGRGBRGBBRGBRBBGRBBGBRGRGRRGRGBRBBBBRGGRGBRBBRGRBRBBGGRRBRBBGBRGBBGRGRGRGBRGBGGRRGBBRRRBGBBGBRBBRGRBBBBRGGGRBRRRBGBRGRBRRBGBRGBGRRRBBRRRGBBBRRRRGGRRGBGBBBRRGBGBRBBBRGGBRRBGRRBBGBRRBGRBBRBRRGRGRGGGBBGBBGGGGRGRRGGRRBRBRRRGGBBRRRGBGBBGRGBBBGRRRBGGBGRBBGRBGRBGGRGBRGBGRBRBGBBGGGBRRRRBBGGGGRRGGBRBGRRGRBRGGGBBBBGRBBGGGBRRGGGRGRRBRRRRRGGGRGBGRGGRRBRBRRRGBGBRGBBBGRRGRBGRGGGBBGRRRRRRGGBGBBBBBBBRGBRGBGBGRGRRBRRRBGBGRGBGGGRGBBBRBBBBGGRGBGBBBGRGBBBRGBGRGBBGBGGGBRGGBGGBRRBRGRGBRBRGBBBGGBRGBGRGRBRRGGBBRBBGRGRRGRRRRRBGGBBRGRBBRBBGBRRBRRRGBBBRRRBGBBRRGGRRBRRBRRRBGBGBBRGBRRGRBRBGBRGGGBBRRRRRGGGBRRBGRRRGGBRGRBBBRGGBGGBGGRBRBRGBGRGBGBGRBGGRGGBBBBGRGBBBBGGGBRBGRRRBBGRRRGRBBRGBBBRRBBGBGRRGRBBRRRGRRGGRRGBRBGGGBGRGGGRRGBBGBBBRBRBBBRRRBRGGBBRGGRBRGGGRRRBBBBRBRRRRRGRBGRGGRBRBBGBBBRRRGRRGRRGRGBGBRBGBBRGRRGBBBRBGGRBRRRGRGRGRRBBR");
    return 0;
}