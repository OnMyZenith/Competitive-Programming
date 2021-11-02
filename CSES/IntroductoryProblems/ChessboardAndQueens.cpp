#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    vector<vector<bool>> board;
    for (int i = 0; i < 8; i++) {
        vector<bool> tmpVec;
        for (int j = 0; j < 8; j++) {
            char tmp;
            cin >> tmp;
            if (tmp == '.')
                tmpVec.push_back(true);
            else
                tmpVec.push_back(false);
        }
        board.push_back(tmpVec);
    }
    int cnt = 0;

    // A itself means First Row, its val represents the col val
    for (int a = 0; a < 8; a++) // 1st Row
        if (board[0][a])
            for (int b = 0; b < 8; b++) // 2nd Row
                if (board[1][b] && b != a && (abs((abs((float)b - (float)a) / (float)1) - 1) > 0.01))
                    for (int c = 0; c < 8; c++) // 3rd Row
                        if (board[2][c] && c != b && c != a && (abs((abs((float)c - (float)a) / (float)2) - 1) > 0.01) && (abs((abs((float)c - (float)b) / (float)1) - 1) > 0.01))
                            for (int d = 0; d < 8; d++) // 4th Row
                                if (board[3][d] && d != c && d != b && d != a && (abs((abs((float)d - (float)a) / (float)3) - 1) > 0.01) && (abs((abs((float)d - (float)b) / (float)2) - 1) > 0.01) && (abs((abs((float)d - (float)c) / (float)1) - 1) > 0.01))
                                    for (int e = 0; e < 8; e++) // 5th Row
                                        if (board[4][e] && e != d && e != c && e != b && e != a && (abs((abs((float)e - (float)a) / (float)4) - 1) > 0.01) && (abs((abs((float)e - (float)b) / (float)3) - 1) > 0.01) && (abs((abs((float)e - (float)c) / (float)2) - 1) > 0.01) && (abs((abs((float)e - (float)d) / (float)1) - 1) > 0.01))
                                            for (int f = 0; f < 8; f++) // 6th Row
                                                if (board[5][f] && f != e && f != d && f != c && f != b && f != a && (abs((abs((float)f - (float)a) / (float)5) - 1) > 0.01) && (abs((abs((float)f - (float)b) / (float)4) - 1) > 0.01) && (abs((abs((float)f - (float)c) / (float)3) - 1) > 0.01) && (abs((abs((float)f - (float)d) / (float)2) - 1) > 0.01) && (abs((abs((float)f - (float)e) / (float)1) - 1) > 0.01))
                                                    for (int g = 0; g < 8; g++) // 7th Row
                                                        if (board[6][g] && g != f && g != e && g != d && g != c && g != b && g != a && (abs((abs((float)g - (float)a) / (float)6) - 1) > 0.01) && (abs((abs((float)g - (float)b) / (float)5) - 1) > 0.01) && (abs((abs((float)g - (float)c) / (float)4) - 1) > 0.01) && (abs((abs((float)g - (float)d) / (float)3) - 1) > 0.01) && (abs((abs((float)g - (float)e) / (float)2) - 1) > 0.01) && (abs((abs((float)g - (float)f) / (float)1) - 1) > 0.01))
                                                            for (int h = 0; h < 8; h++) // 8th Row
                                                                if (board[7][h] && h != g && h != f && h != e && h != d && h != c && h != b && h != a && (abs((abs((float)h - (float)a) / (float)7) - 1) > 0.01) && (abs((abs((float)h - (float)b) / (float)6) - 1) > 0.01) && (abs((abs((float)h - (float)c) / (float)5) - 1) > 0.01) && (abs((abs((float)h - (float)d) / (float)4) - 1) > 0.01) && (abs((abs((float)h - (float)e) / (float)3) - 1) > 0.01) && (abs((abs((float)h - (float)f) / (float)2) - 1) > 0.01) && (abs((abs((float)h - (float)g) / (float)1) - 1) > 0.01))
                                                                    cnt++;
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}