#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int j = 0;
	while (j < m)
	{
		if (matrix[j][n-1] >= target)
		{
			int start = 0;
			int end = n - 1;
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				if (matrix[j][mid] == target)
				{
					return true;
				}
				if (matrix[j][mid] < target)
					start = mid + 1;
				else
					end = mid - 1;
			}
			return false;
		}
		else
		{
			j++;
		}
	}
	return false;
}
int main()
{
	int r, c, t, temp;
	;
	cout << "Enter size of matrix\n";
	cin >> r >> c;
	cout << "Enter target number\n";
	cin >> t;
	vector<vector<int>> mat(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		cout << "Enter " << i + 1 << " row of vevector\n";
		for (int j = 0; j < c; j++)
		{
			cin >> temp;
			mat[i][j] = temp;
		}
	}
	bool result = searchMatrix(mat, t);
	cout << result << endl;
	return 0;
}