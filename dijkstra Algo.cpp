#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int,int>>> &graph,int u,int v,int w){
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
}

vector<int> dijkstra(vector<vector<pair<int,int>>> &graph,int n,int s){
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(s,0));
        dist[s]=0;
        while(!pq.empty()){
            int u = pq.top().first;
            pq.pop();
            for(int i=0;i<graph[u].size();i++){
                int v = graph[u][i].first;
                int w = graph[u][i].second;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    pq.push(make_pair(v,dist[v]));
                }
            }
        }
        return dist;
}

int main(){
	cout<<"enter no of nodes: ";
	int n;
	cin>>n;
	vector<vector<pair<int,int>>> graph(n);
	cout<<"enter no of edges: ";
	int e;
	cin>>e;
	for(int i=0;i<e;i++){
		int a,b,w;
		cin>>a>>b>>w;
		addEdge(graph,a,b,w);
	}
	int s;
	cout<<"enter source: ";
	cin>>s;
	vector<int> ans = dijkstra(graph,n,s);
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
}
