#include<iostream>
using namespace std;

const int a=50;
const int b=50;
int memo[a][b];

int max(int c,int d){
    return (c>d)?c:d;
}

int lcs(string s1,string s2,int m,int n){
    if(memo[m][n]!=-1){
        return memo[m][n];
    }
    if(m==0 || n==0){
        memo[m][n]=0;
    }
    else{
        if(s1[m-1]==s2[n-1]){
            memo[m][n]=1+lcs(s1,s2,m-1,n-1);
        }
        else{
            memo[m][n]=max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
        }
    }
    return memo[m][n];
}


int main(){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            memo[i][j]=-1;
        }
    }
    int res=lcs("AGGTAB","GXTXAYB",6,7);
    cout<<res;
    return 0;
}