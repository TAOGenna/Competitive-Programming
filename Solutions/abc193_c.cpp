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

lli binpow(lli a, lli b) {
    if (b == 0) return 1;
    lli res = binpow(a, b / 2);
    if (b % 2) return res * res * a;
    else return res * res;
}

set<lli> s;

int main(){
    lli n; cin>>n;
    lli cnt=0;
    for(lli p=34;p>=2;p--){
        for(lli x=2;x<=1e5;x++){
            lli res=binpow(x,p);
            if(res>n) break;
            s.insert(res);
        }
    }
    cout<<n-sz(s)<<endl;
    return 0;
}
