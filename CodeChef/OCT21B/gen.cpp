#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int n = rand(1, 4);
    int k = n * (n + 1) / 2;
    printf("1\n");
    printf("%d %d\n", n, k);
    for (int i = 0; i < n; ++i) {
        int x = rand(0, n + 1);
        printf("%d ", x);
    }
    printf("\n");
}