#include<iostream>
using namespace std;

int firstocc(int arr[],int low,int high,int key){
    while(low<=high){
        int mid=(low+high)/2;
        if(key<arr[mid]) high=mid-1;
        if(key>arr[mid]) low=mid+1;
        else{
            if(mid==0 || arr[mid]!=arr[mid-1]) return mid;
            else high=mid-1;
        }
    }
    return -1;
}

int lastocc(int arr[],int low,int high,int key){
    while(low<=high){
        int mid=(low+high)/2;
        if(key<arr[mid]) high=mid-1;
        if(key>arr[mid]) low=mid+1;
        else{
            if(mid==high || arr[mid]!=arr[mid+1]) return mid;
            else low=mid+1;
        }
    }
    return -1;
}

int count(int arr[],int key,int n){
    if(firstocc(arr,0,n-1,key)==-1) return 0;
    else return (lastocc(arr,0,n-1,key)-firstocc(arr,0,n-1,key)+1); 
}

int main(){
    int arr[10]={1,1,2,2,2,3,4,5,5,5};
    cout<<count(arr,5,10);
    return 0;
}