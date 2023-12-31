#include <bits/stdc++.h> 
using namespace std;

int dp[2][3];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        dp[1][0]=max(dp[0][1],dp[0][2])+a;
        dp[1][1]=max(dp[0][0],dp[0][2])+b;
        dp[1][2]=max(dp[0][1],dp[0][0])+c;

        for(int j=0;j<3;j++) dp[0][j]=dp[1][j];
    }
    cout<<max({dp[1][0],dp[1][1],dp[1][2]})<<endl;
    return 0;
}
