// Variation of kadane's algorithm to find start and end index of max sum subarray
#include <bits/stdc++.h>
using namespace std;
int largestSum(int *arr, int n){
	int max_ending_here = 0;
	int max_so_far = INT_MIN;
	int start =0, end = 0, s = 0;
	for(int i=0; i<n; i++){
		max_ending_here = max_ending_here + arr[i];
		if(max_ending_here < arr[i]){
			max_ending_here = arr[i];
			s++;
		}
		if(max_so_far < max_ending_here){
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}
	}
	cout<<"Max sum subarray start from index "<<start<<" ends on index "<<end<<endl;
	cout<<"Hence size is = ";
	return (end-start+1);
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
	cout<<largestSum(arr, s)<<endl;
	return 0;
} 