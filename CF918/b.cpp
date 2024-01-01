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
    vector<bool> v(3,false);
    for(int i=0;i<3;i++){
        char a,b,c; cin>>a>>b>>c;
        if(a=='?' or b=='?' or c=='?'){
            if(a!='?') v[a-'A']=true;
            if(b!='?') v[b-'A']=true;
            if(c!='?') v[c-'A']=true;
        }
    }
    for(int i=0;i<3;i++){
        if(v[i]==false) cout<<char('A'+i)<<endl;
    }
}


int main(){
    int casos; cin>>casos;
    while(casos--) solve();
    return 0;
}
