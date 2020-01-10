#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		int b[n];
		for (i = 0; i < n; i++) {
			cin >> b[i];
		}
		P c[n];
		for (i = 0; i < n; i++) {
			c[i].F = a[i];
			c[i].S = b[i];
		}
		sort(c, c + n);
		int dp[n];
		for (i = 0; i < n; i++) {
			ans = 0;
			for (j = 0; j < i; j++) {
				if (c[j].S <= c[i].S) {
					ans = max(ans, dp[j]);
				}
			}
			dp[i] = ans + 1;
		}
		ans = 0;
		for (i = 0; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		cout << ans << '\n';
	}
}