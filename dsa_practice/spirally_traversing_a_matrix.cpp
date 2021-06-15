#include <bits/stdc++.h>
using namespace std;
vector <int> spirallyTraverse(vector<vector<int>> matrix, int r, int c ){
	vector <int> result;
	int t=0, b=r-1, l=0, R=c-1;
	int dir = 0;
	while(t<= b && l <= R){
		if(dir == 0){	
			for(int i=l; i<=R; i++){
				result.push_back(matrix[t][i]);
			}
			t++;
			dir = 1;
		}
		else if(dir == 1){
			for(int i=t; i<=b; i++){
				result.push_back(matrix[i][R]);
			}
			R--;
			dir = 2;
		}
		else if(dir == 2){
			for(int i=R; i>=l; i--){
				result.push_back(matrix[b][i]);
			}
			b--;
			dir = 3;
		}
		else if(dir == 3){
			for(int i=b; i>=t; i--){
				result.push_back(matrix[i][l]);
			}
			l++;
			dir = 0;
		}
	}
	return result;
}
int main(){
	int r,c,temp;
	cout<<"Enter size of matrix\n";
	cin>>r>>c;
	vector<vector<int>> matrix(r, vector<int>(c));
	for(int i=0; i<r; i++){
		cout<<"Enter "<<i+1<<" row of vevector\n";
		for(int j=0; j<c; j++){
			cin>>temp;
			matrix[i][j] = temp;
		}
	}
	vector <int> ret = spirallyTraverse(matrix, r, c);
	for(int i=0; i<r*c; i++){
		cout<<ret[i]<<" ";
	}
	cout<<endl;
	return 0;
}
