#include<iostream>
using namespace std;

int min(int a, int b){
    int res=(a<b)?a:b;
    return res;
}

int watertrap(int ar[],int n){
    int res=0;
    for(int i=1;i<n-1;i++){
        int lmax=ar[i];
        for(int j=0;j<i;j++){
            if(ar[j]>lmax){
                lmax=ar[j];
            }
        }
        int rmax=ar[i];
        for(int j=i+1;j<n;j++){
            if(ar[j]>rmax){
                rmax=ar[j];
            }
        }
        res+=min(lmax,rmax)-ar[i];
    }
    return res;
}

int main(){
    int ar[5]={3,0,1,2,5};
    cout<<watertrap(ar,5);
    return 0;
}