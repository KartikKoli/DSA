#include<iostream>
#include<string>
using namespace std;

bool issub(string &s1,string &s2,int n,int m){
    if(n<m) return false;
    int j=0;
    for(int i=0;i<n;i++){
        if(s1[i]==s2[j]) j++;
    }
    return (j==m);
}

int main(){
    string s1="kartik";
    string s2="arit";
    bool res=issub(s1,s2,s1.length(),s2.length());
    if(res==true) cout<<"Yes!";
    else cout<<"No!";
    return 0;
}