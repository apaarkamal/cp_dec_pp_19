#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<pair<int, int>> gr[N];

bool vis[N];
int mindis[N];
int dijsktra(int src, int des) {
	// priority_queue min
	priority_queue<P, vector<P>, greater<P>> Q;
	for (int i = 0; i < N; i++) {
		mindis[i] = INT_MAX;
		vis[i] = false;
	}

	// insert source with its distance in the queue
	Q.push({0, src});
	// {distance, vertex}
	// main algo started
	while (!Q.empty()) {
		// topmost smallest distance element
		pair<int, int> tp = Q.top();
		Q.pop();

		int cur = tp.S;
		int dis = tp.F;

		if (vis[cur]) continue;

		vis[cur] = true;
		mindis[cur] = dis;

		for (auto x : gr[cur]) {
			Q.push({mindis[cur] + x.S, x.F});
		}
	}
	return mindis[des];
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		for (i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			gr[x].pb({y, w});
			gr[y].pb({x, w});
		}

	}
}