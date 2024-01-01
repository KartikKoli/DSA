#include<iostream>
using namespace std;

int maxprofit(int ar[],int n){
    int profit=0;
    for(int i=1;i<n;i++){
        if(ar[i]>ar[i-1]){
            profit+=ar[i]-ar[i-1];
        }
    }
    return profit;
}

int main(){
    int price[5]={1,5,3,8,12};
    int res=maxprofit(price,5);
    cout<<res;
    return 0;
}