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

lli fun(lli num,:){



int main(){
    lli n; cin>>n;
    vector<lli> v;
    while(n>0){
        v.pb(n%10);
        n/=10;
    }
    lli sum=0;
    for(lli i=1;i<sz(v);i++){
        if(i%2==0){
            lli can=i/2;
            lli temp=1;
            for(lli j=1;j<=can;j++) temp*=9;
            sum+=temp;
        }
    }
    if(sz(v)%2==0){
        lli ope=1;
        for(lli i=1;i<=(sz(v)/2)-1;i++) ope*=9;
        for(lli i=1;i<v[0];i++){
            sum+=ope;
        }
        vector<lli> final;
        for(lli i=1,j=sz(v)/2;i<sz(v)/2;i++,j++){
            final.pb(min(v[i],v[j]));
        }
        lli temp=1;
        for(auto x:final) temp*=x;
    
        sum+=temp;
    }
    cout<<sum<<endl;
    return 0;
}


                
