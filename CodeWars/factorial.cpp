#include <bits/stdc++.h>
using namespace std;

string multiply(int n, string f)
{
    vector<int> v = {};

    for (auto it = f.rbegin(); it != f.rend(); it++) //multipying each digit with n and adding to an int vector
        v.push_back((*it - '0') * n);

    // for (int i = f.length() - 1; i > -1; i--) //multipying each digit with n and adding to an int vector
    //     v.push_back((f[i] - '0') * n);
    /*

       4 2 5
       * 1 9
    --------
         9 5
       3 8 x
     7 6 x x          <----i is row no.
    --------
     8 0 7 5          <----j is column no.
    
    */

    string prod = "";
    int carryover = 0;
    for (int j = 0; j < f.length() + to_string(n).length() + 1; j++)
    {
        int sumOfOneCol = 0;
        int digitJ = 0;
        for (int i = 0; (i < v.size()) && (i <= j); i++)
        {
            sumOfOneCol += (((int)(v.at(i) / pow(10, j - i))) % 10);
        }

        digitJ = (sumOfOneCol + carryover) % 10;
        carryover = (sumOfOneCol + carryover) / 10;
        prod = to_string(digitJ) + prod;
    }

    while (prod[0] == '0')
    {
        prod.erase(prod.begin());
    }

    return prod;
}

string factorial(int fact)
{
    if (fact == 1)
        return "1";

    return multiply(fact, factorial(fact - 1));
}

int main()
{
    cout << factorial(5) << "\n";
    cout << factorial(15) << "\n";
    cout << factorial(25) << "\n";
    return 0;
}