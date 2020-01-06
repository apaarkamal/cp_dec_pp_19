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
		dfs(1, 0);
		cout << '\n';
		bfs(1, n);
	}
}