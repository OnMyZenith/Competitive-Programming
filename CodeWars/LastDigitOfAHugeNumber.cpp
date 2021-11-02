#include <list>
#include <iostream>
#include<vector>
#include<set>

using namespace std;
int last_digit(list<int> array) {
    vector<set<int>> all;
    for (int i = 0; i < 100;i++){
        int res = i;
        while(!all[i].count(res)){
            all[i].insert(res);
            res *= i;
            res %= 100;
        }
    }

}
