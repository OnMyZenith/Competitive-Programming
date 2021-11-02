#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int n = rand(7, 7);
    printf("1\n");
    char c = 'a' + rand(0, 25);
    printf("%d %c\n", n, c);

    for (int i = 0; i < n; i++) {
        char x = 'a' + rand(0, 25);
        if (rand(0, 2) == 2)
            printf("%c", c);
        else
            printf("%c", x);
    }
    printf("\n");
}