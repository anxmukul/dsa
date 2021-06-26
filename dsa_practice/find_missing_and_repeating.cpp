#include <bits/stdc++.h>
using namespace std;
int *findTwoElement(int *arr, int n) {
	static int result[2];
	int count_numbers[n];
	for(int j=0; j<n; j++){
		count_numbers[j] = 0;
	}
	for(int i=0; i<n; i++){
		count_numbers[arr[i]-1]++;
	}
	for(int i=0; i<n; i++){
		if(count_numbers[i] == 0){
			result[1] = i+1;
			// cout<<"Missing number in function is ="<<result[1]<<endl;
		}
		if(count_numbers[i] == 2){
			result[0] = i+1;;
			// cout<<"Repeating number in function\n";
		}
	}
	return result;
}
int main(){
	int N;
	cout<<"Enter number of element in arrray\n";
	cin>>N;
	int a[N];
	cout<<"Enter array element\n";
	for(int i=0; i<N; i++){
		cin>>a[i];
	}
	int *ar;
	ar = findTwoElement(a, N);
	cout<<"Repeating Number = "<<ar[0]<<endl;
	cout<<"Missing Number = "<<ar[1]<<endl;
	return 0;
}

//We can also solve ts this problem using bit manupulaion;
