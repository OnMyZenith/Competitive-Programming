#include <iostream>
#include <string>

using namespace std;

int solution(string roman)
{
    int sum = 0;

    for (int i = 0; i < roman.length();)
    {

        bool was2Char = false;

        switch (roman[i])
        {
        case 'C':
            switch (roman[i + 1])
            {
            case 'M':
                sum += 900;
                was2Char = true;
                break;
            case 'D':
                sum += 400;
                was2Char = true;
                break;
            default:
                sum += 100;
            }
            break;
        case 'X':
            switch (roman[i + 1])
            {
            case 'C':
                sum += 90;
                was2Char = true;
                break;
            case 'L':
                sum += 40;
                was2Char = true;
                break;
            default:
                sum += 10;
            }
            break;

        case 'I':
            switch (roman[i + 1])
            {
            case 'X':
                sum += 9;
                was2Char = true;
                break;
            case 'V':
                sum += 4;
                was2Char = true;
                break;
            default:
                sum += 1;
            }
            break;

        case 'V':
            sum += 5;
            break;

        case 'L':
            sum += 50;
            break;

        case 'D':
            sum += 500;
            break;

        case 'M':
            sum += 1000;
            break;
        }

        if (was2Char == true)
            i += 2;
        else
            i++;
    }
    return sum;
}

int main()
{
    string X;
    cin >> X;
    cout << solution(X);
}