template <typename T> struct FenwickTree {
#define lowbit(x) ((x) & -(x))
  int n;
  std::vector<T> tree;
  FenwickTree(int _n) : n(_n), tree(_n, 0) {}
  void modify(int pos, int val) {
    for (pos += 1; pos <= n; pos += lowbit(pos)) {
      tree[pos - 1] += val;
    }
  }
  T query(int pos) {
    T ans = 0;
    for (; pos; pos -= lowbit(pos)) {
      ans += tree[pos - 1];
    }
    return ans;
  }
  T query(int l, int r) { return query(r) - query(l); }
#undef lowbit
};
