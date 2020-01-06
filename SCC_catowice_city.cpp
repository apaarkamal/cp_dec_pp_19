#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1000005;

vector<int> gr[N], grr[N], order, comp[N];
int vis[N];
int num;

void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs(x);
	}
	order.pb(cur);
}

void rdfs(int cur) {
	vis[cur] = 1;
	comp[num].pb(cur);
	for (auto x : grr[cur]) {
		if (!vis[x]) {
			rdfs(x);
		}
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		for (i = 0; i < n; i++) {
			gr[i].clear();
			grr[i].clear();
			vis[i] = 0;
			comp[i].clear();
		}
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			gr[x].pb(y);
			grr[y].pb(x);
		}
		order.clear();
		for (i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}
		reverse(order.begin(), order.end());
		for (i = 0; i < n; i++) {
			vis[i] = 0;
		}
		num = 0;
		for (auto x : order) {
			if (!vis[x]) {
				rdfs(x);
				num++;
			}
		}
		if (num == 1) {
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
			cout << n - comp[0].size() << " " << comp[0].size() << '\n';
			for (i = 1; i < num; i++) {
				for (auto x : comp[i]) {
					cout << x + 1 << " ";
				}
			}
			cout << '\n';
			for (auto x : comp[0]) {
				cout << x + 1 << " ";
			}
			cout << '\n';
		}
	}
}