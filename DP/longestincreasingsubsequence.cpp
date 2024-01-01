#include<iostream>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}

int lis(int arr[],int n){
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int res=dp[0];
    for(int i=1;i<n;i++){
        res=max(res,dp[i]);
    }
    return res;
}

int main(){
    int arr[6]={10,5,18,7,2,9};
    cout<<lis(arr,6);
    return 0;
}