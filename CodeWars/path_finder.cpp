#include <iostream>
#include <string>
#include <vector>
#include <sstream>
// #include <bits/stdc++.h>

using namespace std;

int n = 0;

void display(vector<string> &m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            cout << m[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isPath(int x, int y, vector<string> &m)
{
    display(m);
    if (x == 0 && y == 0) //Final Destination
    {
        m[y][x] = '+';
        display(m);
        return true;
    }
    if (x == n || y == n || x == -1 || y == -1) //Taking care of stepping outside first
        return false;
    if (m[y][x] == 'W') //Can safely check for walls
        return false;
    if (m[y][x] == '+') //Checking for paths already traversed
        return false;
    if (m[y][x] == '.') //Marking traversed and moving forward
    {
        m[y][x] = '+';
        return (isPath(x, y - 1, m) || isPath(x - 1, y, m) || isPath(x, y + 1, m) || isPath(x + 1, y, m));
    }
    return false;
}

bool path_finder(string maze)
{
    // TODO: Determine whether one can reach the exit at (n - 1, n - 1)
    // starting from (0, 0) in a n × n maze (represented as a string)
    // and return a boolean value accordingly
    istringstream iss(maze);
    string temp;
    n = 0;
    vector<string> m = {};
    while (getline(iss, temp))
    {
        m.push_back(temp);
        n++;
    }

    display(m);

    return isPath(n - 1, n - 1, m);
}

int main()
{
    string s = ".W.\n.W.\n... ";
    cout << path_finder(s);
    return 0;
}