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

int main(){
  fastio
  lli n,m; cin>>n>>m;
  vector<lli> v;
  for(lli i=0;i<n;i++){
    lli num; cin>>num;
    v.pb(num);
  }
  sort(all(v));
  while(m--){
    lli target; cin>>target;
    lli lo=0,hi=sz(v)-1;
    while(lo<=hi){
      int mid=lo+(hi-lo)/2;
      if(v[mid]>target) hi=mid-1;
      else lo=mid+1;
    }
  //  trace(hi,v[hi]);
    if(sz(v) and v[0]<=target){
      cout<<v[hi]<<endl;
      v.erase(v.begin()+hi);
    }else{
      cout<<-1<<endl;
    }
  }
  return 0;
}
