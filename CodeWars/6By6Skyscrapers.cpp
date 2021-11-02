#include <bits/stdc++.h>

using namespace std;
std::vector<std::vector<int>> SolvePuzzle(const std::vector<int> &clues) {
    map<pair<int, int>, vector<vector<int>>> allMap;
    vector<int> base = {1, 2, 3, 4, 5, 6};
    do {
        int max = 0, leftCount = 0; //or up
        for (int i = 0; i < 6; i++) {
            if (base[i] > max) {
                max = base[i];
                leftCount++;
            }
        }
        allMap[make_pair(leftCount, 0)].push_back(base);
        int rightCount = 0; //or down
        max = 0;
        for (int i = 5; i > -1; i--) {
            if (base[i] > max) {
                max = base[i];
                rightCount++;
            }
        }
        allMap[make_pair(0, 0)].push_back(base);
        allMap[make_pair(0, rightCount)].push_back(base);
        allMap[make_pair(leftCount, rightCount)].push_back(base);
    } while (next_permutation(base.begin(), base.end()));

    // for (auto i : allMap) {
    //     cout << i.first.first << "  " << i.first.second << "\n";
    // }
    // cout << allMap.size() << "\n";

    vector<pair<int, int>> rowEnds, colEnds;
    for (int i = 0; i < 6; i++)
        colEnds.push_back(make_pair(clues.at(i), clues.at(17 - i)));
    for (int i = 6; i < 12; i++)
        rowEnds.push_back(make_pair(clues.at(29 - i), clues.at(i)));

    vector<vector<vector<int>>> res;
    vector<vector<int>> allRowRes, allColRes;
    vector<int> temp;

    for (auto i : rowEnds)
        res.push_back(allMap[i]);
    for (auto r1 : res[0]) {
        for (auto r2 : res[1]) {
            for (auto r3 : res[2]) {
                for (auto r4 : res[3]) {
                    for (auto r5 : res[4]) {
                        for (auto r6 : res[5]) {
                            temp.clear();

                            auto l = {r1, r2, r3, r4, r5, r6};
                            for (auto i : l) {
                                for (auto e : i)
                                    temp.push_back(e);
                            }

                            allRowRes.push_back(temp);
                        }
                    }
                }
            }
        }
    }

    res.clear();
    for (auto i : colEnds)
        res.push_back(allMap[i]);
    for (auto c1 : res[0]) {
        for (auto c2 : res[1]) {
            for (auto c3 : res[2]) {
                for (auto c4 : res[3]) {
                    for (auto c5 : res[4]) {
                        for (auto c6 : res[5]) {
                            temp.clear();

                            auto l = {c1, c2, c3, c4, c5, c6};
                            for (auto i : l) {
                                for (auto e : i)
                                    temp.push_back(e);
                            }

                            allColRes.push_back(temp);
                        }
                    }
                }
            }
        }
    }

    // vector<vector<int>> colOptions;
    // for (int p = 0; p < 6; p++) {
    //     colOptions = allMap[colEnds[p]];
    //     for (vector<int> v : colOptions) {
    //         vector<int> allowed;
    //         for (int a : v)
    //             allowed.push_back(a);
    //         for (int i = 0; i < 6; i++) {
    //             for (auto it = (res[i]).begin(); it != (res[i]).end();) {
    //                 if (find(allowed.begin(), allowed.end(), (*it)[p]) == allowed.end()) (res[i]).erase(it);
    //                 else
    //                     it++;
    //             }
    //         }
    //         allowed.clear();
    //     }
    // }
    vector<vector<int>> result;
    // for (auto v : res)
    //     result.push_back(v[0]);
    return result;
}

int main() {
    vector<int> v = {3, 2, 2, 3, 2, 1, 1, 2, 3, 3, 2, 2, 5, 1, 2, 2, 4, 3, 3, 2, 1, 2, 2, 4};
    auto res = SolvePuzzle(v);
    cout << res.size() << "\n";

    return 0;
}