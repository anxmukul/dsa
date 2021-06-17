// No. of rotation in rottated sorted array will be equal to
// Index of minimum element in that array
#include <bits/stdc++.h>
using namespace std;
int searchIndex(int a[], int n)
{
	if (a[0] < a[n - 1])
	{
		return 0;
	}
	int start = 0, end = n - 1, mid, next, prev, pivot = -1;
	while (start <= end)
	{
		if (a[start] <= a[end])
		{
			return start;
		}
		int mid = start + (end - start) / 2;
		int next = (mid + 1) % n;
		int prev = (mid - 1 + n) % n;
		if (a[mid] <= a[next] && a[mid] <= a[prev])
		{

			pivot = mid;
			break;
		}
		if (a[start] <= a[mid])
		{

			start = mid + 1;
		}
		else if (a[mid] <= a[end])
		{
			end = mid - 1;
		}
	}
	return pivot;
}
int main()
{
	int no;
	cout << "Enter number of element\n";
	cin >> no;
	int arr[no];
	cout << "Enter values of rotated sorted array\n";
	for (int i = 0; i < no; i++)
	{
		cin >> arr[i];
	}
	int x = searchIndex(arr, no); // Is a binary seach based algorithm
	cout << "Min value index or pivot is = " << x << endl;
	return 0;
}