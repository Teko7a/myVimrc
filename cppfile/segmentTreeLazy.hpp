template <class Info, class Tag, class Merge = std::plus<Info>>
struct LazySegmentTree {
  const int n;
  const Merge merge;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LazySegmentTree(int n)
      : n(n), merge(Merge()), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
  LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        info[p] = init[l];
        return;
      }
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m, r);
      pull(p);
    };
    build(1, 0, n);
  }
  void pull(int p) { info[p] = merge(info[2 * p], info[2 * p + 1]); }
  void apply(int p, const Tag &v) {
    ::apply(info[p], v);
    ::apply(tag[p], v);
  }
  void push(int p) {
    apply(2 * p, tag[p]);
    apply(2 * p + 1, tag[p]);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    if (x < m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m, r, x, v);
    }
    pull(p);
  }
  void modify(int p, const Info &v) { modify(1, 0, n, p, v); }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
      return Info();
    }
    if (l >= x && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    push(p);
    return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
  }
  Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
  bool rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
    if (l >= y || r <= x) {
      return true;
    }
    if (l >= x && r <= y && info[p].c[0] + info[p].c[1] == r - l) {
      apply(p, v);
      return true;
    }
    if (l >= x && r <= y && info[p].c[0] + info[p].c[1] == 0) {
      return false;
    }
    int m = (l + r) / 2;
    push(p);
    bool res;
    if (rangeApply(2 * p + 1, m, r, x, y, v)) {
      res = rangeApply(2 * p, l, m, x, y, v);
    } else {
      res = false;
    }
    pull(p);
    return res;
  }
  bool rangeApply(int l, int r, const Tag &v) {
    return rangeApply(1, 0, n, l, r, v);
  }
};
