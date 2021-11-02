#include <bits/stdc++.h>

using namespace std;

// void display(vector<vector<int>> &m)
// {
//     for (int i = 0; i < m.size(); i++)
//     {
//         for (int j = 0; j < m[i].size(); j++)
//         {
//             cout << m[i][j] << "  ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // vector<vector<int>> field = {std::vector<int>{1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    //                              std::vector<int>{1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    //                              std::vector<int>{1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
    //                              std::vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //                              std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    //                              std::vector<int>{0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //                              std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    //                              std::vector<int>{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //                              std::vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //                              std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    // display(field);

    // field.insert(field.begin(), {0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    // field.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

    // for (int i = 0; i < 12; i++)
    // {
    //     field[i].insert(field[i].begin(), 0);
    //     field[i].push_back(0);
    // }
    // display(field);
    // cout << sizeof(bool) << "\n";
    // cout << sizeof(int) << "\n";
    // int res = 1;
    // for (int i = 1; i < 100; i++) {
    //     res *= 2;
    //     res %= 100;
    //     cout << res << "\n";
    //     if (res == 52) {
    //         cout << i;
    //         break;
    //     }
    // }

    vector<vector<int>> all(100);
    for (int i = 0; i < 100;i++){
        int res = i;
        res *= i;
        res %= 100;
        all[i].push_back(res);
        res *= i;
        res %= 100;
        while(all[i][0]!=(res)){
            all[i].push_back(res);
            res *= i;
            res %= 100;
        }
            all[i].push_back(res);
    }
    for (int i = 0; i < 100;i++) {
        cout << i << " : "<<all[i].size()<<" : ";
        for (auto j : all[i])
            cout << j << " ";
        cout << '\n';
    }

    return 0;
}