#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int n = rand(1, 5);
    int l = rand(1, 100);
    int r = rand(100, 500);
    printf("1\n%d %d %d\n", n, l, r);
    set<int> used;
    for (int i = 0; i < n; ++i)
        printf("%d ", rand(1, 20));

    printf("\n");
}