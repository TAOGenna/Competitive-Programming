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


int arr[10];

int main(){

  int v; cin>>v;
  int mini=1e9,number=0;
  rep(i,1,10){
    cin>>arr[i];
    if(arr[i]<=mini){
      mini=arr[i];
      number=i;
    }
  }
  vector<int> wyn;
  rep(i,0,v/mini){
    wyn.pb(number);
  }
  int res=v % mini;

  for(auto &x : wyn){
    bool chi=false;
    int num=0;
    rep(i,1,10){
      if(i>x and res>=arr[i]-arr[x]){
        chi=true;
        num=i;
      }
    }
    if(chi){
      res-=arr[num]-arr[x];
      x=num;
    }
  }
  if(sz(wyn)){
    for(auto x: wyn) cout<<x;cout<<endl;
  }else{
    cout<<-1<<endl;
  }


  return 0;
}
