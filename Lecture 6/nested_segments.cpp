#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 400005;
int ended[N];
vector<int> fn;

struct fenwick {
	int n;
	void init(int _n) {
		n = _n + 10;
		fn.clear(); fn.resize(n, 0);
	}
	void add(int x, int val) {
		x++;// 1 based indexing
		while (x <= n) {
			fn[x] += val;
			x += (x & (-x));
		}
	}
	int sum(int x) {
		x++;//1 basaed indexing
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x));
		}
		return ans;
	}
} bit;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		pair<int, int> a[n], b[n];
		vector<int> temp;
		int res[n];
		for (i = 0; i < n; i++) {
			cin >> a[i].F >> a[i].S;
			temp.pb(a[i].F);
			temp.pb(a[i].S);
		}
		sort(temp.begin(), temp.end());
		// coordinate compress
		for (i = 0; i < n; i++) {
			a[i].F = lower_bound(temp.begin(), temp.end(), a[i].F) - temp.begin() + 1;
			a[i].S = lower_bound(temp.begin(), temp.end(), a[i].S) - temp.begin() + 1;
			ended[a[i].S] = i + 1;
			b[i] = a[i];
		}
		sort(a, a + n, [&](P a, P b) {
			return a.S < b.S;
		});
		bit.init(N);
		for (i = 0; i < N; i++) {
			if (ended[i]) {
				int l = b[ended[i] - 1].F, r = b[ended[i] - 1].S;
				res[ended[i] - 1] = bit.sum(r) - bit.sum(l - 1);
				bit.add(l, 1);
			}
		}
		for (i = 0; i < n; i++) {
			cout << res[i] << '\n';
		}
	}
}