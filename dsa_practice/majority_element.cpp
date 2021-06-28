#include <bits/stdc++.h>
using namespace std;
int majorityElement(int a[], int size){
	int max_element = a[0], count =1;
	for(int i=1; i<size; i++){
		if(max_element == a[i]){
			count++;
		}
		else{
			count--;
		}
		if(count == 0){
			max_element = a[i];
			count = 1;
		}
	}
	int counter = 0;
	for(int i=0; i<size; i++){
		if(a[i] == max_element){
			counter++;
		}
	}
	// cout<<"majority Element = "<<max_element<<" number of occurance = "<<counter<<endl;
	if(counter > size/2){
		return max_element;
	}
	else{
		return -1;
	}
}
int main(){
	int n;
	cout<<"Enter number of element in array\n";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements\n";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<majorityElement(arr, n)<<endl;
	return 0;
}