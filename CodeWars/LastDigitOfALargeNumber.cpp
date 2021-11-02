#include <iostream>
#include <string>
#include <vector>
using namespace std;
int last_digit(const std::string &str1, const std::string &str2) {
    cout << str1 << " " << str2 << "\n";
    if (str2.length() == 1 && str2[0] == '0') return 1;
    vector<int> v2 = {6, 2, 4, 8}, v3 = {1, 3, 9, 7}, v7 = {1, 7, 9, 3}, v8 = {6, 8, 4, 2};
    switch (str1[str1.length() - 1]) {
    case '0':
    case '1':
    case '5':
    case '6':
        return str1[str1.length() - 1] - '0';
    case '4':
        return (str2[str2.length() - 1] - '0') % 2 == 0 ? 6 : 4;
    case '9':
        return (str2[str2.length() - 1] - '0') % 2 == 0 ? 1 : 9;
    case '2':
        if (str2.length() < 2) return v2[((str2[str2.length() - 1] - '0')) % 4];
        return v2[((str2[str2.length() - 2] - '0') * 10 + (str2[str2.length() - 1] - '0')) % 4];
    case '3':
        if (str2.length() < 2) return v3[((str2[str2.length() - 1] - '0')) % 4];
        return v3[((str2[str2.length() - 2] - '0') * 10 + (str2[str2.length() - 1] - '0')) % 4];
    case '7':
        if (str2.length() < 2) return v7[((str2[str2.length() - 1] - '0')) % 4];
        return v7[((str2[str2.length() - 2] - '0') * 10 + (str2[str2.length() - 1] - '0')) % 4];
    case '8':
        if (str2.length() < 2) return v8[((str2[str2.length() - 1] - '0')) % 4];
        return v8[((str2[str2.length() - 2] - '0') * 10 + (str2[str2.length() - 1] - '0')) % 4];
    }
    return 0;
}
int main() {
    cout << last_digit("4", "1");
}