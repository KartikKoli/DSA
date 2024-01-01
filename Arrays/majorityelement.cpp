#include<iostream>
using namespace std;

int majority(int arr[],int n){
    int res=0;
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[res]){
            count++;
        }
        else{
            count--;
            if(count==0){
                res=i;
                count=1;
            }
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[res]){
            count++;
        }
    }
    if(count<=n/2){
        res=-1;
    }
    return res;
}

int main(){
    int arr[5]={6,8,4,8,8};
    cout<<majority(arr,5);
    return 0;
}