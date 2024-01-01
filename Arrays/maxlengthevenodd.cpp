#include<iostream>
using namespace std;

int max(int a,int b){
    return ((a>b)?a:b);
}

int maxlength(int arr[],int n){
    int res=1;
    int curr=1;
    for(int i=1;i<n;i++){
        if((arr[i]%2==0 && arr[i-1]%2==1)||(arr[i]%2==1 && arr[i-1]%2==0)){
            curr++;
            res=max(res,curr);
        }
        else{
            curr=1;
        }
    }
    return res;
}

int main(){
    int arr[6]={5,10,20,6,3,8};
    cout<<maxlength(arr,6);
    return 0;
}