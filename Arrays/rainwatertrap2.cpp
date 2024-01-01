#include<iostream>
using namespace std;

int min(int a, int b){
    int res=(a<b)?a:b;
    return res;
}

int max(int a,int b){
    int res=(a>b)?a:b;
    return res;
}

int watertrap(int ar[],int n){
    int res=0;
    int lmax[n],rmax[n];
    lmax[0]=ar[0];
    for(int i=1;i<n;i++){
        lmax[i]=max(lmax[i-1],ar[i]);
    }
    rmax[n-1]=ar[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=max(ar[i],rmax[i+1]);
    }
    for(int i=1;i<n-1;i++){
        res+=min(lmax[i],rmax[i])-ar[i];
    }
    return res;
}

int main(){
    int ar[5]={3,0,1,2,5};
    cout<<watertrap(ar,5);
    return 0;
}