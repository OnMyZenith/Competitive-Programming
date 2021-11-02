#include <bits/stdc++.h>

bool isEven(std::vector<int> &arr)
{
    int sum = abs(arr[0] % 2) + abs(arr[1] % 2) + abs(arr[2] % 2);
    if (sum < 2)
        return true;
    else
        return false;
}

int FindOutlier(std::vector<int> arr)
{
    bool even = isEven(arr);
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        if (even)
        {
            if (abs(arr[i] % 2) == 1)
                break;
        }
        else
        {
            if (abs(arr[i] % 2) == 0)
                break;
        }
    }
    return arr[i];
}