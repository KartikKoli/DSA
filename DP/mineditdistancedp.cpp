#include<iostream>
#include<string>
using namespace std;

int min(int a,int b,int c){
    if(a<=b && b<=c) return a;
    if(b<=a && b<=c) return b;
    if(c<=a && c<=b) return c;
}

int med(string s1,string s2){
    int m=s1.size();
    int n=s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s1="CAT";
    string s2="CUT";
    cout<<med(s1,s2);
    return 0;
}