// Creating Graph using vector of array
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adjList[], int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);

}

void printGraph(vector <int> adjList[], int V){
    for(int i=0; i<V; i++){
        cout<<"Adjacency List of vertex "<<i<<":\n"<<i;
        for(auto v:adjList[i]){
            cout<<"->"<<v;
        }
        cout<<endl;
    }
}

int main(){
    int V;
    cout<<"Enter no. of Edge:\n";
    cin>>V;
    vector <int> adj[V];
    int u,v;
    cout<<"Enter nodes/vertices connected with every edge\n";
    for(int i=0; i<V; i++){
        cin>>u>>v;
        addEdge(adj, u, v);
    }
    printGraph(adj, V);
    return 0;
}

// some random comment