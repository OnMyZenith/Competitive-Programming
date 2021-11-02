#include <bits/stdc++.h>
using namespace std;

string who_is_winner(vector<string> pieces_position_list)
{
    string winner = "Draw";
    vector<vector<int>> score = {{10, 10, 10, 10, 10, 10}, {10, 10, 10, 10, 10, 10}, {10, 10, 10, 10, 10, 10}, {10, 10, 10, 10, 10, 10}, {10, 10, 10, 10, 10, 10}, {10, 10, 10, 10, 10, 10}, {10, 10, 10, 10, 10, 10}};

    //updates score on every move and check for possible winner
    bool turnRed = (pieces_position_list[0][2] == 'R');

    for (int k = 0; k < pieces_position_list.size(); k++)
    {

        //This block basically updates score on every move
        int vectorNo = pieces_position_list.at(k)[0] - 'A'; //A_Red = A - A = 0, B_Yellow = B - A = 1 , C=2, D=3....
        //Red = 0, Yellow = 1
        auto posOfFirstEmptyEle = find(score.at(vectorNo).begin(), score.at(vectorNo).end(), 10);
        if (turnRed)
            *posOfFirstEmptyEle = 0;
        else
            *posOfFirstEmptyEle = 1;

        turnRed = !turnRed;
        //check for winners only if atleast 4 entries are done
        if (k < 4)
            continue;

        //Verical Check --- checks every vector of vector score
        for (int i = 0; i < 7; i++) // i is no. of cloumns & j is no. of rows
        {
            for (int j = 0; j < 3; j++)
            {
                if (score.at(i).at(j + 3) == 10) // once the top one becomes 10, everything above is same
                    break;

                if (score.at(i).at(j) == score.at(i).at(j + 1) && score.at(i).at(j + 1) == score.at(i).at(j + 2) && score.at(i).at(j + 2) == score.at(i).at(j + 3))
                {
                    winner = (score.at(i).at(j) == 0) ? "Red" : "Yellow";
                    break;
                }
            }
        }

        //Horizontal Check
        for (int j = 0; j < 6; j++) // i is no. of cloumns & j is no. of rows
        {
            for (int i = 0; i < 4; i++)
            {
                if ((score.at(i).at(j) != 10) && score.at(i).at(j) == score.at(i + 1).at(j) && score.at(i + 1).at(j) == score.at(i + 2).at(j) && score.at(i + 2).at(j) == score.at(i + 3).at(j))
                {
                    winner = (score.at(i).at(j) == 0) ? "Red" : "Yellow";
                    break;
                }
            }
        }

        //Positive Diagonal Check
        for (int i = 0; i < 4; i++) // i is no. of cloumns & j is no. of rows
        {
            for (int j = 0; j < 3; j++)
            {
                if ((score.at(i).at(j) != 10) && score.at(i).at(j) == score.at(i + 1).at(j + 1) && score.at(i + 1).at(j + 1) == score.at(i + 2).at(j + 2) && score.at(i + 2).at(j + 2) == score.at(i + 3).at(j + 3))
                {
                    winner = (score.at(i).at(j) == 0) ? "Red" : "Yellow";
                    break;
                }
            }
        }

        //Negative Diagonal Check
        for (int i = 0; i < 4; i++) // i is no. of cloumns & j is no. of rows
        {
            for (int j = 3; j < 6; j++)
            {
                if ((score.at(i).at(j) != 10) && score.at(i).at(j) == score.at(i + 1).at(j - 1) && score.at(i + 1).at(j - 1) == score.at(i + 2).at(j - 2) && score.at(i + 2).at(j - 2) == score.at(i + 3).at(j - 3))
                {
                    winner = (score.at(i).at(j) == 0) ? "Red" : "Yellow";
                    break;
                }
            }
        }

        if (winner != "Draw")
            break;
    }
    for (int j = 5; j > -1; j--)
    {
        for (int i = 0; i < 7; i++)
        {
            cout << setw(5) << score[i][j];
        }
        cout << endl;
    }
    return winner;
}

int main()
{
    vector<string> s = {
        "A_Red",
        "B_Yellow",
        "A_Red",
        "B_Yellow",
        "A_Red",
        "B_Yellow",
        "G_Red",
        "B_Yellow"};
    cout << who_is_winner(s);
    return 0;
}