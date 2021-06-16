#include <bits/stdc++.h>
using namespace std;
// int firstOccurance(int arr[], int n, int x){
// 	int res = -1;
// 	int start = 0;
//     int end = n-1;
//     while(start <= end){
//         int mid = start + (end - start) / 2;
//         if(arr[mid] == x){
// 			res = mid;
// 			end = mid-1;
//         }
//         if (arr[mid] < x)
//             start = mid + 1;
//         else
//             end = mid - 1;
//     }
// 	return res;
// }
// int lastOccurance(int arr[], int n, int x){
// 	int res = -1;
// 	int start = 0;
//     int end = n-1;
//     while(start <= end){
//         int mid = start + (end - start) / 2;
//         if(arr[mid] == x){
// 			res = mid;
// 			start = mid+1;
//         }
//         if (arr[mid] < x)
//             start = mid + 1;
//         else
//             end = mid - 1;
//     }	
// 	return res;
// }
// vector<int> find(int arr[], int n, int x)
// {
// 	vector <int> result;
// 	result.push_back(firstOccurance(arr, n, x));
// 	result.push_back(lastOccurance(arr, n, x));
// 	return result;
// }
vector<int> find(int arr[], int n , int x )
{
    vector<int> res;
    int low = 0;
    int high = n-1;
    int mid=0;
    bool isPresent = false;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==x){
            isPresent = true;
            break;
        } else if(arr[mid]<x)
            low = mid +1;
        else
            high = mid -1;
    }
    if(isPresent==false){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    low = mid;
    high = mid;
    while(arr[low]==x){
        low--;
    }
    while(arr[high]==x){
        high++;
    }
    res.push_back(low+1);
    res.push_back(high-1);
    return res;
}
int main()
{
	int n, t;
	cout << "Enter size of array\n";
	cin >> n;
	cout << "value of x = ";
	cin >> t;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> result = find(arr, n, t);
	for (int i = 0; i < 2; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
