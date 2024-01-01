#include<iostream>
using namespace std;

int maxcount(bool arr[],int n){
    int res=0,count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count=0;
        }
        else{
            count++;
            if(count>res){
                res=count;
            }
        }
    }
    return res;
}

int main(){
    bool arr[7]={0,1,1,0,1,1,1};
    cout<<maxcount(arr,7);
    return 0;
}