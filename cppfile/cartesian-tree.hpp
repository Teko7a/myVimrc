struct Node {
  int id, val, p, s[2];
  void init(int _id, int _val, int _p) {
    id = _id, val = _val, p = _p, s[0] = s[1] = 0;
  }
};

template <class Cmp = std::less<>>
int cartesian_build(std::vector<Node> &tree, const Cmp &&cmp = std::less<>()) {
  int n = tree.size() - 1;
  for (int i = 1; i <= n; ++i) {
    int k = i - 1;
    while (cmp(tree[i].val, tree[k].val)) {
      k = tree[k].p;
    }
    tree[i].s[0] = tree[k].s[1];
    tree[k].s[1] = i;
    tree[i].p = k;
    tree[tree[i].s[0]].p = i;
  }
  return tree[0].s[1];
}
