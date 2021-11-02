#include <bits/stdc++.h>
using namespace std;

string add(int *product, int max_power)
{
    string sum = "";
    int carryover = 0;
    for (int j = 0; j < max_power + 3; j++) //max_power + 3 is total digits to compute//J is digit from right // no. with max power cant be greater than 3 digit
    {
        int sumOfOneCol = 0;
        int digitJ = 0;
        for (int i = 0; (i < max_power + 1) && (i <= j); i++)
        {
            sumOfOneCol += (((int)(product[i] / pow(10, j - i))) % 10);
        }

        digitJ = (sumOfOneCol + carryover) % 10;
        carryover = (sumOfOneCol + carryover) / 10;
        sum = to_string(digitJ) + sum;
    }

    while (sum[0] == '0')
    {
        sum.erase(sum.begin());
    }

    if (sum.length() > 0)
        return sum;
    else
        return "0";
}

string multiply(string a, string b)
{
    bool isNegative = false;
    int decimalPosition = 0;

    if (a.front() == '-')
    {
        a.erase(a.begin());
        isNegative = !isNegative;
    }

    if (b.front() == '-')
    {
        b.erase(b.begin());
        isNegative = !isNegative;
    }

    while (a.front() == '0')
        a.erase(a.begin());

    while (b.front() == '0')
        b.erase(b.begin());

    for (auto ch : a)
    {
        if (ch == '.')
        {
            while (a.back() == '0')
            {
                a.pop_back();
            }

            for (auto it = a.rbegin(); it != a.rend(); it++)
            {
                if (*it == '.')
                {
                    a.erase(next(it).base());
                    break;
                }
                decimalPosition++;
            }

            break;
        }
    }
    for (auto ch : b)
    {
        if (ch == '.')
        {
            while (b.back() == '0')
            {
                b.pop_back();
            }

            for (auto it = b.rbegin(); it != b.rend(); it++)
            {
                if (*it == '.')
                {
                    b.erase(next(it).base());
                    break;
                }
                decimalPosition++;
            }

            break;
        }
    }

    if (a == "" || b == "")
        return "0";

    int k = (a.length() - 1 + b.length() - 1); //(23)(205)=(2*10 + 3)(2*100 + 0*10 +5) ==> MAX power is 3 = (2-1)+(3-1)
    int product[k + 1];                        //product is a one dimensional array where 1st elem is the sum of elements in the first place and second elem is the sum of elements in the tens place....
    for (int i = 0; i < *(&product + 1) - product; i++)
        product[i] = 0;

    for (unsigned int i = 0; i < a.length(); i++)
    {
        for (unsigned int j = 0; j < b.length(); j++)
            product[k - (i + j)] += (a.at(i) - '0') * (b.at(j) - '0');
    }

    string res = add(product, k);

    if (decimalPosition != 0)
        res.insert(res.length() - decimalPosition, 1, '.');

    if (isNegative)
        res = '-' + res;

    return res;
}

int main()
{
    cout << multiply("-0158.2300", "0052.030");
    return 0;
}