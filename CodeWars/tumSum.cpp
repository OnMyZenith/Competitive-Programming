#include <iostream>
#include<array>

using namespace std;

int main()
{   
    int numbers[] = {};
    numbers = {1, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 9, 9};
    int target = 18;
    int i, j, l = numbers.size();
    printf("%d\n", l);
    //     std::size_t i ,j;
    //     std::size_t l = sizeof(numbers)/sizeof(numbers[0]);
    bool found = false;
    for (i = 0; i < l; i++)
    {
        for (j = i + 1; j < l; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    printf("%d %d\n", i, j);

    return 0;
}