#include <stdio.h>
#include <stdlib.h>
void heapify(int *a, int i, int n){
    int left, right, max;
    left = 2*i +1;
    right = 2*i + 2;
    max  = i;
    if(left <n && a[max] < a[left]){
        max = left;
    }
    if(right <n && a[max] < a[right]){
        max = right;
    }
    if(max != i){
        int temp;
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        heapify(a, max, n);
    }
}
int main(){
    int a[10] = {4, 10, 9, 3, 8, 7, 12, 2, 1, 6};
    int n=10;
    for(int i=(n/2 - 1); i>=0; i--){
        heapify(a, i, n);
    }
    int j=0;
    while(j < 10){
        printf("%d ", a[j]);
        j++;
    }
    printf("\n");
    return 0;
}