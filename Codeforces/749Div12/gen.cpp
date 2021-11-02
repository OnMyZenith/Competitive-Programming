#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int n = rand(3, 3);
    int m = rand(3, 3);
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (rand(1, 3) == 1) cout << 'X';
            else
                cout << '.';
        }
        cout << '\n';
    }
    printf("10\n");
    for (int i = 0; i < 10; i++){
        int x = rand(1, m);
        int y = rand(1, m);
        if (x > y) swap(x, y);
        cout << x << " " << y << '\n';
    }
    printf("\n");
}