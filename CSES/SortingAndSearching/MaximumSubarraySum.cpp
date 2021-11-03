// Time limit: 1.00 s Memory limit: 512 MB
// Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

// Input

// The first input line has an integer n: the size of the array.

// The second line has n integers x1,x2,…,xn: the array values.

// Output

// Print one integer: the maximum subarray sum.

// Constraints
// 1≤n≤2⋅105
// −109≤xi≤109
// Example

// Input:
// 8
// -1 3 -2 5 3 -5 2 2

// Output:
// 9

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long max_sum = arr[0];
    long long cur_sum = arr[0];
    for (long long i = 1; i < n; i++) {
        cur_sum = max(arr[i], cur_sum + arr[i]);
        max_sum = max(max_sum, cur_sum);
    }
    cout << max_sum << endl;
    return 0;
}