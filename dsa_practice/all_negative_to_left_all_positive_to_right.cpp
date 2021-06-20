#include <bits/stdc++.h>
using namespace std;
void reaarange(int *arr, int n)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		if (arr[left] < 0 && arr[right] < 0)
			left += 1;
		else if (arr[left] > 0 && arr[right] < 0)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left += 1;
			right -= 1;
		}
		else if (arr[left] > 0 && arr[right] > 0)
			right -= 1;
		else
		{
			left += 1;
			right -= 1;
		}
	}
}
int main()
{
	int n;
	cout << "Enter size of array\n";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	reaarange(arr, n);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}