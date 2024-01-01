#include<iostream>
#include<string>
using namespace std;

bool issub(string &s1,string &s2,int m,int n){
    if(n==0) return true;
    if(m==0) return false;
    if(s1[m-1]==s2[n-1]) return issub(s1,s2,m-1,n-1);
    else return issub(s1,s2,m-1,n);
}

int main(){
    string s1="kartik";
    string s2="arit";
    bool res=issub(s1,s2,s1.length(),s2.length());
    if(res==true) cout<<"Yes!";
    else cout<<"No!";
    return 0;
}