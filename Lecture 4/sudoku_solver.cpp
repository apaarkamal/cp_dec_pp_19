#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

const int n = 9;
int grid[n][n];

void print_grid() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool check(int row, int col, int digit) {
	//row check
	int i, j;
	for (j = 0; j < n; j++) {
		if (grid[row][j] == digit) return false;
	}
	//column check
	for (i = 0; i < n; i++) {
		if (grid[i][col] == digit) return false;
	}
	// 3*3 check
	int start_row = (row / 3) * 3, start_col = (col / 3) * 3;
	for (i = start_row; i < start_row + 3; i++) {
		for (j = start_col; j < start_col + 3; j++) {
			if (grid[i][j] == digit) return false;
		}
	}
	return true;
}

void sudoku_solver(int row, int col) {
	// print_grid();
	if (col == 9) {
		sudoku_solver(row + 1, 0);
		return ;
	}
	if (row == 9 && col == 0) {
		print_grid();
		exit(0);
	}
	if (grid[row][col] == 0) {
		// fill all possible options
		for (int digit = 1; digit <= 9; digit++) {
			if (check(row, col, digit)) {
				grid[row][col] = digit;
				sudoku_solver(row, col + 1);
				grid[row][col] = 0;
			}
		}
	}
	else {
		sudoku_solver(row, col + 1);
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, m, ans = 0, cnt = 0, sum = 0;
		cin >> m;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		sudoku_solver(0, 0);
	}
}