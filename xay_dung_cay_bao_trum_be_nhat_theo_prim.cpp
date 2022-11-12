#include<bits/stdc++.h>
using namespace std;

struct canh{
    int dx,dy;
};

int n, u, used[100], a[100][100], dh;

void readdata(){
    cin>>n>>u;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        used[i]=0;
    }
}

bool ktra(){
    for(int i=1;i<=n;i++){
        if(used[i]==0) return true;
    }
    return false;
}

void prim(){
    canh kq[100];
    used[u]=1;
    int dem=0;
    while(ktra()){
        int min=INT_MAX, tmp1, tmp2;
        for(int j=1;j<=n;j++){
            if(used[j]==1){
                for(int i=1;i<=n;i++){
                    if(used[i]==0 && a[j][i]<min && a[j][i]!=0){
                        min=a[j][i];
                        tmp1=j; tmp2=i;
                    }
                }
            }
        }
        dh+=min;
        used[tmp2]=1;
        dem++;
        kq[dem].dx=tmp1;
        kq[dem].dy=tmp2;
    }
    cout<<"dH = "<<dh<<endl;
    for(int j=1;j<=dem;j++){
        if(kq[j].dx<kq[j].dy) cout<<kq[j].dx<<' '<<kq[j].dy<<endl;
        else cout<<kq[j].dy<<' '<<kq[j].dx<<endl;
    }
}

int main(){
    readdata();
    dh=0;
    prim();
    
}

