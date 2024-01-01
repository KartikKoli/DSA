#include<iostream>
using namespace std;

void frequencies(int arr[],int n){
    int freq=1;
    int i=1;
    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
            freq++;
            i++;
        }
        cout<<arr[i-1]<<": "<<freq<<endl;
        i++;
        freq=1;
    }
    if(n==1 || arr[n-1]!=arr[n-2]){
        cout<<arr[i-1]<<": "<<freq<<endl;
    }
}

int main(){
    int arr[6]={10,10,10,30,30,40};
    frequencies(arr,6);
    int arr2[4]={50,60,60,60};
    frequencies(arr2,4);
    return 0;
}