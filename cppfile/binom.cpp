std::vector<Z> fac(N + 1), infac(N + 1);
for (int i = 0; i <= N; ++i) {
	fac[i] = !i ? 1 : fac[i - 1] * i;
	if (i == N) {
		infac[N] = fac[N].inv();
	}
}
for (int i = N; i; --i) {
	infac[i - 1] = infac[i] * i;
}
auto binom = [&](int n, int m) -> Z {
	if (n < m || m < 0) return 0;
	return fac[n] * infac[m] * infac[n - m];
};
