#include <bits/stdc++.h>
using namespace std;
int Bsearch(vector<int> arr,int low, int high, int x){
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==x){
            return mid;
        } else if(arr[mid]<x)
            low = mid +1;
        else
            high = mid -1;
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
	int n = nums.size();
	int pivot = -1;
	if (nums[0] < nums[n - 1])
	{
		pivot = 0;
	}
	else
	{
		int start = 0, end = n - 1, mid, next, prev;
		while (start <= end)
		{
			if (nums[start] <= nums[end])
			{
				pivot = start;
				break;
			}
			int mid = start + (end - start) / 2;
			int next = (mid + 1) % n;
			int prev = (mid - 1 + n) % n;
			if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
			{

				pivot = mid;
				break;
			}
			if (nums[start] <= nums[mid])
			{

				start = mid + 1;
			}
			else if (nums[mid] <= nums[end])
			{
				end = mid - 1;
			}
		}
	}
	if(target <= nums[n-1]){
		return Bsearch(nums, pivot, n-1, target);
	}
	else if(target > nums[n-1]){
		return Bsearch(nums, 0, pivot-1, target);
	}
	return -1;
}
int main()
{
	int n, temp;
	cout << "Enter number of element\n";
	cin >> n;
	vector<int> numbers;
	cout << "Enter values of rotated sorted array\n";
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		numbers.push_back(temp);
	}
	int tar;
	cout << "Enter target element\n";
	cin >> tar;
	int result = search(numbers, tar);
	cout << result << endl;
	// search(numbers, tar);
	return 0;
}