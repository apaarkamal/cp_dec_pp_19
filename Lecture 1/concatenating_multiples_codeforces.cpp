#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M = 11;

int len_of_num(int x) {
	int cnt = 0;
	while (x) {
		cnt++;
		x /= 10;
	}
	return cnt;
}

unordered_map<int, int> mp[M];

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> k;
		int p[M];// powr(10,i) % k
		p[0] = 1 % k;
		for (i = 1; i < M; i++) {
			p[i] = p[i - 1] * 10;
			p[i] %= k;
		}
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 0; i < n; i++) {
			int len = len_of_num(a[i]);
			mp[len][a[i] % k]++;
		}
		for (int len = 1; len < M; len++) {
			for (i = 0; i < n; i++) {
				int val = ((a[i] % k) * p[len]) % k;
				int need = (k - val) % k;
				ans += mp[len][need];
			}
		}
		for (i = 0; i < n; i++) {
			int len = len_of_num(a[i]);
			int val = ((a[i] % k) * (p[len] + 1) % k) % k;
			if (val == 0) ans--;
		}
		cout << ans;
	}
}