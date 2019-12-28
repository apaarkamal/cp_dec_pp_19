#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<P> factors;
void factorisation(int n) {
	// check by 2
	if (n % 2 == 0) {
		int cnt = 0;
		while (n > 1 && n % 2 == 0) {
			n /= 2;
			cnt++;
		}
		factors.pb({2, cnt});
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n > 1 && n % i == 0) {
				n /= i;
				cnt++;
			}
			factors.pb({i, cnt});
		}
	}
	if (n > 1) {
		factors.pb({n, 1});
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
		factorisation(n);
		for (auto x : factors) {
			cout << x.F << " " << x.S << '\n';
		}
	}
}