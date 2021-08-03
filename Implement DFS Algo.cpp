#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &graph,int u,int v){
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void dfs(vector<vector<int>> &graph,int s,int n){
	vector<bool> visited(n,false);
	stack<int> st;
	st.push(s);
	visited[s]=true;
	while(!st.empty()){
		int v = st.top();
		cout<<v<<" ";
		st.pop();
		for(auto i: graph[v]){
			if(!visited[i]){
				visited[i]=true;
				st.push(i);
			}
		}
	}
}
 
void dfs_recursive(vector<vector<int>> &graph,vector<bool> &visited,int s){
	visited[s]=true;
	cout<<s<<" ";
	for(auto i:graph[s]){
		if(!visited[i]){
			dfs_recursive(graph,visited,i);
		}
	}
} 
 
void dfs_util(vector<vector<int>> &graph,int n){
	vector<bool> visited(n,false);
	dfs_recursive(graph,visited,0);
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
	cout<<"iterative : ";
	dfs(graph,0,n);
	cout<<endl;
	cout<<"recursive : ";
	dfs_util(graph,n);
}
