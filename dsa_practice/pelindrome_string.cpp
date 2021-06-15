#include <bits/stdc++.h>
using namespace std;
int pelindrome(string s){
	int l = s.length();
	for(int i=0; i<l/2; i++){
		if(s[i] != s[l-(i+1)]){
			return 0;
		}
	}
	return 1;
}
int main(){
	string s;
	cout<<"Enter a string\n";
	cin>>s;
	int r = pelindrome(s);
	cout<<r<<endl;
	return 0;
}