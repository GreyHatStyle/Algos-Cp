#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define debug(x) printf("[x: %d]",x);
char* issorted(int *arr, int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]) return "unsorted";
    }
    return "sorted";
}
void printArr(int *arr, int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}



int swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insertion_sort(int arr[], int *e){
    int l = arr - arr;
    int r = e - arr;
    r++;
    for (int i = l+1 ; i<=r;i++){
        int key = arr[i];
        int j=i-1;

        while(j>=l && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    return;
}


void heapify(int arr[], int n, int i){
    int larg = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l<n && arr[l]>arr[larg])
        larg = l;

    if(r<n && arr[r]>arr[larg])
        larg = r;
    
    if(larg!=i){
        swap(&arr[i], &arr[larg]);
        heapify(arr, n , larg);
    }

    
}

void heapsort(int arr[], int *e){

    int n = e - arr;
    for(int i = n/2 - 1; i>=0; i--)
        heapify(arr,n,i);

    for(int i=n-1; i>=0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr,i,0);
    }
}


int *Partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low-1);

    for(int j = low;j<high-1;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (arr+i+1);
}

int *MedianOfThree(int * a, int * b, int * c) 
{ 
    if (*a < *b && *b < *c) 
        return (b); 
  
    if (*a < *c && *c <= *b) 
        return (c); 
  
    if (*b <= *a && *a < *c) 
        return (a); 
  
    if (*b < *c && *c <= *a) 
        return (c); 
  
    if (*c <= *a && *a < *b) 
        return (a); 
  
    if (*c <= *b && *b <= *a) 
        return (b); 
} 

void IntroSortUtil(int arr[], int *begin, int *end, int detph_limit){
    int size = end - begin;
    // Debug *arr@(size)
    if(size < 16){
        insertion_sort(arr, end);
        return;
    }

    if(detph_limit == 0){
        heapsort(arr, end);
        return;
    }

    int *pivot = MedianOfThree(begin, begin+size/2, end);
    swap(pivot, end);
    char p = 'p';
    int *pi = Partition(arr, begin-arr, end-arr);
    char a = 'p';
    IntroSortUtil(arr, begin, pi-1, detph_limit-1);
    IntroSortUtil(arr, pi+1, end, detph_limit-1);

    return;

}

void IntroSort(int arr[], int *n){
    int end = n-arr;
    int beg = arr-arr;
    end--;
    int depthlim = 2*log(end-beg);
    
    IntroSortUtil(arr, arr, arr+end , depthlim);
    return;
}

int main(){
    // This code is connected to inputGenerator.py in College python directory
    // Please have a input.txt file in same directory with inputs to test this code!
    FILE *f = fopen("input.txt", "r");
    int n;
    fscanf(f, " %d", &n);
    int i=0;
    int arr[n];
    while (fscanf(f, " %d", &arr[i++]) == 1) {}
    printf("hi");
    IntroSort(arr, arr+n);
    printf("%s\n",issorted(arr,n));
    // printArr(arr,n);
    return 0;
}
