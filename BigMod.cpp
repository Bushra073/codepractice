#include <bits/stdc++.h>
using namespace std;
long long bigMod(long long a, long long b, long long m){
    long long res=1; a%=m;
    while(b){
        if(b&1) res=(res*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return res;
}
int main(){
    long long a,b,m; cin>>a>>b>>m;
    cout<<bigMod(a,b,m);
}
