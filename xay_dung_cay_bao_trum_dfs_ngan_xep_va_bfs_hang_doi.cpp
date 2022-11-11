#include <bits/stdc++.h>
using namespace std;

int n, start, a[100][100];
bool chuaxet[100];

void dfs(int u) {
    cout << "DFS tree" << endl;
    memset(chuaxet, 0, sizeof(chuaxet));
    stack<int> st;
    st.push(u);
    chuaxet[u] = 1;
    while(st.size()) {
        int s = st.top();
        st.pop();
        for(int i=1; i<=n; i++) {
            if(chuaxet[i] == 0 && a[s][i] == 1) {
                cout << min(s, i) << " " << max(s, i) << endl;
                chuaxet[i] = 1;
                st.push(s);
                st.push(i);
                break;
            }
        }
    }
}

void bfs(int u) {
    cout << "BFS tree" << endl;
    memset(chuaxet, 0, sizeof(chuaxet));
    queue<int> Q;
    Q.push(u);
    chuaxet[u] = 1;
    while(Q.size()) {
        int s = Q.front();
        Q.pop();
        for(int i=1; i<=n; i++) {
            if(chuaxet[i] == 0 && a[s][i] == 1) {
                cout << min(s, i) << " " << max(s, i) << endl;
                chuaxet[i] = 1;
                Q.push(i);
            }
        }
    }
}

void solve() {
    cin >> n >> start;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> a[i][j];
    
    dfs(start);
    bfs(start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    for(int tc=1; tc<=t; tc++) {
        solve();
    }
}
