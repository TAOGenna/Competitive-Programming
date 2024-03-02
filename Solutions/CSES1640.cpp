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
//map<lli,lli> m;
const int N=2e5+10;
vector<lli> g[N];
int main(){
  lli n,x; cin>>n>>x;
  vector<pair<lli,lli> > v;
  for(lli i=0;i<n;i++){
    lli num; cin>>num;
    v.pb({num,i});
  }
  //cout<<v[17349].ff<<" "<<v[5783].ff<<endl;
  sort(all(v));
  map<lli,lli> m;
  for(lli i=0,foo=1;i<n;i++){
    if(m.count(v[i].ff)) g[m[v[i].ff]].pb(v[i].ss);
    else{
      m[v[i].ff]=foo++;
      g[m[v[i].ff]].pb(v[i].ss);
    }
  }
  bool chi=false;
  for(auto xx : m){
    lli num = xx.ff;
    lli res = x-num;
    if(m.count(res) and !chi){
      if(res!=num){
        cout<<g[m[num]][0]+1<<" "<<g[m[res]][0]+1<<endl;
        chi=true;
      }else if(res==num and sz(g[m[num]])>=2){
        cout<<g[m[num]][0]+1<<" "<<g[m[num]][1]+1<<endl;
        chi=true;
      }
    }
  }
  if(!chi) cout<<"IMPOSSIBLE"<<endl;

  return 0;
}
