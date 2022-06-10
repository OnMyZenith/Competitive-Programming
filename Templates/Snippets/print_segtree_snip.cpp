// Print this segtree
    void print() {
#ifdef asr_debug
        int nodes = 1, spaces = 2 * N, idx = 1;
        while (idx < 2 * N) {
            for (int j = 0; j < nodes; j++) {
                cout << setw(j ? 2 * spaces : spaces);
                if (v[idx] != NEUTRAL_VAL) cout << (v[idx]); else cout << ('_');
                idx++;
            }
            cout << '\n'; nodes *= 2; spaces /= 2;
        }
        for (int k = 0; k < 2 * 2 * N; k++) cout << "-\n"[k == 2 * 2 * N - 1];
#endif
    }
