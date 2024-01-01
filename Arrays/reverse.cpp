#include <iostream>

using namespace std;

void reverse(int arr[],int n){
    int low=0;
    int high=n-1;
    int temp;
    while(low<high){
        temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
    }
    cout<<"Reversed array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    
}
}

int main()
{
    int arr[6]={10,13,15,18,19,20};
    reverse(arr,6);
    return 0;
}
