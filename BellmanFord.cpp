#include<bits/stdc++.h>
#define white 0
#define grey 1
#define V 10
using namespace std;
vector < int > color;
vector <int> parent;
vector < int > dist;
int a=0;
int node,edge;
pair < int ,pair< int, int > > adj[V];
int cost=0;
int main()
{ int a,b,c;

    cout<<"Enter node and edge number :"<<endl;
    cin>>node>>edge;
int source=0;

    cout<<"Enter two connected vertices and cost : "<<endl;
    for(int i=0;i<edge;i++)
    {   cin>>a>>b>>c;
    adj[i]=make_pair(c,make_pair(a,b));
    }
    dist.assign(node,INT_MAX);
    parent.assign(node,0);
    dist[source]=0;
parent[source]=-1;
for(int j=1;j<node;++j)
{
for(int i=0;i<edge;++i)
{
int u=adj[i].second.first;
   int v=adj[i].second.second;
int weight=adj[i].first;
if(dist[u]!=INT_MAX&&weight+dist[u]<dist[v])
{
    dist[v]=weight+dist[u];
    parent[v]=u;
    //q.insert(make_pair(dist[v],v));
}
    }
}
for (int i = 0; i < edge; ++i) {
         int u=adj[i].second.first;
   int v=adj[i].second.second;


int weight=adj[i].first;
if(dist[u]!=INT_MAX&&weight+dist[u]<dist[v])
{a=1;

}


puts("");
}

if(a==1)
{
    cout<<"Negative Cycle exists "<<endl;
}
else
{
    cout<<"Doesnt exist "<<endl;
}
    for(int i=0;i<node;i++)
{
    cout<<parent[i]<<"----"<<i<<" "<<dist[i]<<endl;
}
}
