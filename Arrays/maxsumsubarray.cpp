#include<iostream>
using namespace std;

int max(int a,int b){
    return ((a>b)?a:b);
}

int maxsum(int arr[],int n){
    int res=arr[0];
    int maxending=arr[0];
    for(int i=1;i<n;i++){
        maxending=max(maxending+arr[i],arr[i]);
        res=max(maxending,res);
    }
    return res;
}

int main(){
    int arr[6]={-3,8,-2,4,-5,6};
    cout<<maxsum(arr,6);
    return 0;
}