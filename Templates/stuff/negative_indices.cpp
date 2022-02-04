//https://codeforces.com/blog/entry/70472 Errichto's comment
#include <bits/stdc++.h>
using namespace std;

const int M = 10;  // I want indices from -M to +M
int _a[2 * M + 1]; // underlying array of size 2*M+1
int *a = _a + M;   // array that has index [0] in the middle of the big array

// int main() {
//     a[-10] = a[1] = 7;
//     cout << a[-10] << " " << a[3] << " " << a[10] << endl;
// }


//-----------------------------------------
// lemelisk's comment
// Theoretically you can do the same — put a pointer into the center of array.
// You just need to typecast it, if your array has more than one dimension.
// I'm sure that C++ standard looks bad at this kind of casts, so some unobvious pitfalls can arise.

// Array [-N..N][-N..N][-N..N]
const int N = 3;
int _arr[2*N + 1][2*N + 1][2*N + 1];
auto a = reinterpret_cast<int (*)[2*N + 1][2*N +1]>(&_arr[N][N][N]);

// int main() {
// 	for (int i = -N; i <= N; ++i)
// 		for (int j = -N; j <= N; ++j)
// 			for (int k = -N; k <= N; ++k)
// 				cout << a[i][j][k] << " ";
// }


//-----------------------------------------
// tnowak's comment
template<class T>
struct MyArray {
	int offset;
	vector<T> vec;

	MyArray(int n, int off, T &&values = T()) {
		vec.resize(n, values);
		offset = off;
	}

	T& operator[](int i) {
		i += offset;
		assert(0 <= i and i < int(vec.size()));
		return vec[i];
	}
};
// MyArray<int> dp(2 * n, m) creates a vector with 2n elements,
// where i-th element has index i-m. It is possible to create multi-dimensional vectors,
// just like normal vectors: example