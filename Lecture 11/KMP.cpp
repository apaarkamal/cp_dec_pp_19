#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> build_lps_array(string pat) {
	int i, j, m = pat.size();
	vector<int> lps(m, 0);
	i = 1; j = 0;
	while (i < m) {
		if (pat[j] == pat[i]) {
			i++; j++;
			lps[i - 1] = j;
		}
		else {
			if (j == 0) {
				i++;
			}
			else {
				j = lps[j - 1];
			}
		}
	}
	return lps;
}

void kmp() {
	string str, pat;
	cin >> str >> pat;
	vector<int> lps = build_lps_array(pat);
	int i = 0, j = 0, m = pat.size(), n = str.size();
	while (i < n) {
		if (str[i] == pat[j]) {
			i++; j++;
			if (j == m) {
				j = lps[j - 1];
				// cout << "matched" << " " << i << " " << j << '\n';
			}
		}
		else {
			if (j == 0) {
				i++;
			}
			else {
				j = lps[j - 1];
			}
		}
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		kmp();
	}
}