#include <bits/stdc++.h> 
using namespace std;
int main(){
    int n; cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int num; cin>>num;
        if(num>10) sum+=num-10;
    }
    cout<<sum<<endl;
    return 0;
}
