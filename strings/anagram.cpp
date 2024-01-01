#include<iostream>
#include<string>
using namespace std;

const int CHAR=256;

bool isAnagram(string &s1,string &s2){
    if(s1.length()!=s2.length()) return false;
    int count[CHAR]={0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i=0;i<CHAR;i++){
        if(count[i]!=0) return false;
    }
    return true;
}

int main(){
    string s1="kartik";
    string s2="kitrkk";
    bool res=isAnagram(s1,s2);
    if(res==true) cout<<"Yes!";
    else cout<<"No!";
    return 0;
}