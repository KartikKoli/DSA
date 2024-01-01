#include<iostream>
#include<stack>
using namespace std;

void prevGreater(int arr[],int n){
    stack<int> s;
    cout<<"-1 ";
    s.push(arr[0]);
    for(int i=1;i<n;i++){
        while(s.empty()==false && s.top()<arr[i]){
            s.pop();
        }
        int pg=(s.empty()==true)?-1:s.top();
        cout<<pg<<" ";
        s.push(arr[i]);
    }
}

int main(){
    int arr[5]={20,30,10,5,15};
    prevGreater(arr,5);
    return 0;
}