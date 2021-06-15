#include <bits/stdc++.h>
using namespace std;
void minmax(int arr[], int n){
	int min = arr[0];
	int max = arr[0];
	if(n == 1){
		cout<<"Min "<<min<<endl;
		cout<<"Max "<<max<<endl;
	}
	else{
		for(int i=1; i<n; i++){
			if(arr[i] > max){
				max = arr[i];
			}
			if(arr[i] < min){
				min = arr[i];
			}
		}
		cout<<"Min "<<min<<endl;
		cout<<"Max "<<max<<endl;
	}
}
int main(){
	int arr[] = {3, 5, 9, 34, 76, 21, 0};
	minmax(arr, 7);
	return 0;
}