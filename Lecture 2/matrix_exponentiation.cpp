#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

const int mod = 1e9 + 7;
const int sz = 2;
struct Mat
{
	int m[sz][sz];

	Mat()
	{
		memset(m, 0, sizeof m);
	}

	void eye()
	{
		for (int i = 0; i < sz; i++)
			m[i][i] = 1;
	}

	Mat operator* (const Mat &a) const
	{
		Mat r;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				for (int k = 0; k < sz; k++)
					r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j]) % mod;
		return r;
	}
};

int solve(int n)
{
	Mat r, a;
	r.eye();
	a.m[0][0] = a.m[0][sz - 1] = a.m[1][0] = 1;
	while (n)
	{
		if (n & 1)
			r = r * a;
		a = a * a;
		n >>= 1;
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cout << r.m[i][j] << " ";
		}
		cout << '\n';
	}
	return r.m[0][0];
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		solve(2);

	}
}