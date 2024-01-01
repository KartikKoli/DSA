#include<iostream>
using namespace std;

void maxdiff(int arr[],int n){
    int res=arr[1]-arr[0];
    int min_val=arr[0];
    for(int j=1;j<n;j++){
        if(arr[j]-min_val>res){
            res=arr[j]-min_val;
        }
        if(arr[j]<min_val){
            min_val=arr[j];
        }
    }
    cout<<res;
}

int main(){
    int arr[7]={2,3,10,6,4,8,1};
    maxdiff(arr,7);
    return 0;
}