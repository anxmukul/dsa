#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n){
	int temp = arr[n-1];
	for(int i=n-1; i>= 1; i--){
		arr[i] = arr[i-1];
	}
	arr[0] = temp;
}
int main(){
	int n; 
	cout<<"Enter array size\n";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	rotate(arr, n);
}