#include<iostream>
#define MAX 100
#define INF 1000000
using namespace std;

//mai huy hoang
class   graph{
    int     n, s, C[MAX][MAX], d[MAX], truoc[MAX];
    public:
    void    readdata();
    int     gets(){ return s;   }
    void    bellmanford(int s);
};
void    graph::readdata(){
    cin>>n>>s;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>C[i][j];
            if(C[i][j]==0)  C[i][j]=INF;
        }
}
void    graph::bellmanford(int s){
    //Khoi tao:
    for(int v=1; v<=n; v++){
        d[v]=C[s][v];
        truoc[v]=s;
    }
    d[s]=0;
    //Lap
    for(int k=1; k<=n-2; k++)
        for(int v=1; v<=n; v++)
            if(v!=s)
                for(int u=1; u<=n; u++)
                    if((d[v]>d[u]+C[u][v])&&(d[u]!=INF)&&(C[u][v]!=INF)){
                        d[v]=d[u]+C[u][v];
                        truoc[v]=u;
                    }
    //In kq
    for(int v=1; v<=n; v++)
        if(d[v]==INF)   cout<<"K/c "<<s<<" -> "<<v<<" = INF;"<<endl;
        else{
            cout<<"K/c "<<s<<" -> "<<v<<" = "<<d[v]<<"; ";
            cout<<v<< " <- ";
            int u=truoc[v];
            while(u!=s){
                cout<<u<<" <- ";    u=truoc[u];
            }
            cout<<s<<endl;
        }
}
int main(){
    graph   g;  g.readdata();   g.bellmanford(g.gets());   //cout<<"\nOK";
}
