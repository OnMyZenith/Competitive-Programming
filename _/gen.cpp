#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int n = rand(1, 5);
    printf("1\n%d\n", n);
    set<int> used;
    for (int i = 0; i < n; ++i) {
        cout << rand(1, 10)<< " ";
    }
    printf("\n");
}