#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::string encode_rail_fence_cipher(const std::string &str, int n) {
    size_t len = str.length();
    if (len == 0) return "";
    string res;
    vector<int> elemsInRow;
    int x = len / (2 * (n - 1));
    for (int i = 0; i < n; i++) {
        if (i > 0 && i < n - 1) elemsInRow.push_back(2 * x);
        else
            elemsInRow.push_back(x);
    }
    for (size_t i = 1; i <= len % (2 * (n - 1)); i++) {
        int j = i;
        if (j > n) j = 2 * n - j;
        elemsInRow[j - 1]++;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            for (int j = 0; j < elemsInRow[i]; j++)
                res += str[j * 2 * (n - 1) + i];
        } else {
            int j = 0, k = 0;
            while (j < elemsInRow[i]) {
                res += str[k * 2 * (n - 1) + i];
                j++;
                k++;
                if (j >= elemsInRow[i]) break;
                res += str[k * 2 * (n - 1) - i];
                j++;
            }
        }
    }
    cout << str << "  " << res << "\n";
    return res;
}

std::string decode_rail_fence_cipher(const std::string &str, int n) {
    size_t len = str.length();
    if (len == 0) return "";
    string res;
    vector<int> elemsInRow, posOfElemsInRow = {0};
    int x = len / (2 * (n - 1));
    for (int i = 0; i < n; i++) {
        if (i > 0 && i < n - 1) elemsInRow.push_back(2 * x);
        else
            elemsInRow.push_back(x);
    }
    for (size_t i = 1; i <= len % (2 * (n - 1)); i++) {
        int j = i;
        if (j > n) j = 2 * n - j;
        elemsInRow[j - 1]++;
    }

    posOfElemsInRow.push_back(elemsInRow[0]);
    for (size_t i = 2; i < elemsInRow.size(); i++)
        posOfElemsInRow.push_back(posOfElemsInRow[i - 1] + elemsInRow[i - 1]);

    size_t cnt = 0, k = 0;
    while (1) {
        for (int i = 1; i <= 2 * (n - 1); i++) {
            int j = i;
            if (j > n) {
                j = 2 * n - j;
                res += str[posOfElemsInRow[j - 1] + 2 * k + 1];
            } else if (j > 1 && j < n)
                res += str[posOfElemsInRow[j - 1] + 2 * k];
            else
                res += str[posOfElemsInRow[j - 1] + k];
            cnt++;
            if (cnt == len) break;
        }
        if (cnt == len) break;
        k++;
    }
    cout << str << "  " << res << "\n";
    return res;
}
int main() {
    cout << encode_rail_fence_cipher("WEAREDISCOVEREDFLEEATONCE", 3);
}