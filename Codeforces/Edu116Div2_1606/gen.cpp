#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int n = rand(1, 1000);
    int k = rand(1, 1000);
    printf("1\n%d %d\n", n,k);

}