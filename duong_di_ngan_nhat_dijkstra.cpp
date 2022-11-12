#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, start;
    cin >> n >> start;
    int a[n+5][n+5]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    int d[n+5], b[n+5], truoc[n+5];
    for(int i=1;i<=n;i++){
        d[i]=INT_MAX;
        b[i]=0;
        truoc[i]=start;
    }
    d[start]=0;
    truoc[start]=0;
    int nV=n;
    while(nV>0){
        int mind=INT_MAX,u=-1;
        for(int i=1;i<=n;i++){
            if(b[i]==0 && d[i]<mind){
                mind=d[i];
                u=i;
            }
        }
        nV--;
        if(u!=-1){
            b[u]=1;
            for(int v=1;v<=n;v++){
                if(b[v]==0 && a[u][v]!=0 && d[u]+a[u][v]<d[v]){
                    d[v]=d[u]+a[u][v];
                    truoc[v]=u;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"K/c "<<start<<"-> "<<i<<" = ";
        if(d[i]==INT_MAX){
            cout<<"INF; "<<endl;
            continue;
        }
        cout<<d[i]<<"; ";
        if(i!=start){
            int tmp=i;
            while(tmp!=start){
                cout<<tmp<<"<- ";
                tmp=truoc[tmp];
            }
        }
        else cout<<start<<" <- ";
        cout<<start<<endl;
    }
    return 0;
}
