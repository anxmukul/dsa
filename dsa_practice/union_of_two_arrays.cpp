#include <bits/stdc++.h>
using namespace std;

// Method 1 using sorting and searching
// int countDistinct(int arr[], int n)
// {
//     int res = 0;
//     for (int i = 0; i < n; i++) {
//         while (i < n - 1 && arr[i] == arr[i + 1])
//             i++;
//         res++;
//     }
//     return res;
// }
// int doUnion(int a[], int n, int b[], int m)  {
// 	sort(a, a+n);
// 	sort(b, b+m);
// 	//Number of different element in first array
// 	int N = countDistinct(a, n);
// 	int M = countDistinct(b, m);
// 	cout<<N<<endl;
// 	cout<<M<<endl;
// 	int total = N+M;
// 	int prev = -1;
// 	for(int i=0; i<m; i++){
// 		if(b[i] != prev){
// 			int target = b[i];
// 			int start =0, end = n-1;
// 			int mid;
// 			while (start <= end)
// 			{
// 				mid = start + (end-start)/2;
// 				if(a[mid] == target){
// 					total--;
// 					break;
// 				}
// 				else if(a[mid] < target){
// 					start = mid + 1;
// 				}
// 				else{
// 					end = mid-1;
// 				}
// 			}
// 		}
// 		prev = b[i];
// 	}
// 	return total;
// }

// Method 2 using set
int doUnion(int a[], int n, int b[], int m){
	set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(a[i]);
   
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    return s.size();
}
int main(){
	int n,m;
	cout<<"Enter size of two arrays\n";
	cin>>n>>m;
	int arra[n];
	int arrb[m];
	cout<<"Enter element of first array\n";
	for(int i=0; i<n; i++){
		cin>>arra[i];
	}
	cout<<"Enter element of second array\n";
	for(int i=0; i<m; i++){
		cin>>arrb[i];
	}
	int res = doUnion(arra, n, arrb, m);
	cout<<"Union of given two array is = "<<res<<endl;
}