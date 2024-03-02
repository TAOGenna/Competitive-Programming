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


int main(){
   int n,q; cin>>n>>q;
  // trace(n,q);
   string s; cin>>s;
   int pos=0,origin=0;
   while(q--){
       int tipo,npos; cin>>tipo>>npos;
      
       if(tipo==1){
           pos=(pos+npos)%sz(s);
           if(pos%sz(s)) origin=(sz(s)-1)-(pos-1);
           else origin=0;
       //    trace(origin);
       }else{
           int foo=(origin+(npos-1))%sz(s);
     //      trace(foo,origin,npos);
           cout<<s[foo]<<endl;
       }
       
   }
    return 0;
}
