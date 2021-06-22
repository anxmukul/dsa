//largest sum Contigous subArray
#include <bits/stdc++.h>
using namespace std;
int largestSum(int *arr, int n){
	int max_ending_here = 0;
	int max_so_far = INT_MIN;
	for(int i=0; i<n; i++){
		max_ending_here = max_ending_here + arr[i];
		if(max_ending_here < arr[i]){
			max_ending_here = arr[i];
		}
		if(max_so_far < max_ending_here){
			max_so_far = max_ending_here;
		}
	}
	return max_so_far;
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
	cout<<"Max sum is "<<largestSum(arr, s)<<endl;
	return 0;
}