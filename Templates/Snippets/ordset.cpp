// PBDS Ordered set
#include <bits/extc++.h>
using namespace __gnu_pbds;

template <class T> using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
