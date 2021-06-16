#include <bits/stdc++.h>
using namespace std;
void sort012(int a[], int n)
{
	int zero = 0, one =0, two = 0, j, k;
	for(int i=0; i<n; i++){
		if(a[i] == 1){
			one++;
		}
		else if(a[i] == 0){
			zero++;
		}
		else{
			two++;
		}
	}
	for(int i=0; i<zero; i++){
		a[i] = 0;
	}
	for(int i=zero; i<zero+one; i++){
		a[i] = 1;
	}
	for(int i=zero+one; i<n; i++){
		a[i] = 2;
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