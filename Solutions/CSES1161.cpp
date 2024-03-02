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

const int N=2e5+10;
lli arr[N];

lli solve(lli l, lli r){
  // find the half in value of that array
  lli half = (arr[r]-arr[l-1])/2;
  lli lo=l,hi=r;
  while(lo<=hi){
    lli mid = lo + (hi-lo)/2;
    lli val = arr[mid]-arr[l-1];
    if(val <= half) lo = mid+1;
    else{
      hi=mid-1;
      
    }
  }
}



int main(){
  lli n,x; cin>>x>>n;
  vector<lli> v;
  for(int i=1;i<=n;i++){
    lli num; cin>>num;
    v.pb(num);
    arr[i]=arr[i-1]+num;
  }
  lli wyn = solve(1,n);
  return 0;
}
