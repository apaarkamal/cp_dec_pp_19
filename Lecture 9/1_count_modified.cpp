#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

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
		j = 0;
		for (i = 0; i < n; i++) {
			while (j < n) {
				if (k == 0) {
					if (a[j] == 1) {

					}
					else {
						break;
					}
				}
				else {
					if (a[j] == 0) k--;
				}
				j++;
			}
			// db(i, j);
			ans = max(ans, j - i);
			if (a[i] == 0) k++;
		}
		cout << ans;
	}
}