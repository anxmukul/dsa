#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
	vector <int> temporary;
	vector<vector<int>> result(N , vector<int> (N));
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			temporary.push_back(Mat[i][j]);
		}
	}
	sort(temporary.begin(), temporary.end());
	int k=N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int index = (k*i) + j;
			result[i][j] = temporary[index];
		}
	}
	return result;
}
int main(){
	int n;
	cout<<"Enter size of array\n";
	cin>>n;
	cout<<"Enter element row wise\n";
	vector<vector<int>> vec(n , vector<int> (n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int temp;
			cin>>temp;
			vec[i][j] = temp;
		}
	}
	vector<vector<int>> res = sortedMatrix(n, vec);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}