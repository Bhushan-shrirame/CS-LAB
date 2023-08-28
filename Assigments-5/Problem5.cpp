#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool sumZero(int temp[], int* starti, int* endj, int n)
{
	map<int, int> presum;
	int sum = 0;
	int max_length = 0;
	for (int i = 0; i < n; i++) {
		sum += temp[i];
		if (temp[i] == 0 && max_length == 0) {
			*starti = i;
			*endj = i;
			max_length = 1;
		}
		if (sum == 0) {
			if (max_length < i + 1) {
				*starti = 0;
				*endj = i;
			}
			max_length = i + 1;
		}
		if (presum.find(sum) != presum.end()) {
			int old = max_length;
			max_length = max(max_length, i - presum[sum]);

			if (old < max_length) {
				*endj = i;
				*starti = presum[sum] + 1;
			}
		}
		else
			presum[sum] = i;
	}

	return (max_length != 0);
}

void sumZeroMatrix(int a[][MAX], int row, int col)
{
	int temp[row];
	int fup = 0, fdown = 0, fleft = 0, fright = 0;
	int sum;
	int up, down;
	int maxl = INT_MIN;
	for (int left = 0; left < col; left++) {
		memset(temp, 0, sizeof(temp));
		for (int right = left; right < col; right++) {
			for (int i = 0; i < row; i++)
				temp[i] += a[i][right];
			bool sum = sumZero(temp, &up, &down, row);
			int ele = (down - up + 1) * (right - left + 1);
			if (sum && ele > maxl) {
				fup = up;
				fdown = down;
				fleft = left;
				fright = right;
				maxl = ele;
			}
		}
	}
	if (fup == 0 && fdown == 0 && fleft == 0 && fright == 0
		&& a[0][0] != 0) {
		cout << "No zero-sum sub-matrix exists";
		return;
	}
    cout << "the size of the largest sub-matrix whose sum is 0 is  " << fdown - fup + 1 << "x" <<  fright - fleft + 1 << endl;
}
int main()
{
	int a[][MAX] = { { 9, 7, 16, 5 },
					{ 1, -6, -7, 3 },
					{ 1, 8, 7, 9 },
					{ 7, -2, 0, 10} };

	int row = 4, col = 5;
	sumZeroMatrix(a, row, col);
	return 0;
}
