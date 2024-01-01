#include<iostream>
#include<string>
using namespace std;

int min(int a,int b,int c){
    if(a<=b && b<=c) return a;
    if(b<=a && b<=c) return b;
    if(c<=a && c<=b) return c;
}

int med(string s1,string s2,int m,int n){
    if(m==0) return n;
    if(n==0) return m;
    if(s1[m-1]==s2[n-1]) return med(s1,s2,m-1,n-1);
    else{
        return 1+min(med(s1,s2,m-1,n),med(s1,s2,m,n-1),med(s1,s2,m-1,n-1));
    }
}

int main(){
    string s1="CAT";
    string s2="CUT";
    cout<<med(s1,s2,3,3);
    return 0;
}