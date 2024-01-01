#include<string>
#include<iostream>
using namespace std;

bool ispal(string &s){
    int start=0;
    int end=s.length()-1;
    while(start<end){
        if(s[start]==s[end]){
            start++;
            end--;
        }
        else return false;
    }
    return true;
}

int main(){
    string s="mom";
    bool res=ispal(s);
    if(res==true) cout<<"Palindrome";
    else cout<<"Not a palindrome";
    return 0;
}