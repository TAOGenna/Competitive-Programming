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

const int N=50+2;
char g[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[N][N];
int n,m;

bool fun(vector<pair<int,int> > pos,bool chi){
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j]=false;

  queue<pair<int,int> > q;
  q.push({n-1,m-1});

  while(!q.empty()){
    pair<int,int> foo=q.front(); q.pop();
    int x=foo.ff, y=foo.ss;
    for(int i=0;i<4;i++){
      int nx=x+dx[i],ny=y+dy[i];
      if(nx<0 or ny<0 or nx>=n or ny>=m) continue;
      if(g[nx][ny]=='#') continue;
      if(vis[nx][ny]) continue;
      vis[nx][ny]=true;
      q.push({nx,ny});
    }
  }
  bool wyn=true;
  if(chi){//searching for good
    for(auto [x,y]: pos) if(!vis[x][y]) wyn=false;
  }else{//searching for bad
    for(auto [x,y]: pos) if(vis[x][y]) wyn=false;
  }
  return wyn;
}

void solve(void){
  cin>>n>>m;
  vector<pair<int,int> > pos,good;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char temp; cin>>temp;
      g[i][j]=temp;
      if(temp=='B') pos.pb({i,j});
      if(temp=='G') good.pb({i,j});
    }
  }
  for(auto [x,y]:pos){
    for(int i=0;i<4;i++){
      int nx=x+dx[i],ny=y+dy[i];
      if(nx<0 or ny<0 or nx>=n or ny>=m) continue;
      if(g[nx][ny]=='G' or g[nx][ny]=='B') continue;
      g[nx][ny]='#';
    }
  }

  //check
  bool wyn = fun(good,true);
  if(g[n-1][m-1]=='#' and sz(good)) wyn=false;
  if(g[n-1][m-1]!='#') wyn = wyn and fun(pos,false);

  if(wyn) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

}


int main(){
  int cas; cin>>cas;
  while(cas--) solve();
  return 0;
}
