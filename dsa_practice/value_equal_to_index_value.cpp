#include <bits/stdc++.h>
using namespace std;
vector<int> valueEqualToIndex(int arr[], int n) {
	vector <int> res;
	for(int i=0; i<n; i++){
		if(arr[i] == i+1){
			res.push_back(i+1);
		}
	}
	return res;
}
int main()
{
	int s;
	cout << "Enter size of array" << endl;
	cin >> s;
	int arr[s];
	cout << "Enter elements of array\n";
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	vector <int> result = valueEqualToIndex(arr, s);
	 for (auto i = result.cbegin(); i != result.cend(); ++i)
        cout << *i << " ";
}