#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli dp[100010][110],maxi=1e9+10;

int main(){
    lli N,W,sum=0; cin>>N>>W;
    vector<lli> w(N+1),m(N+1);
    for(lli i=1;i<=N;i++){
        cin>>w[i]>>m[i];
        sum+=m[i];
    }
    lli wyn=0;
    memset(dp,maxi,sizeof(dp));
    dp[0][0]=0;
    for(lli i=1;i<=N;i++){
        for(lli v=0;v<=sum;v++){
            dp[v][i]=min( ((v-m[i]<0)?maxi:(dp[v-m[i]][i-1]+w[i])),dp[v][i-1]);
            if(dp[v][i]<=W) wyn=max(wyn,v);
        }
    }
    cout<<wyn<<endl;
    return 0;
}
