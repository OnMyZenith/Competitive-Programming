// Neagtive Indices
//https://codeforces.com/blog/entry/70472 Errichto's comment (also check out lemelisk's comment(for 3D) and tnowak's comment)
const int M = 10;  // I want indices from -M to +M
int _a[2 * M + 1]; // underlying array of size 2*M+1
int *a = _a + M;   // array that has index [0] in the middle of the big array

// int main() {
//     a[-10] = a[1] = 7;
//     cout << a[-10] << " " << a[3] << " " << a[10] << endl;
// }
