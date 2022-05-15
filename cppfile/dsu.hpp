class DSU {
public:
  std::vector<int> p, size;
  int n, setCount;
  DSU(int _n) : n(_n), setCount(_n), p(_n), size(_n, 1) {
    std::iota(p.begin(), p.end(), 0);
  }
  int find(int x) { return p[x] = x == p[x] ? x : find(p[x]); }
  bool unite(int x, int y) {
    if (size[x] < size[y]) {
      return unite(y, x);
    }
    return p[y] = x, size[x] += size[y], --setCount, true;
  }
  bool helper(int x, int y) {
    int pX = find(x), pY = find(y);
    return pX != pY ? unite(pX, pY) : false;
  }
};
