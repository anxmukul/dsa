#include <bits/stdc++.h>
using namespace std;
int countOnceInSetBit(int n){
	int count = 0;
	while(n != 0){
		if(n%2 == 1){
			count++;
		}
		n = n/2;
	}
	return count;

}
int main(){
	int n;
	cout<<"Enter any number\n";
	cin>>n;
	cout<<countOnceInSetBit(n)<<endl;
	return 0;
}