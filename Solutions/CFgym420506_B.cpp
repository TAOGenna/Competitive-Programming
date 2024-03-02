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

const int N=1e5+10;
vector<int> g[N];

int main(){
  int n,m,q; cin>>n>>m>>q;
  // m baskets
  // n objects
  for(int i=0;i<n;i++) g[0].pb(i);
  while(q--){
    char tip; cin>>tip;
    if(tip=='s'){
      int a,b; cin>>a>>b;
      int temp=g[a].back();
      g[a].pop_back();
      g[b].pb(temp);
    }else{
      int a,i; cin>>a>>i;
      if(sz(g[a])-1>=i){
        cout<<g[a][i]<<endl;
      }else{
        cout<<-1<<endl;
      }
    }
    // line;
    // for(int i=0;i<=m;i++){
    //   cout<<"basquet: "<<i<<" -> ";
    //   for(auto x : g[i]) cout<<x<<" "; cout<<endl;
    // }
    // line;
  }
  //cout<<"asdasd"<<endl;
  return 0;
}
