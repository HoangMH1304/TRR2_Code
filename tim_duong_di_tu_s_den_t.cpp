#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class graph{
    public:
    int n,A[MAX][MAX], chuaxet[MAX], truoc[MAX],s,t;
    void readdata();
    void init();
    void dfs(int u);
    void bfs(int u);
    void pathreconstruct(int s,int t);
};

void graph::readdata(){
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>A[i][j];
    }
}

void graph::init(){
    for(int i=1;i<=n;i++){
        chuaxet[i]=1;
        truoc[i]=0;
    }
}

void graph::dfs(int u){
    stack<int> nganxep;
    nganxep.push(u);
    chuaxet[u]=0;
    while(!nganxep.empty()){
        int u=nganxep.top(); nganxep.pop();
        for(int v=1;v<=n;v++){
            if(A[u][v]==1 && chuaxet[v]==1){
                chuaxet[v]=0;
                nganxep.push(u);
                nganxep.push(v);
                truoc[v]=u;
                break;
            }
        }
    }
}

void graph::bfs(int u){
    queue<int> hangdoi;
    hangdoi.push(u);
    chuaxet[u]=0;
    while(!hangdoi.empty()){
        int u=hangdoi.front(); hangdoi.pop();
        for(int v=1;v<=n;v++){
            if(A[u][v]==1 && chuaxet[v]==1){
                chuaxet[v]=0;
                hangdoi.push(v);
                truoc[v]=u;
            }
        }
    }
}

void graph::pathreconstruct(int s,int t){
    if(truoc[t]==0) cout<<"no path";
    else{
        cout<<t<<" ";
        int u=truoc[t];
        while(u!=s){
            cout<<u<<" ";
            u=truoc[u];
        }
        cout<<s;
    }
}

int main(){
    graph g;
    g.readdata();
    g.init();
    g.dfs(g.s);
    if(g.truoc[g.t]!=0) cout<<"DFS path: ";
    g.pathreconstruct(g.s,g.t);
    g.init(); g.bfs(g.s);
    if(g.truoc[g.t]!=0){
        cout<<"\nBFS path: "; g.pathreconstruct(g.s,g.t);
    }
    //cout<<"\nOk";
    return 0;
}
