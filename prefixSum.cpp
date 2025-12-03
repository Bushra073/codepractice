#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n), pre(n+1,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i-1];

    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r; // 1-based
        cout<<pre[r]-pre[l-1]<<endl;
    }
}
