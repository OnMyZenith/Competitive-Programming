/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N = 1;
int col[int(1e5 + 7)];
bitset<300'007> col_tree;
void cset(int idx, bool v) {
    for (col_tree[idx += N] = v; idx >>= 1;) {
        col_tree[idx] = col_tree[idx << 1] & col_tree[idx << 1 | 1];
    }
}

bool cget(int l, int r) {
    bool left = 1, right = 1;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) left &= col_tree[l++];
        if (r & 1) right &= col_tree[--r];
    }
    return left & right;
}

int row[int(1e5 + 7)];
bitset<263'000> row_tree;
void rset(int idx, bool v) {
    for (row_tree[idx += N] = v; idx >>= 1;) {
        row_tree[idx] = row_tree[idx << 1] & row_tree[idx << 1 | 1];
    }
}

bool rget(int l, int r) {
    bool left = 1, right = 1;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) left &= row_tree[l++];
        if (r & 1) right &= row_tree[--r];
    }
    return left & right;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;
    while (N < n) N *= 2;
    for (int i = N + n; i < 2 * N; i++) row_tree[i] = 1, col_tree[i] = 1;
    for (int i = N - 1; --i;) {
        row_tree[i] = row_tree[i << 1] & row_tree[i << 1 | 1];
        col_tree[i] = col_tree[i << 1] & col_tree[i << 1 | 1];
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int r, c; cin >> r >> c; r--, c--;
            if (!row[r]) {
                rset(r, 1);
            }
            if (!col[c]) {
                cset(c, 1);
            }
            row[r]++; col[c]++;
        } else if (t == 2) {
            int r, c; cin >> r >> c; r--, c--;
            row[r]--; col[c]--;
            if (!row[r]) {
                rset(r, 0);
            }
            if (!col[c]) {
                cset(c, 0);
            }
        } else {
            int r1, c1; cin >> r1 >> c1; r1--, c1--;
            int r2, c2; cin >> r2 >> c2;
            if (rget(r1, r2) || cget(c1, c2)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}