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


const lli N=2e5+10;

lli add[2*N],res[2*N];


void solve(void){
  lli n,k; cin>>n>>k;
  vector<lli> v;
  for(lli i=0;i<n;i++){
    lli num; cin>>num;
    v.pb(num);
  }
  vector<pair<lli,lli> > par;
  for(lli i=0;i<n/2;i++){
    par.pb({v[i],v[n-1-i]});
  }
  for(auto [x,y]: par){
  //  line;
  //  cout<<"FOR "<<x<<" "<<y<<endl;
    if(x==y and x==1){
      // one operation
      add[3]++;
      res[1+k]++;
      // two operations
      add[2+k]+=2;
      res[2*k]+=2;
    }else if(x==1 or y==1){
    //  cout<<"one operation"<<endl;
      // one operation
      add[2]++;
      res[x+y-1]++;
      //trace(2,x+y-1);cout<<endl;
      //
      add[x+y+1]++;
      res[max(x,y)+k]++;
    //  trace(x+y+1,max(x,y)+k);
    //  cout<<endl;
    //  cout<<"two operations"<<endl;
      // two operations
      if(max(x,y)!=k){
        add[max(x,y)+k+1]+=2;
        res[2*k]+=2;
        //trace(max(x,y)+k+1,2*k);
      }
    }else{
    //  cout<<"one operation"<<endl;
      // one operation
      add[min(x,y)+1]++;
      res[x+y-1]++;
    //  trace(min(x,y)+1,x+y-1);cout<<endl;
      //
      add[x+y+1]++;
      res[max(x,y)+k]++;
    //  trace(x+y+1,max(x,y)+k);cout<<endl;
      //two operations
    //  cout<<"Two operations"<<endl;
      add[2]+=2;
      res[min(x,y)]+=2;
    //  trace(2,min(x,y));cout<<endl;
      //
      add[max(x,y)+k+1]+=2;
      res[2*k]+=2;
    //  trace(max(x,y)+k+1,2*k);
    }
  }


  lli wyn=1e9,cnt=0;
  for(lli i=2;i<=2*k;i++){
    cnt+=add[i];
    //cout<<i<<" --> "<<cnt<<endl;
    wyn=min(wyn,cnt);
    cnt-=res[i];
  }
  cout<<wyn<<endl;
  for(lli i=0;i<=2*k;i++){
    add[i]=0;
    res[i]=0;
  }
}

int main(){
  int cas; cin>>cas;
  while(cas--){
    solve();
  }
  return 0;
}
