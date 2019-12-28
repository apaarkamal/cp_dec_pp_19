#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int a[N], n, k;

bool check(int x) {
	int given = 0, painters = 1;
	for (int i = 0; i < n; i++) {
		given += a[i];
		if (given > x) {
			painters++;
			given = a[i];
		}
	}
	return painters <= k;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t; while (t--)
	{
		int i, j, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> k;
		int mx = -1;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
			sum += a[i];
		}
		int lf = mx, rt = sum;
		while (lf < rt) {
			int mid = (lf + rt) / 2;
			if (check(mid)) {
				rt = mid;
			}
			else {
				lf = mid + 1;
			}
		}
		cout << lf << '\n';
	}
}