#include <vector>
#include <iostream>
// #include <bits/stdc++.h>

void display(std::vector<std::vector<int>> &m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            std::cout << m[i][j] << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool submarines(std::vector<std::vector<int>> &field)
{
    int count = 4;

    //i is row, j is column
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            //1 horizontal rows ==1 && 3 horizontal rows above ==0 && 3 horizontal rows below == 0 && head and tail padded with 0
            bool submarine = (field[i][j]);
            bool paddingBelow = !(field[i - 1][j - 1] || field[i - 1][j] || field[i - 1][j + 1]);
            bool paddingAbove = !(field[i + 1][j - 1] || field[i + 1][j] || field[i + 1][j + 1]);
            bool paddingHeadTail = !(field[i][j - 1] || field[i][j + 1]);

            if (submarine && paddingBelow && paddingAbove && paddingHeadTail)
            {
                field[i][j] = 0; //marking it so don't end up counting it again
                count--;
            }
        }
    }

    if (count == 0)
        return true;
    else
        return false;
}

bool destroyers(std::vector<std::vector<int>> &field)
{
    int count = 3;

    // horizontal ship        i is row, j is column
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            //2 horizontal rows ==1 && 4 horizontal rows above ==0 && 4 horizontal rows below == 0 && head and tail padded with 0
            bool destroyer = (field[i][j] && field[i][j + 1]);
            bool paddingBelow = !(field[i - 1][j - 1] || field[i - 1][j] || field[i - 1][j + 1] || field[i - 1][j + 2]);
            bool paddingAbove = !(field[i + 1][j - 1] || field[i + 1][j] || field[i + 1][j + 1] || field[i + 1][j + 2]);
            bool paddingHeadTail = !(field[i][j - 1] || field[i][j + 2]);

            if (destroyer && paddingBelow && paddingAbove && paddingHeadTail)
            {
                field[i][j] = field[i][j + 1] = 0; //marking it so don't end up counting it again
                count--;
            }
        }
    }

    // vertical ship        i is row, j is column
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            //2 vertical rows ==1 && 4 vertical rows left ==0 && 4 vertical rows right ==0 && head and tail padded with 0
            bool destroyer = (field[i][j] && field[i + 1][j]);
            bool paddingLeft = !(field[i - 1][j - 1] || field[i][j - 1] || field[i + 1][j - 1] || field[i + 2][j - 1]);
            bool paddingRight = !(field[i - 1][j + 1] || field[i][j + 1] || field[i + 1][j + 1] || field[i + 2][j + 1]);
            bool paddingHeadTail = !(field[i - 1][j] || field[i + 2][j]);

            if (destroyer && paddingLeft && paddingRight && paddingHeadTail)
            {
                field[i][j] = field[i + 1][j] = 0; //marking it so don't end up counting it again
                count--;
            }
        }
    }

    if (count == 0)
        return true;
    else
        return false;
}

bool cruisers(std::vector<std::vector<int>> &field)
{
    int count = 2;

    // horizontal ship        i is row, j is column
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            //3 horizontal rows ==1 && 5 horizontal rows above ==0 && 5 horizontal rows below == 0 && head and tail padded with 0
            bool cruiser = (field[i][j] && field[i][j + 1] && field[i][j + 2]);
            bool paddingBelow = !(field[i - 1][j - 1] || field[i - 1][j] || field[i - 1][j + 1] || field[i - 1][j + 2] || field[i - 1][j + 3]);
            bool paddingAbove = !(field[i + 1][j - 1] || field[i + 1][j] || field[i + 1][j + 1] || field[i + 1][j + 2] || field[i + 1][j + 3]);
            bool paddingHeadTail = !(field[i][j - 1] || field[i][j + 3]);

            if (cruiser && paddingBelow && paddingAbove && paddingHeadTail)
            {
                field[i][j] = field[i][j + 1] = field[i][j + 2] = 0; //marking it so don't end up counting it again
                count--;
            }
        }
    }

    // vertical ship        i is row, j is column
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            //3 vertical rows ==1 && 5 vertical rows left ==0 && 5 vertical rows right ==0 && head and tail padded with 0
            bool cruiser = (field[i][j] && field[i + 1][j] && field[i + 2][j]);
            bool paddingLeft = !(field[i - 1][j - 1] || field[i][j - 1] || field[i + 1][j - 1] || field[i + 2][j - 1] || field[i + 3][j - 1]);
            bool paddingRight = !(field[i - 1][j + 1] || field[i][j + 1] || field[i + 1][j + 1] || field[i + 2][j + 1] || field[i + 3][j + 1]);
            bool paddingHeadTail = !(field[i - 1][j] || field[i + 3][j]);

            if (cruiser && paddingLeft && paddingRight && paddingHeadTail)
            {
                field[i][j] = field[i + 1][j] = field[i + 2][j] = 0; //marking it so don't end up counting it again
                count--;
            }
        }
    }

    if (count == 0)
        return true;
    else
        return false;
}

bool battleship(std::vector<std::vector<int>> &field)
{
    // horizontal ship        i is row, j is column
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            //4 horizontal rows ==1 && 6 horizontal rows above ==0 && 6 horizontal rows below == 0 && head and tail padded with 0
            bool battleship = (field[i][j] && field[i][j + 1] && field[i][j + 2] && field[i][j + 3]);
            bool paddingBelow = !(field[i - 1][j - 1] || field[i - 1][j] || field[i - 1][j + 1] || field[i - 1][j + 2] || field[i - 1][j + 3] || field[i - 1][j + 4]);
            bool paddingAbove = !(field[i + 1][j - 1] || field[i + 1][j] || field[i + 1][j + 1] || field[i + 1][j + 2] || field[i + 1][j + 3] || field[i + 1][j + 4]);
            bool paddingHeadTail = !(field[i][j - 1] || field[i][j + 4]);

            if (battleship && paddingBelow && paddingAbove && paddingHeadTail)
            {
                field[i][j] = field[i][j + 1] = field[i][j + 2] = field[i][j + 3] = 0; //marking it so don't end up counting it again
                return true;
            }
        }
    }

    // vertical ship        i is row, j is column
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            //4 vertical rows ==1 && 6 vertical rows left ==0 && 6 vertical rows right ==0 && head and tail padded with 0
            bool battleship = (field[i][j] && field[i + 1][j] && field[i + 2][j] && field[i + 3][j]);
            bool paddingLeft = !(field[i - 1][j - 1] || field[i][j - 1] || field[i + 1][j - 1] || field[i + 2][j - 1] || field[i + 3][j - 1] || field[i + 4][j - 1]);
            bool paddingRight = !(field[i - 1][j + 1] || field[i][j + 1] || field[i + 1][j + 1] || field[i + 2][j + 1] || field[i + 3][j + 1] || field[i + 4][j + 1]);
            bool paddingHeadTail = !(field[i - 1][j] || field[i + 4][j]);

            if (battleship && paddingLeft && paddingRight && paddingHeadTail)
            {
                field[i][j] = field[i + 1][j] = field[i + 2][j] = field[i + 3][j] = 0;
                return true;
            }
        }
    }

    return false;
}

bool nothingElseRemaining(std::vector<std::vector<int>> &field)
{
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if ((field[i][j]))
            {
                return false;
            }
        }
    }

    return true;
}

bool validate_battlefield(std::vector<std::vector<int>> field)
{
    //padding all 4 sides
    field.insert(field.begin(), {0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    field.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    for (int i = 0; i < 12; i++)
    {
        field[i].insert(field[i].begin(), 0);
        field[i].push_back(0);
    }
    display(field);

    return submarines(field) && destroyers(field) && cruisers(field) && battleship(field) && nothingElseRemaining(field);
}

int main()
{
    std::vector<std::vector<int>> V = {
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    display(V);
    std::cout << validate_battlefield(V);
    return 0;
}