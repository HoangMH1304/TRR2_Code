#include<iostream>
using namespace std;
#define MAX 100
class graph{
    int n, A[MAX][MAX],s,chuaxet[MAX],X[MAX];
    public:
    void readdata();
    void init(){ for(int i=1;i<=n;i++) chuaxet[i]=1; }
    int gets(){ return s; }
    void setchuaxet(int k){ chuaxet[k]=0; }
    void hmt(int k);
    void setX1(){ X[1]=s; }
};

void graph::readdata(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>A[i][j];
    }
}

void graph::hmt(int k){
    for(int y=1;y<=n;y++){
        if(A[X[k-1]][y] == 1){
            if(k==n+1 && y==X[1]){
                for(int i=1;i<=n;i++) cout<<X[i]<<" ";
                cout<<X[1]<<endl;
            }else if(chuaxet[y]==1){
                X[k]=y; chuaxet[y]=0; hmt(k+1); chuaxet[y]=1;
            }
        }
    }
}

int main(){
    graph g;
    g.readdata(); g.init(); g.setX1(); g.setchuaxet(g.gets()); g.hmt(2); 
    return 0;
}
