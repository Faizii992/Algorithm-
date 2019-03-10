#include<bits/stdc++.h>
#define white 0
#define grey 1
using namespace std;
vector < int > color;
vector <int> parent;
vector < int > dist;
int node,edge;
vector < pair < int, int > > adj[100];
set < pair< int, int > > q;
int cost=0;
void BFS(int src)
{
    color[src]=grey;
    q.insert(make_pair(0,src));
while(!q.empty())
{
    auto x=q.begin();
    int u=x->second;
q.erase(q.begin());
    color[u]=grey;

    for( auto c  : adj[u])
    {
int v=c.first;
int weight=c.second;
if(color[v]==white&&(weight+dist[u]<dist[v]))
{
    dist[v]=weight+dist[u];
    parent[v]=u;
    q.insert(make_pair(dist[v],v));
}
    }
}
    for(int i=0;i<node;i++)
{
    cout<<parent[i]<<"----"<<i<<" "<<dist[i]<<endl;
    cost+=dist[i];
}
cout<<"Cost is "<<cost<<endl;
}
int main()
{ int a,b,c;

    cout<<"Enter node and edge number :"<<endl;
    cin>>node>>edge;
int source=0;
for(int i=0;i<node;i++)
{ adj[i].clear();

}
    cout<<"Enter two connected vertices and cost : "<<endl;
    for(int i=0;i<edge;i++)
    {  cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));

    }
    dist.assign(node,INT_MAX);
    parent.assign(node,-1);
    color.assign(node,white);
dist[source]=0;
parent[source]=0;
cout<<"The connected vertices on application of Dijkstra are: "<<endl;
BFS(source);
}
