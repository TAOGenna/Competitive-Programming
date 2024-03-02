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

bool check(lli a,lli b,lli tar){
  if(a>=tar and b>=tar){
    a-=tar,b-=tar;
    if(a+b>=tar) return true;
  }
  return false;
}

int main(){
  lli r,g,b; cin>>r>>g>>b;
  lli wyn=min({r,g,b});
  r-=wyn,g-=wyn,b-=wyn;
  vector<lli> foo;
  if(r>0) foo.pb(r);
  if(g>0) foo.pb(g);
  if(b>0) foo.pb(b);
  rep(i,0,abs(2-sz(foo))) foo.pb(0);
  lli lo=0,hi=r+g+b;
  while(lo<=hi){
    lli mid=lo+(hi-lo)/2;
    if( check(foo[0],foo[1],mid) ){
      lo=mid+1;
    }else{
      hi=mid-1;
    }
  }
  cout<<wyn+hi<<endl;
  return 0;
}
