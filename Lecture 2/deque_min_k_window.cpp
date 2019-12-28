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
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> k;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		deque<int> Q;
		for (i = 0; i < k; i++) {
			while (!Q.empty() && a[Q.back()] > a[i]) Q.pop_back();
			Q.push_back(i);
		}
		//////////////
		cout << Q.front() << " ";
		////////////
		for (i = k; i < n; i++) {
			while (!Q.empty() && a[Q.back()] > a[i]) Q.pop_back();
			Q.push_back(i);
			if (Q.front() == i - k) Q.pop_front();
			cout << Q.front() << " ";
		}
	}
}
