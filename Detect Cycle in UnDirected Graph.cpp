#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &graph,int u,int v){
	graph[u].push_back(v);
    graph[v].push_back(u);
}

bool isCyclic_Util(vector<vector<int>> graph,vector<bool> &visited,vector<int> &parent,int v){
	visited[v]=true;
	for(auto u:graph[v]){
	    if(!visited[u]){
	    	parent[u]=v;
	        if(isCyclic_Util(graph,visited,parent,u))return true;
	    }
	    else if(parent[v]!=u)return true;
	}
	return false;
}
bool isCyclic(vector<vector<int>> graph,int V) 
{
	vector<bool> visited(V,false);
	vector<int> parent(V,-1);
	for(int i=0;i<V;i++){
		if(!visited[i]) if(isCyclic_Util(graph,visited,parent,i))return true;
    }
	return false;
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
	if(isCyclic(graph,n)){
		cout<<"cycle is detected";
	}
	else{
		cout<<"cycle is not detected";
	}
}
