#include<iostream>
using namespace std;

int focc(int arr[],int low,int high,int key){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(key<arr[mid]) return focc(arr,low,mid-1,key);
    if(key>arr[mid]) return focc(arr,mid+1,high,key);
    else{
        if(mid==0 || arr[mid]!=arr[mid-1]) return mid;
        else return focc(arr,low,mid-1,key);
    }
}

int main(){
    int arr[10]={1,1,2,2,2,3,4,5,5,5};
    int ind=focc(arr,0,9,6);
    if(ind!=-1) cout<<arr[ind]<<" found at index:"<<ind;
    else cout<<"Element not found!";
    return 0;
}