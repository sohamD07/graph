#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &graph,int u,int v){
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void bfs(vector<vector<int>> &graph,int s,int n){
	vector<bool> visited(n,false);
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int v = q.front();
		cout<<v<<" ";
		q.pop();
		for(auto i: graph[v]){
			if(!visited[i]){
				visited[i]=true;
				q.push(i);
			}
		}
	}
}
int main(){
	cout<<"enter no of nodes: ";
	int n;
	cin>>n;
	vector<vector<int>> graph(n);
	cout<<"enter no of edges: ";
	int e;
	cin>>e;
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		addEdge(graph,a,b);
	}
	bfs(graph,0,n);
}
