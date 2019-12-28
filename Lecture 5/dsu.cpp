struct dsu {
	vector<int> p, sz;
	int comp;
	void init(int NN) {
		sz.clear(); p.clear();
		p.resize(NN); sz.resize(NN, 1);
		iota(p.begin(), p.end(), 0);
		comp = NN;
	}
	int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			p[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
			comp--;
		}
	}
} G;
