#include<iostream>
using namespace std;

void leaders(int arr[],int n){ // most efficient way, order of printing is reversed
    int curr_leader=arr[n-1];
    cout<<curr_leader<<" ";
    for(int i=n-2;i>=0;i--){
        if(arr[i]>curr_leader){
            curr_leader=arr[i];
            cout<<curr_leader<<" ";
        }
    }
}

int main(){
    int arr[7]={7,10,4,10,6,5,2};
    leaders(arr,7);
    return 0;
}