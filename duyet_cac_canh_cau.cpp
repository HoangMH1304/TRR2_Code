#include<iostream>
#define MAX 100
using namespace std;

class graph{
    int n,A[MAX][MAX],chuaxet[MAX];
    public:
    void readdata();
    void reinit();
    void dfs(int u);
    void bridge();
};

void graph::readdata(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>A[i][j];
    }
}

void graph::reinit(){
    for(int i=1;i<=n;i++) chuaxet[i]=1;
}

void graph::dfs(int u){
    chuaxet[u]=0;
    for(int v=1;v<=n;v++){
        if(A[u][v]==1 && chuaxet[v]==1){
            dfs(v);
        }
    }
}

void graph::bridge(){
    reinit();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(A[i][j]==1 && j>i){
                A[i][j]=A[j][i]=0;
                dfs(1);
                for(int k=1;k<=n;k++){
                    if(chuaxet[k]==1){
                        cout<<i<<" "<<j<<endl;
                        break;
                    }
                }
                A[i][j]=A[j][i]=1;
                reinit();
            }
        }
    }
}

int main(){
    graph g;
    g.readdata(); g.bridge();
    return 0;
}
