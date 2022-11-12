#include<iostream>
#include<stack>
#define MAX 100
using namespace std;

class graph{
    public:
    int n,A[MAX][MAX],s;
    void readdata();
    void init();
    void dfs();
    void euler(int u);
};

void graph::readdata(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>A[i][j];
    }
}

void graph::euler(int u){
    stack<int> nganxep,ce;
    nganxep.push(u);
    while(!nganxep.empty()){
        int s=nganxep.top(),empty=1;
        for(int t=1;t<=n;t++){
            if(A[s][t]==1){
                empty=0;
                nganxep.push(t);
                A[s][t]=A[t][s]=0;
                break;
            }
        }
        if(empty==1){
            nganxep.pop();
            ce.push(s);
        }
    }
    while(!ce.empty()){
        cout<<ce.top()<<" ";
        ce.pop();
    }
}

int main(){
    graph g;
    g.readdata();
    g.euler(g.s);
}
