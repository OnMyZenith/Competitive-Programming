#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        bool endsWithZero = false;
        long long K;
        int a, b;
        cin >> K >> a >> b;
        long long sum = a + b;
        K -= 2;
        while (K)
        {
            if (sum % 10 == 0)
            {
                endsWithZero = true;
                break;
            }
            if (sum % 2 == 0)
                break;
            sum += sum % 10;
            K--;
        }

        if (endsWithZero == false && K > 0)
        {

            int pattern;
            switch (sum % 10)
            {
            case 2:
                pattern = 2486;
                break;
            case 4:
                pattern = 4862;
                break;
            case 6:
                pattern = 6248;
                break;
            case 8:
                pattern = 8624;
                break;
            }

            int numberOfFinalDigits = K % 4;

            int finalDigits;
            switch (numberOfFinalDigits)
            {
            case 1:
                finalDigits = pattern / 1000;
                break;
            case 2:
                finalDigits = pattern / 100;
                break;
            case 3:
                finalDigits = pattern / 10;
                break;
            }

            int sumOfFinalDigits = 0;
            while (finalDigits)
            {
                sumOfFinalDigits += finalDigits % 10;
                finalDigits /= 10;
            }

            sum += 20 * (K / 4) + sumOfFinalDigits;
        }

        if (sum % 3)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}