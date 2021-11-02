#include <iostream>
#include <string>
using namespace std;

int main(
    char INDIAN[] = "INDIAN";
    char CONTEST_WON[] = "CONTEST_WON";
    char TOP_CONTRIBUTOR[] = "TOP_CONTRIBUTOR";
    char BUG_FOUND[] = "BUG_FOUND";
    char CONTEST_HOSTED[] = "CONTEST_HOSTED";
    int T;
    cin >> T;
    while (T--)
    {
        int activities, LADDU, rank, sev, months;
        string nationality;
        cin >> activities >> nationality;
        int isIndian = nationality.compare(INDIAN));
        while (activities--)
        {
            string achievement;
            cin >> achievement;
            if (strcmp(achievement, CONTEST_WON) == 0)
            {
                LADDU += 300;
                cin >> rank;
                rank = 20 - rank;
                if (rank > 0)
                    LADDU += rank;
            }
            if (strcmp(achievement, TOP_CONTRIBUTOR) == 0)
            {
                LADDU += 300;
            }
            if (strcmp(achievement, BUG_FOUND) == 0)
            {
                cin >> sev;
                LADDU += sev;
            }
            if (strcmp(achievement, CONTEST_HOSTED) == 0)
            {
                LADDU += 50;
            }
        }
        if (isIndian == 0)
            months = LADDU / 200;
        else
            months = LADDU / 400;
        cout << months;
    }
    return 0;
}