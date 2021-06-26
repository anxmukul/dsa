// create a temp = str1 + str1, and check wether str2 is substring of temp;
#include <bits/stdc++.h>
using namespace std;
int isRotation(string s1, string s2){
	if (s1.length() != s2.length())
        return 0;
	string temp = s1 + s1;
	return (temp.find(s2) != string::npos); //string::npos actually means until the end of string
}
int main(){
	string str1, str2;
	cout<<"Enter two strings\n";
	cin>>str1>>str2;
	cout<<isRotation(str1, str2)<<endl;
	return 0;
}