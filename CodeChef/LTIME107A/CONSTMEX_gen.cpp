#include "home.hpp"

// Random number between a and b inclusive
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

// Print n random numbers between l and r inclusive
void prand(int n, int l = 0, int r = 10) {
    f0r(i, n) cout << rand(l, r) << " \n"[i == n - 1];
}

// Print n random UNIQUE numbers between l and r inclusive
void puni(int n, int l = 0, int r = 10) {
    assert(n <= r - l + 1);
    set<int> used;
    f0r(i, n) {
        int x;
        do {
            x = rand(l, r);
        } while (used.count(x));
        cout << x << " \n"[i == n - 1];
        used.insert(x);
    }
}

// Print a random binary string of length n
void pbin(int n) {
    f0r(i, n) { pr(rand(0, 1)); }
    ps();
}

// Print a random set of characters of length n
void pstr(int n, char c = 'a', char d = 'z') {
    if (d < c) swap(c, d);
    f0r(i, n) { pr(char(c + rand(0, int(d - c)))); }
    ps();
}

//NOT necessarily connected // TODO: print connected graphs
// Print a graph with n nodes and m edges
void graph(int n_max, int m_max = -1) {
    int n = rand(2, n_max);     // if theres only one node then edges = 0, will get a seg falut trying to find rand(1,0) for no. of edges
    if (m_max < 0) m_max = n * (n - 1) / 2;
    int m = rand(1, m_max);

    ps(n,m);
    set<pi> used;
    f0r(i, m) {
        int x, y;
        do {
            x = rand(1, n);
            y = rand(1, n);
            if (x > y) swap(x, y);
        } while (x == y || used.count({x, y}));
        used.ins({x, y});
        ps(x, y);
    }
}

// Print a tree with max n_max nodes //from Errichto gen_tree2
void ptree(int n_max){ // Max Nodes
    int n = rand(2, n_max);
    ps(n,n-1,rand(1,n),rand(1,n));  // N nodes and n-1 edges
    vpi edges;
    for (int i = 2; i <= n; ++i) {
        edges.eb(rand(1, i - 1), i);
    }

    vi perm(n + 1); // re-naming vertices
    for (int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    random_shuffle(1+all(perm));

    random_shuffle(all(edges)); // random order of edges

    for (pi edge : edges) {
        int a = edge.ff, b = edge.ss;
        if (rand() % 2) {
            swap(a, b); // random order of two vertices
        }
        ps(perm[a], perm[b]);
    }
}
template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

int main(int argc, char *argv[]) {
    vamos;
    (void)argc;
    srand(atoi(argv[1]));
    // prepareFact(_);

    ps(1);      // One Test Case

    int n = rand(2, 5);
    ps(n);      // Print n

    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    shuffle(v.begin(), v.end(), rng);
    ov(v);





    // pstr(10, 'l', 'k');
    // pstr(10);
    // prand(5);
    // pbin(20);
    // prand(10, 45, 55);
    // puni(12, 1, 12);
    // puni(12, 1, 10); // will fail the assertion

    return 0;
}