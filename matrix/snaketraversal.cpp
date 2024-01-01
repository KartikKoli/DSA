#include<iostream>
using namespace std;

void print(int *arr[],int m,int n){
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

int main(){
    int m,n,a;
    cout<<"Enter no. of rows and cols:";
    cin>>m>>n;
    int *arr[m];
    cout<<"Enter elements of the matrix:"<<endl;
    for(int i=0;i<m;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>a;
            arr[i][j]=a;
        }
    }
    print(arr,m,n);
    return 0;
}