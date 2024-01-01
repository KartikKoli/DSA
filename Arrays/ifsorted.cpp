#include <iostream>

using namespace std;

bool ifsorted(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[5]={10,13,15,19,20};
    bool result=ifsorted(arr,5);
    if(result==0){
        cout<<"Array is not sorted!";
    }
    else{
        cout<<"Array is sorted!";
    }
    return 0;
}
