#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

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
		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		if (x != y) {
			p[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
			comp--;
		}
	}
} G;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		tuple<int, int, int> edges[m];
		for (i = 0; i < n; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			edges[i] = {w, x, y};
		}
		sort(edges, edges + m);
		G.init(n + 1);
		for (i = 0; i < n; i++) {
			int w = get<0>(edges[i]);
			int x = get<1>(edges[i]);
			int y = get<2>(edges[i]);
			if (G.get(x) != G.get(y)) {
				ans += w;
				G.unite(x, y);
			}
		}
		cout << ans;
	}
}