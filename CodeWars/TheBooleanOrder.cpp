#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

bool op(bool a, char op, bool b) {
    switch (op) {
    case '^': return a ^ b;
    case '&': return a & b;
    case '|': return a | b;
    }
    return 0;
}

int64_t solve(const std::string &s, const std::string &ops) {
    int trues = 0;
    int sz = s.size();

    vector<bool> val;
    for (char ch : s)
        if (ch == 't') val.emplace_back(true);
        else
            val.emplace_back(false);

    vector<int> oneOrderOfOps;
    for (int i = 0; i < sz - 1; i++)
        oneOrderOfOps.emplace_back(i);

    vector<vector<int>> allOrders;
    do {
        allOrders.emplace_back(oneOrderOfOps);
    } while (next_permutation(oneOrderOfOps.begin(), oneOrderOfOps.end()));

    for (auto one : allOrders) {

        vector<bool> oneRes = val;
        for (int i = 0; i < sz - 1; i++) {
            bool res = op(oneRes.at(one[i]), ops[one[i]], oneRes.at(one[i] + 1));
            oneRes.at(one[i]) = res;
            oneRes.at(one[i] + 1) = res;
        }

        if (oneRes[one[sz - 2]]) {
            trues++;
        }
    }
    return trues;
}

int main() {
    cout << solve("tft", "^&") << "\n";
    cout << solve("ttftff", "|&^&&") << "\n";
    cout << solve("ttftfftf", "|&^&&||") << "\n";
    cout << solve("ttftfftft", "|&^&&||^") << "\n";
    cout << solve("ttftfftftf", "|&^&&||^&") << "\n";
    return 0;
}