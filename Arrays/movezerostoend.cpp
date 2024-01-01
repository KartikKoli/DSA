#include <iostream>

using namespace std;

void movezeros(int arr[],int n){
    int count=0;
    int temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp=arr[i];
            arr[i]=arr[count];
            arr[count]=temp;
            count++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[6]={1,0,5,0,0,4};
    movezeros(arr,6);
    return 0;
}
