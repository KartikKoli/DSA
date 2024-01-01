#include<iostream>
using namespace std;

int findsecondlargest(int arr[],int n){
    int largest=0;
    int res=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[largest]){
            res=largest;
            largest=i;
        }
        else if(arr[i]!=arr[largest]){
            if(arr[i]>arr[res] || res==-1){
                res=i;
            }
        }
    }
    return res;
}

int main(){
    int arr1[5]={10,12,6,20,12};
    cout<<findsecondlargest(arr1,5);
    return 0;
}