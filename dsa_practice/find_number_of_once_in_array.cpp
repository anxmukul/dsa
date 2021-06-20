#include <bits/stdc++.h>
using namespace std;
int countOne(int *arr, int n){
	int low = 0, high = n-1;
	int mid;
	while(high >= low)
    {
        int mid = low + (high - low)/2;
        // Check if the element at middle index is first 1
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
        else if (arr[mid] == 0)
			low = mid+1;
        else
			high = mid-1;
    }
    return -1;
}
int main(){
	int n, max =-1;
	cin>>n;
	int Arr[n];
	for(int i=0; i<n; i++){
		cin>>Arr[i];
	}
	int res = countOne(Arr, n);
	if(res == -1){
		cout<<0<<endl;
	}
	else{
		cout<<n-res<<endl;
	}
	return 0;
}