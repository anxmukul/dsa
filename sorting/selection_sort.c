#include <stdio.h>
#include <stdlib.h>
void selection_sort(int *ar, int n){
    int i,j;
    for(i=0; i<n-1; i++){
        int min = i;
        for(j=i+1; j<n; j++){
            if(ar[j] < ar[min]){
                min = j;
            }
        }
        int temp = ar[i];
        ar[i] = ar[min];
        ar[min] = temp;
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
    selection_sort(arr, n);
    printf("After sorting array become\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}