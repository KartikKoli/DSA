#include<iostream>
using namespace std;

int maxProfit(int arr[],int start,int end){
    if(start<=end){
        return 0;
    }
    int profit=0;
    int curr_profit;
    for(int i=start;i<end;i++){
        for(int j=i+1;i<end;i++){
            if(arr[j]>arr[i]){
                curr_profit=arr[j]-arr[i]+maxProfit(arr,start,i-1)+maxProfit(arr,j+1,end);
                if(curr_profit>profit){
                    profit=curr_profit;
            }
            }
        }
    }
    return profit;
}

int main(){
    int price[5]={1,5,3,8,12};
    int res=maxProfit(price,0,5);
    cout<<res;
    return 0;
}