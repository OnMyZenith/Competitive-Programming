#include <bits/stdc++.h>
using namespace std;
const int N = 7;
bool visited[N][N];
int dx[] = {0, +1, 0, -1}, dy[] = {-1, 0, +1, 0};
int solve(string &str, int cur = 0, int y = 0, int x = 0) {
    if (y == N - 1 && x == 0) return (cur == (N * N - 1));
    if (((y + 1 == N || (visited[y - 1][x] && visited[y + 1][x])) && x - 1 >= 0 && x + 1 < N && !visited[y][x - 1] && !visited[y][x + 1]) ||
        ((x + 1 == N || (visited[y][x - 1] && visited[y][x + 1])) && y - 1 >= 0 && y + 1 < N && !visited[y - 1][x] && !visited[y + 1][x]) ||
        ((y == 0 || (visited[y + 1][x] && visited[y - 1][x])) && x - 1 >= 0 && x + 1 < N && !visited[y][x - 1] && !visited[y][x + 1]) ||
        ((x == 0 || (visited[y][x + 1] && visited[y][x - 1])) && y - 1 >= 0 && y + 1 < N && !visited[y - 1][x] && !visited[y + 1][x]))
        return 0;

    visited[y][x] = true;
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        if ((str[cur] == 'U' && i != 0) || (str[cur] == 'R' && i != 1) ||
            (str[cur] == 'D' && i != 2) || (str[cur] == 'L' && i != 3)) continue;
        int _y = y + dy[i], _x = x + dx[i];
        if (_y >= 0 && _x >= 0 && _y < N && _x < N && !visited[_y][_x]) res += solve(str, cur + 1, _y, _x);
    }
    visited[y][x] = false;
    return res;
}
signed main(){
#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    cout << solve(str) << '\n';
#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif
    return 0;
}
