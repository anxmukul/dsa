//KMP algorithm search a pattern in a string in O(m+n)
#include <bits/stdc++.h>
using namespace std;
void LPSarray(char *pat, int m, int *LPS){
	int len = 0;
	LPS[0] = 0;
	int i = 1;
	while(i < m){
		if(pat[i] == pat[len]){
			len++;
			LPS[i] == len;
			i++;
		}else{
			if(len != 0){
				len = LPS[len-1];
			}
			else{
				LPS[i] = 0;
				i++;
			}
		}
	}
	for(int k=0; k<m; k++){
		cout<<LPS[k]<<endl;
	}
}
void KMPsearch(char *str, char *pat){
	int m = strlen(pat);
	int n = strlen(str);
	cout<<m<<"\t"<<n<<endl;
	int LPS[m];
	LPSarray(pat, m, LPS);
	int i = 0;
	int j = 0;
	while(i<n){
		if(pat[j] == str[i]){
			j++;
			i++;
		}
		if(j == m){
			cout<<"Pattern found INDEX\t"<<i-m<<"-"<<i<<endl;
			j = LPS[j-1];
			// break;
		}
		else if (i < n && pat[j] != str[i]){
			if(j != 0){
				j = LPS[j-1];
			}
			else{
				i += 1;
			}
		}
	}
	// cout<<"NO matches found\n";
}
int main(){
	string String;
	string Pattern;
	cout<<"Enter string and then pattern to search in next line\n";
	cin>>String>>Pattern;
	char str[15], pat[15];
	strcpy(str, String.c_str());
	strcpy(pat, Pattern.c_str());
	cout<<"String:\t"<<str<<"\nPattern\t"<<pat<<endl;
	KMPsearch(str, pat);
	return 0;
}