#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *ar, int n){
    int i,j;
    for(i=0; i<n-1; i++){
        int count = 0;
        for(j=0; j<n-1-i; j++){
            if(ar[j]>ar[j+1]){
               int temp = ar[j];
               ar[j] = ar[j+1];
               ar[j+1] = temp;
               count =1;
            }
        }
        if (count == 0){
            break;
        }
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
    bubble_sort(arr, n);
    printf("After sorting array become\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}