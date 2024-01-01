#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cin.exceptions(cin.failbit);
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (lli)(x).size()
#define wis cout<<endl<<"I already speak english, bitch"<<endl<<endl;
#define line cout<<"---------------------------"<<endl<<endl
 
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
 
#define trace(args...) { string  _s =#args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);}
void err(istream_iterator<string> it){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args){
    cerr <<  *it  << " : " << a << endl;
    err(++it, args...);
}

void solve(void){
    lli n; cin>>n;
    lli sa=0,sb=0;
    set<lli> s;
    s.insert(0);
    bool chi=false;
    for(lli i=1;i<=n;i++){
        lli foo,ta=sa,tb=sb; cin>>foo;
        if(i%2==1) ta+=foo;
        else tb+=foo;
        if(s.count(ta-tb)) chi=true;
        else s.insert(ta-tb);
        sa=ta,sb=tb;
    }
    if(chi) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}



int main(){
    fastio
    int cas; cin>>cas;
    while(cas--) solve();
    return 0;
}
