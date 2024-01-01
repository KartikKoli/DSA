#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool ismatching(char a,char b){
    return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
}

bool solve(string s){
    stack<char> st;
    for(char i:s){
        if(i=='(' || i=='{' || i=='[') st.push(i);
        else{
            if(st.empty()==true) return false;
            else if(ismatching(st.top(),i)==false) return false;
            else st.pop();
        }
    }
    return (st.empty()==true);
}

int main(){
    string s="[[{({[]})}]]";
    if(solve(s)==true) cout<<"Balanced!";
    else cout<<"Unbalanced!";
    return 0;
}