#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,f[1005],a[1005][1005];

void dfs(int u){
    f[u]=1;
    for(int i=1;i<=n;i++){
        if(!f[i] && a[u][i]){
            f[i]=1;
            dfs(i);
        }
    }
}

void xuly(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    int dem=0;
    for(int i=1;i<=n;i++){
        if(!f[i]){
            dem++;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        f[i]=1;
        int res=0;
        for(int i=1;i<=n;i++){
            if(!f[i]){
                res++; dfs(i);
            }
        }
        if(res>dem) cout<<i<<" ";
    }
}

int main(){
    xuly();
    return 0;
}
