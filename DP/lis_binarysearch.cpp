#include<iostream>
using namespace std;

int ceilind(int arr[],int l,int r,int x){
    while(l<r){
        int mid=(l+r)/2;
        if(arr[mid]>=x){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return r;
}

int lis(int ar[],int n){
    int tail[n];
    int len=1;
    tail[0]=ar[0];
    for(int i=1;i<n;i++){
        if(ar[i]>tail[len-1]){
            tail[len]=ar[i];
            len++;
        }
        else{
            int ind=ceilind(tail,0,len-1,ar[i]);
            tail[ind]=ar[i];
        }
    }
    return len;
}

int main(){
    int arr[6]={10,5,18,7,2,9};
    cout<<lis(arr,6);
    return 0;
}