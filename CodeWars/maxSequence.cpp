#include <vector>
#include <bits/stdc++.h>
using namespace std;
int maxSequence(const std::vector<int> &arr){
    std::vector<int> allPossibleSums = {0}; //n(n-1)/2 + 1 for 0

    //going to add all possible sums i.e. n(n-1)/2
    for(int i = 0; i < arr.size(); i++){
        for(int j = i; j < arr.size(); j++){
            int sum = 0;
            for(int k = i; k <= j; k++) sum += arr[k];

            allPossibleSums.push_back(sum);
        }
    }
    
    return *max_element(allPossibleSums.begin(), allPossibleSums.end());
}