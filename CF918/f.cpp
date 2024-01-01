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

const int N=4e5+100;
int st[N];
vector<pair<int,int> > v;

int query(int a,int b){
    a+=sz(v),b+=sz(v);
    int sum=0;
    while(a<=b){
        if(a%2==1) sum+=st[a++];
        if(b%2==0) sum+=st[b--];
        a/=2,b/=2;
    }
    return sum;
}
void update(int ind){
    ind+=sz(v);
   // trace(ind);
    st[ind]=1;
   // trace(st[ind]);
    for(ind/=2;ind>=1;ind/=2){
        st[ind]=st[ind*2]+st[ind*2+1];
     //   trace(ind,st[ind]);
    }
   // line;
}

void solve(void){
    int n; cin>>n;
   
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        v.pb({a,i});
        v.pb({b,i});
        //trace(i,a,b);
        //line;
    }
    sort(all(v));
    int wyn=0;
    set<int> s;
    map<int,int> m;
    for(int i=0;i<sz(v);i++){
       // trace(sz(s));
        if(s.count(v[i].ss)){
          //  wis;
            wyn+=query(m[v[i].ss]+1,sz(v)+1);
     //      trace(m[v[i].ss]+1);
            update(m[v[i].ss]+1);
        }else{
            m[v[i].ss]=i;
            s.insert(v[i].ss);
        }
       // for(int j=1;j<=10;j++){
         //   cout<<"node "<<j<<" -> "<<st[j]<<endl;
       // }line;
    }
    v.clear();
    for(int i=1;i<=2*sz(v);i++) st[i]=0;
    cout<<wyn<<endl;
}

   



int main(){
    fastio
    int cas; cin>>cas; 
    while(cas--) solve();
    return 0;
}
