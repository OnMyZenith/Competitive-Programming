#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int k = rand(0, 100);
    int n = rand(k, 200);
    printf("1\n%d %d\n", n, k);
}