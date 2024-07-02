#include<stdio.h>
#include<time.h>

clock_t start,stop; //clock_t is a built-in type for processor time(ticks)
double duration; //records the run time(seconds) of a function

int iter_sequential_search(int a[],int n){
    for(int i = 0;i<n;i++){
        if(a[i] == n) return 1;
    }
    return 0;
}
int rec_sequential_search(int a[],int n,int i){ //i is the index of the array
    if(i >= n) return 0; //base case
    if(a[i] == n) return 1;
    return rec_sequential_search(a,n,i+1); //search the next element
}
int iter_binary_search(int a[],int n){
    int left = 0;
    int right = n-1;
    while(left<right){
        int mid = (left+right)/2;
        if(a[mid] > n) right = mid-1; //if the middle element is greater than n,then it implies that n is in the left half of the array
        else if(a[mid] < n) left = mid+1;
        else return 1; // if the middle element is equal to n,then return 1
    }
    return 0;
}
int rec_binary_search(int a[],int n,int left,int right){ //left and right are used to define the range of the array
    if(left>right) return 0;
    int mid = (left+right)/2;
    if(a[mid]>n) return rec_binary_search(a,n,left,mid-1); 
    else if(a[mid]<n) return rec_binary_search(a,n,mid+1,right); //if the middle element is less than n,then it implies that n is in the right half of the array
    else return 1; // if the middle element is equal to n,then return 1
}

int main(){
    int n;
    scanf("%d", &n); //input the size of the array
    int a[n]; //declare an array of size n
    for(int i = 0;i<n;i++)  a[i] = i; //initialize the array
    int k = 100000; //k times to iterate to obtain a total run time
    double total_ticks = 0; //total ticks
    double total = 0; //total run time
    // measure iter_sequential_search function
    for(int i = 0;i<k;i++){
        start = clock(); //record the ticks at the start of the function
        iter_sequential_search(a,n); // call the function
        stop = clock(); //record the ticks at the end of the function
        duration = ((double)(stop-start))/CLK_TCK; //convert ticks to seconds
        total += duration;
        total_ticks += (double)(stop-start); 
    }
    printf("iter_sequential_search:Ticks:%f,Total Time:%f,Duration:%.9f\n",total_ticks,total,total/k);
    // measure rec_sequential_search function
    total = 0; // reset total
    total_ticks = 0;//reset total ticks
    for(int i = 0;i<k;i++){ //iterate k times
        start = clock();
        rec_sequential_search(a,n,0); //call the function
        stop = clock();
        duration = ((double)(stop-start))/CLK_TCK;
        total += duration;
        total_ticks += (double)(stop-start);
    }
    printf("rec_sequential_search:Ticks:%f,Total Time:%f,Duration:%.9f\n",total_ticks,total,total/k);
    k = 10000000; // for binary_search
    // measure iter_binary_search function
    total = 0; // reset total
    total_ticks = 0; // reset total ticks
    for(int i = 0;i<k;i++){ // iterate k times
        start = clock();
        iter_binary_search(a,n);
        stop = clock();
        duration = ((double)(stop-start))/CLK_TCK;
        total += duration;
        total_ticks += (double)(stop-start);
    }
    printf("iter_binary_search:Ticks:%f,Total Time:%f,Duration:%.9f\n",total_ticks,total,total/k);
    // measure rec_binary_search function
    total = 0; // reset total
    total_ticks = 0; // reset total ticks
    for(int i = 0;i<k;i++){
        start = clock();
        rec_binary_search(a,n,0,n-1);
        stop = clock();
        duration = ((double)(stop-start))/CLK_TCK;
        total += duration;
        total_ticks += (double)(stop-start);
    }
    printf("rec_binary_search:Ticks:%f,Total Time:%f,Duration:%.9f\n",total_ticks,total,total/k);
    return 0;
}