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
        cout <<  *it  << " : " << a << endl;
            err(++it, args...);
}

void solve(){
  int n; cin>>n;
  vector<int> v;
  map<int,int> m,temp_m;
  set<int> s,temp_s;
  for(int i=0;i<2*n;i++){
    int num; cin>>num;
    v.pb(num);
    m[num]++;
    s.insert(num);
  }
  sort(all(v));
  for(int i=0;i<2*n-1;i++){
    int sum=v.back()+v[i];
    int wyn_sum=sum;
    vector<pair<int,int> > wyn;
    temp_m=m;
    temp_s=s;
    temp_m[v.back()]--; if(temp_m[v.back()]==0) temp_s.erase(v.back());
    temp_m[v[i]]--;     if(temp_m[v[i]]==0) temp_s.erase(v[i]);
    sum=max(v.back(),v[i]);
    wyn.pb({v.back(),v[i]});
    bool chi=true;
    for(int j=0;j<n-1;j++){
      int num = *temp_s.rbegin();
      int res = sum-num;
      if(temp_s.count(num) and temp_s.count(res) and ( (num==res)?(temp_m[num]>=2):true ) ){
        temp_m[num]--; if(temp_m[num]==0) temp_s.erase(num);
        temp_m[res]--; if(temp_m[res]==0) temp_s.erase(res);
        wyn.pb({num,res});
      }else{
        chi=false;
        break;
      }
      sum=max(num,sum-num);
    }
    if(chi){
      cout<<"YES"<<endl;
      cout<<wyn_sum<<endl;
      for(auto [x,y]:wyn) cout<<x<<" "<<y<<endl;
      return;
    }
  }
  cout<<"NO"<<endl;
  return;
}


int main(){
  fastio
  int cas; cin>>cas;
  while(cas--) solve();
  return 0;
}
