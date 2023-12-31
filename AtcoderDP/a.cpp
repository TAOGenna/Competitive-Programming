# include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int dp[N],h[N];
int n,k;

int go(int pos){
    if(dp[pos]!=-1) return dp[pos];
    dp[pos]=1e9+100;
    for(int i=1;i<=k;i++){
        if(pos-i>=1) dp[pos]=min(dp[pos],go(pos-i)+abs(h[pos]-h[pos-i]));
    }
    return dp[pos];
}

int main(){   
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dp[i]=-1;
        cin>>h[i];
    }
    dp[1]=0;
    cout<<go(n)<<endl;
    return 0;
}

