#include <bits/stdc++.h>
using namespace std;
typedef long long int lli; 

const lli N=1e5+10,M=110;
lli dp[N][M];

int main(){
    lli n,W; cin>>n>>W;
    vector<lli> p(n+1),v(n+1);
    for(lli i=1;i<=n;i++){
        cin>>p[i]>>v[i];
    }
    lli wyn=0;
    for(lli i=1;i<=n;i++){
        for(lli w=1;w<=W;w++){
            dp[w][i]=max( ((w-p[i]<0)?0:(dp[w-p[i]][i-1]+v[i])),dp[w][i-1]);
            wyn=max(wyn,dp[w][i]);
        }
    }
    cout<<wyn<<endl;
   return 0;
}
