#include <bits/stdc++.h>
using namespace std;
// void sort012(int a[], int n)
// {
// 	int zero = 0, one =0, two = 0, j, k;
// 	for(int i=0; i<n; i++){
// 		if(a[i] == 1){
// 			one++;
// 		}
// 		else if(a[i] == 0){
// 			zero++;
// 		}
// 		else{
// 			two++;
// 		}
// 	}
// 	for(int i=0; i<zero; i++){
// 		a[i] = 0;
// 	}
// 	for(int i=zero; i<zero+one; i++){
// 		a[i] = 1;
// 	}
// 	for(int i=zero+one; i<n; i++){
// 		a[i] = 2;
// 	}
// }
//Using dutch national flag algorithm
void sort012(int a[], int n)
{
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high)
	{
		if (a[mid] == 0)
		{
			int temp = a[mid];
			a[mid] = a[low];
			a[low] = temp;
			low++;
			mid++;
		}
		else if (a[mid] == 1)
		{
			mid++;
		}
		else if (a[mid] == 2)
		{
			int temp = a[mid];
			a[mid] = a[high];
			a[high] = temp;
			high--;
		}
	}
}
int main()
{
	int s;
	cout << "Enter size of array" << endl;
	cin >> s;
	int arr[s];
	cout << "Enter elements of array\n";
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	sort012(arr, s);
}