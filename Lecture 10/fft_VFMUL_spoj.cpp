#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

typedef complex < double > base ;
#define PI 3.141592653589793l
void fft(vector<base> &a, bool invert) {
	int i, j, n = a.size();
	for (i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) {
			j -= bit;
		}
		j += bit;
		if (i < j) {
			swap(a[i], a[j]);
		}
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (i = 0; i < n; i += len) {
			base w(1);
			for (j = 0; j < len / 2; ++j) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) {
		for (i = 0; i < n; ++i) {
			a[i] /= n;
		}
	}
}
void multiply(const vector<int> &a, const vector<int> &b, vector <int> &res) {
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	size_t n = 1;
	while (n < max((int)a.size(), (int)b.size())) n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);
	fft(fa, false), fft(fb, false);
	for (size_t i = 0; i < n; ++i) {
		fa[i] *= fb[i];
	}
	fft(fa, true);
	res.resize(n);
	for (size_t i = 0; i < n; ++i) {
		res[i] = (int)(fa[i].real() + 0.5);
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, cnt = 0, sum = 0;
		string s, t;
		cin >> s >> t;
		n = s.size();
		m = t.size();
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		vector<int> p1, p2, res;
		for (i = 0; i < n; i++) {
			p1.pb(s[i] - '0');
		}
		for (i = 0; i < m; i++) {
			p2.pb(t[i] - '0');
		}
		multiply(p1, p2, res);
		// for (auto x : res) {
		// 	cout << x << " ";
		// } cout << '\n';
		vector<int> ans;// final
		int carry = 0;
		for (auto x : res) {
			int val = x;
			x += carry;
			ans.pb(x % 10);
			carry = x / 10;
		}
		while (carry) {
			ans.pb(carry % 10);
			carry /= 10;
		}
		reverse(ans.begin(), ans.end());
		bool non_zero = 0;
		for (auto x : ans) {
			if (x != 0) {
				non_zero = 1;
			}
			if (non_zero) cout << x;
		}
		if (non_zero == 0) {
			cout << 0;
		}
		cout << '\n';
	}
}