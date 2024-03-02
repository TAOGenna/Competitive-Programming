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

map<lli,lli> m;

int main(){
    lli n; cin>>n;
    for(lli i=0;i<n;i++){
        lli num; cin>>num;
        m[num]++;
    }
    lli wyn=0;
    for(lli i=-200;i<=200;i++){
        for(lli j=-200;j<=200;j++){
            wyn+=m[i]*m[j]*(i-j)*(i-j);
        }
    }
    wyn/=2;
    cout<<wyn<<endl;
    return 0;
}

