#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> fun(vector<int> arr,int k){
    int sum=0;
    vector<pair<int,int>> ans;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum%3==0){
        ans.push_back(make_pair(0,k-1));
    }
    int j=k;
    while(j<arr.size()){
        sum=sum-arr[j-k]+arr[j];
        if(sum%3==0){
            ans.push_back(make_pair(j-k+1,j));
        }
        j++;
    }
    return ans;
}

int main(){
    vector<int> arr={8,23,45,12,56,4,3};
    vector<pair<int,int>> res=fun(arr,3);
    for(auto x:res){
        cout<<"{";
        for(int i=x.first;i<=x.second;i++){
            if(i!=x.second) cout<<arr[i]<<",";
            else cout<<arr[i];
        }
        cout<<"}"<<endl;
    }
    return 0;
}