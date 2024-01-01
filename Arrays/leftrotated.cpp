#include<iostream>
using namespace std;

void leftrotatea(int arr[],int n, int d){  //extra space required
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=0;i<d;i++){
        arr[n-d+i]=temp[i];
    }
}

void reverse(int arr[],int low,int high){
    int temp;
    while(low<high){
        temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
    }
}

void leftrotateb(int arr[],int n,int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main(){
    int arr[5]={1,2,3,4,5};
    leftrotatea(arr,5,2);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    leftrotateb(arr,5,3);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}