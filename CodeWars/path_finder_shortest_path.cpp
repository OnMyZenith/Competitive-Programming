#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

void display(int n, string maze) {
    int t = n - 1;
    cout << '\n';
    for (int i = 0; i < maze.size(); i++) {

        cout << maze[i];
        if (i == t) {
            cout << '\n';
            t += n;
        }
    }
    cout << '\n';
}

int shortestPath(int n, string maze) {
    int min = -1;
    vector<pair<int, int>> sp;
    sp.push_back({0, 0});
    maze[0] = '*';
    size_t j = 0;
    while (j != sp.size()) {
        display(n, maze);
        if ((sp[j].first >= n) && maze[sp[j].first - n] == '.') { //up
            sp.push_back(make_pair(sp[j].first - n, sp[j].second + 1));
            maze[sp[j].first - n] = '*';
        }
        if ((sp[j].first <= n * n - n - 1) && maze[sp[j].first + n] == '.') { //down
            sp.push_back(make_pair(sp[j].first + n, sp[j].second + 1));
            maze[sp[j].first + n] = '*';
        }
        if ((sp[j].first % n != 0) && maze[sp[j].first - 1] == '.') { //left
            sp.push_back(make_pair(sp[j].first - 1, sp[j].second + 1));
            maze[sp[j].first - 1] = '*';
        }
        if (((sp[j].first + 1) % n != 0) && maze[sp[j].first + 1] == '.') { //right
            sp.push_back(make_pair(sp[j].first + 1, sp[j].second + 1));
            maze[sp[j].first + 1] = '*';
        }
        if (maze[n * n - 1] != '.' && maze[n * n - 1] != 'W') {
            for (auto i : sp)
                if (i.first == n * n - 1) {
                    min = i.second;
                    break;
                }
            break;
        }
        j++;
    }
    display(n, maze);
    return min;
}

int path_finder(string maze) {
    string temp = maze;
    maze.clear();
    for (char ch : temp)
        if (ch != '\n') maze += ch;

    int n = (int)sqrt(maze.size());

    return shortestPath(n, maze);
}

int main() {
    string s = ".W.\n.W.\n... ";
    string s1 = "......\n......\n......\n......\n......\n......";
    cout << path_finder(s) << '\n';
    cout << path_finder(s1) << '\n';

    return 0;
}