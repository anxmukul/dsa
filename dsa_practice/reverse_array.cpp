#include <bits/stdc++.h>
using namespace std;
void reverse(int *arr, int n){
	for(int i=0; i<n/2; i++){
		arr[i] = arr[i]*arr[n-(i+1)];
		arr[n-(i+1)] = arr[i]/arr[n-(i+1)];
		arr[i] = arr[i]/arr[n-(i+1)];
	}
	
}
int main(){
	int s;
	cout<<"Enter size of array"<<endl;
	cin>>s;
	int arr[s];
	cout<<"Enter elements of array\n";
	for(int i=0; i<s; i++){
		cin>>arr[i];
	}
	reverse(arr, s);
	for(int j=0; j<s; j++){
		cout<<arr[j]<<" ";
	}
	cout<<endl;
	return 0;
}
