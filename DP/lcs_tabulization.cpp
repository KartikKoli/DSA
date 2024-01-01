#include<iostream>
#include<string>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}

int lcs(string s1,string s2){
    int m=s1.length();
    int n=s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int j=0;j<=m;j++){
        dp[j][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    int res=lcs("KARTIK","JARVIS");
    cout<<res;
    return 0;
}