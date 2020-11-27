#include <stdio.h>
#include <stdlib.h>
int binary_search(int *arr, int v, int s){
    int start = 0;
    int end = s-1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == v){
            return 1;
        }
        if (arr[mid] < v)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}
int main(){
    int t;
    printf("Enter size of array\n");
    scanf("%d", &t);
    int arr[t];
    printf("Enter elements of array\n");
    for(int i=0; i<t; i++){
        scanf("%d", arr[i]);
    }
    sort(arr, arr+t);
    int q;
    printf("Enter number of queries to be searched\n");
    scanf("%d", &q);
    for(int k = 0; k<q; k++){
        int n;
        printf("Enter number to search in array\n");
        scanf("%d",&n);
        int s = binary_search(arr, n, t);
        printf("%d\n", s);
    }
    return 0;
}