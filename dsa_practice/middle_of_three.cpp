#include <bits/stdc++.h>
using namespace std;
int findmiddle(int a, int b, int c){
	int x = a-b;
	int y = b-c;
	int z = a-c;
	if(x*y > 0){
		return b;
	}
	else if(a*z > 0){
		return a;
	}
	else{
		return c;
	}
}
int main(){
	int x,y,z;
	cout<<"Enter any three number\n";
	cin>>x>>y>>z;
	int mid = findmiddle(x,y,z);
	cout<<"Middle element is "<<mid<<endl;
}