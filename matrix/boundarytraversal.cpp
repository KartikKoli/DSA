#include<iostream>
using namespace std;

void print(int *arr[],int m,int n){
    if(m==1){
        for(int i=0;i<n;i++){
            cout<<arr[0][i]<<" ";
        }
    }
    else if(n==1){
        for(int i=0;i<m;i++){
            cout<<arr[i][0]<<" ";
        }
    }
    else{
        for(int i=0;i<n;i++){
            cout<<arr[0][i]<<" ";
        }
        for(int i=1;i<m;i++){
            cout<<arr[i][n-1]<<" ";
        }
        for(int i=n-2;i>=0;i--){
            cout<<arr[m-1][i]<<" ";
        }
        for(int i=m-2;i>0;i--){
            cout<<arr[i][0]<<" ";
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