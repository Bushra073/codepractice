#include <bits/stdc++.h>
using namespace std;
vector<int> tree;

void build(vector<int>& a,int v,int tl,int tr){
    if(tl==tr) tree[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}

int sum(int v,int tl,int tr,int l,int r){
    if(l>r) return 0;
    if(l==tl && r==tr) return tree[v];
    int tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr) tree[v]=val;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm) update(v*2,tl,tm,pos,val);
        else update(v*2+1,tm+1,tr,pos,val);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}

int main(){
    int n; cin>>n; vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    tree.resize(4*n); build(a,1,0,n-1);

    int q; cin>>q;
    while(q--){
        int t; cin>>t;
        if(t==1){ int l,r; cin>>l>>r; cout<<sum(1,0,n-1,l,r)<<endl; }
        else{ int pos,val; cin>>pos>>val; update(1,0,n-1,pos,val); }
    }
}
