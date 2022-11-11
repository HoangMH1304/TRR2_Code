#include<iostream>
#define MAX 100
using namespace std;

typedef struct{
    int dau, cuoi, c;
}Edge;

class graph{
    int n, A[MAX][MAX], ne, AT[MAX][MAX], neT, dH, chuaxet[MAX];
    Edge G[MAX], T[MAX];
    public:
    void readdata();
    void init(){ for(int i=1;i<=n;i++) chuaxet[i]=1; }
    void dfsT(int u); //duyet tren cay voi ma tran ke AT
    void kruskal();
    void bubblesort();
};

void graph::readdata(){
    cin>>n;
    ne=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>A[i][j];
            if(A[i][j]!=0 && i<j){
                ne++;
                G[ne].dau=i;
                G[ne].cuoi=j;
                G[ne].c=A[i][j];
            }
        }
    }
}

void graph::dfsT(int u){ //duyet tren cay voi ma tran ke AT
    chuaxet[u]=0;
    for(int v=1;v<=n;v++){
        if(AT[u][v]==1 && chuaxet[v]==1) dfsT(v);
    }
}

void graph::bubblesort(){
    for(int i=ne;i>=1;i--){
        for(int j=1;j<i;j++){
            if(G[j].c>G[j+1].c) swap(G[j],G[j+1]);
        }
    }
}

void graph::kruskal(){
    //1. khoi tao: cay rong
    neT=0;
    dH=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) AT[i][j]=0;
    }
    //2. sap xep danh sach canh cua do thi theo trong so tang dan
    bubblesort();
    //3. buoc lap
    for(int e=1;e<=ne;e++){ //xet cach cua do thi (theo trong so tang dan)
        init(); dfsT(G[e].dau);
        if(chuaxet[G[e].cuoi]==1){ //dau va cuoi cua canh e khong thuoc cung cay con -> khong tao thanh chu trinh
            neT++; 
            T[neT].dau=G[e].dau;
            T[neT].cuoi=G[e].cuoi;
            T[neT].c=G[e].c;
            dH+=G[e].c;
            AT[G[e].dau][G[e].cuoi]=AT[G[e].cuoi][G[e].dau]=1;
        }
    }
    //4. Tra ve ket qua
    if(neT!=n-1) cout<<"Do thi khong lien thong";
    else{
        cout<<"dH = "<<dH<<endl;
        for(int i=1;i<=neT;i++) cout<<T[i].dau<<"  "<<T[i].cuoi<<endl;
    }
}

int main(){
    graph g;
    g.readdata();
    g.kruskal();
    //cout<<"OK"<<endl;
    return 0;
}
