#include<iostream>
using namespace std;

void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]) min_ind=j;
        }
        swap(arr[min_ind],arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[10]={20,50,30,100,10,80,40,60,90,70};
    selection(arr,10);
    return 0;
}