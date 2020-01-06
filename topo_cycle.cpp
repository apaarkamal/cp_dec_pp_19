#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> gr[N];
int vis[N];

void dfs(int cur, int par) {
	cout << cur << '\n';
	for (int i = 0; i < gr[cur].size(); i++) {
		if (gr[cur][i] != par) {
			dfs(gr[cur][i], cur);
		}
	}
}

void bfs(int root, int n) {
	int vis[n + 1] = {};
	queue<int> Q;
	Q.push(root);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		vis[cur] = 1;
		cout << cur << '\n';
		for (int i = 0; i < gr[cur].size(); i++) {
			if (!vis[gr[cur][i]]) {
				Q.push(gr[cur][i]);
			}
		}
	}
}

vector<int> order;
void topo(int cur, int par) {
	for (int i = 0; i < gr[cur].size(); i++) {
		if (gr[cur][i] != par) {
			topo(gr[cur][i], cur);
		}
	}
	order.pb(cur);
}

bool cycle ;
void cycle_detect(int cur, int par) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			cycle_detect(x, cur);
		}
		else if (x != par && vis[x] == 1) {
			cycle = 1;
		}
	}
	vis[cur] = 2;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			gr[x].pb(y);
			gr[y].pb(x);
		}

	}
}