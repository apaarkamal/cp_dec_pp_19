#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int pr[N];
vector<int> primes;

void seive() {
    int i, j;
    for (i = 2; i < N; i++) {
        if (!pr[i]) {
            primes.pb(i);
            for (j = i; j < N; j += i) {
                pr[j]++;
            }
        }
    }
}


int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    seive();
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        int l, r;
        cin >> l >> r;
        n = r - l + 1;
        int a[n];
        for (i = 0; i < n; i++) {
            a[i] = i + l;
        }
        for (auto prime : primes) {
            if (prime * prime > r) break;
            int start = (l / prime) * prime;
            if (prime >= l) start = prime * 2;

            for (i = start; i <= r; i += prime) {
                if (i < l) continue;
                a[i - l] /= prime;
            }
        }
        for (i = 0; i < n; i++) {
            if (i + l == 1 || a[i] != l + i) continue;
            cout << a[i] << "\n";
        }
        cout << '\n';
    }
}