#include <bits/stdc++.h>

class RomanHelper
{
public:
    std::string to_roman(unsigned int n)
    {
        std::string roman = "";
        int nOfDig = std::to_string(n).size();
        int div;
        while (n > 0)
        {
            nOfDig--;
            div = pow(10, nOfDig);
            switch (n - n % div)
            {
            case 1:
                roman += "I";
                break;
            case 2:
                roman += "II";
                break;
            case 3:
                roman += "III";
                break;
            case 4:
                roman += "IV";
                break;
            case 5:
                roman += "V";
                break;
            case 6:
                roman += "VI";
                break;
            case 7:
                roman += "VII";
                break;
            case 8:
                roman += "VIII";
                break;
            case 9:
                roman += "IX";
                break;
            case 10:
                roman += "X";
                break;
            case 20:
                roman += "XX";
                break;
            case 30:
                roman += "XXX";
                break;
            case 40:
                roman += "XL";
                break;
            case 50:
                roman += "L";
                break;
            case 60:
                roman += "LX";
                break;
            case 70:
                roman += "LXX";
                break;
            case 80:
                roman += "LXXX";
                break;
            case 90:
                roman += "XC";
                break;
            case 100:
                roman += "C";
                break;
            case 200:
                roman += "CC";
                break;
            case 300:
                roman += "CCC";
                break;
            case 400:
                roman += "CD";
                break;
            case 500:
                roman += "D";
                break;
            case 600:
                roman += "DC";
                break;
            case 700:
                roman += "DCC";
                break;
            case 800:
                roman += "DCCC";
                break;
            case 900:
                roman += "CM";
                break;
            case 1000:
                roman += "M";
                break;
            case 2000:
                roman += "MM";
                break;
            case 3000:
                roman += "MMM";
                break;
            }
            n %= div;
        }

        return roman;
    }

    int from_roman(std::string rn)
    {
        int sum = 0;

        for (int i = 0; i < rn.length();)
        {

            bool was2Char = false;

            switch (rn[i])
            {
            case 'C':
                switch (rn[i + 1])
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
                switch (rn[i + 1])
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
                switch (rn[i + 1])
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
} RomanNumerals;

int main()
{
    std::cout << RomanNumerals.from_roman("MMCMLVVIX");
    std::cout << RomanNumerals.to_roman(2562);
    return 0;
}