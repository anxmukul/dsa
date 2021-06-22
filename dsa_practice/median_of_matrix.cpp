#include <bits/stdc++.h>
using namespace std;
int findMedian(vector<vector<int> > matrix, int r, int c) {
    vector <int> temporary;
	vector<vector<int>> result(r , vector<int> (c));
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			temporary.push_back(matrix[i][j]);
		}
	}
	sort(temporary.begin(), temporary.end());
    int total = r*c;
    if(total % 2 == 1){
        return temporary[total/2];
    }
    else{
        int temp = temporary[total/2] + temporary[(total/2) + 1];
        return temp/2;
    }
}
int main(){
	int n,m;
	cout<<"Enter size of matrix\n";
	cin>>n>>m;
	vector<vector<int>> vec( n , vector<int> (m, 0));
    for(int i = 0; i < n; i++)
    {
		int temp;
        for(int j = 0; j < m; j++)
        {
            cin>>temp;
			vec[i][j] = temp;
        }
        cout<< endl;
    }
	int r = findMedian(vec, n, m);
    cout<<"Median = "<<r<<endl;
    return 0;
}