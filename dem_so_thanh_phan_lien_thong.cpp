#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//mai huy hoang
int n, A[100][100];
vector<int> adj[1001];
int visited[1001];

void inp(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(A[i][j]){
				adj[i].push_back(j);
			}
		}
	}
	memset(visited, 0, sizeof(visited));
}

void dfs(int u){
	visited[u] = 1;
	for(int it : adj[u]){
		if(!visited[it]){
			dfs(it);
		}
	}
}

void solve(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}

int main(){
	inp();
	solve();
	return 0;
}
