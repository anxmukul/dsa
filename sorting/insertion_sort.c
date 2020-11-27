#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int *ar, int n){
    int i,j,temp;
    for(i=0; i<n; i++){
        temp = ar[i];
        for(j=i-1; j>=0; j--){
            if(ar[j]>temp){
                ar[j+1] = ar[j];
            }
            else{
                break;
            }
        }
        ar[j+1] = temp;
    }
}
int main(){
    int n;
    printf("Enter size of arrray\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of arrray\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    printf("After sorting array become\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}