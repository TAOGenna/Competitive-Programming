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
  int n; cin>>n;
  vector<int> ani;
  set<int> temp1;
  rep(i,0,n){
    int num; cin>>num;
    ani.pb(num);
    temp1.insert(num);
  }

  if(sz(temp1)==1){
    cout<<1<<endl;
    rep(i,0,n) cout<<1<<" ";cout<<endl;
  }else{
    vector<int> comp,cant;
    comp.pb(ani[0]);
    cant.pb(1);
    for(int i=1;i<n;i++){
      if(ani[i]==comp.back()) cant.back()++;
      else{
        comp.pb(ani[i]);
        cant.pb(1);
      }
    }
    if(sz(temp1)==2 or sz(comp)%2==0){
      cout<<2<<endl;
      for(int i=0;i<sz(cant);i++){
        for(int j=0;j<cant[i];j++){
          if(i%2==0) cout<<1<<" ";
          else cout<<2<<" ";
        }
      }
      cout<<endl;
    }else{
      cout<<3<<endl;
      for(int i=0;i<sz(cant)-1;i++){
        for(int j=0;j<cant[i];j++){
          if(i%2==0) cout<<1<<" ";
          else cout<<2<<" ";
        }
      }
      for(int i=0;i<cant.back();i++) cout<<3<<" ";
      cout<<endl;
    }

  }
}


int main(){
  int cas; cin>>cas;
  while(cas--) solve();

  return 0;
}
