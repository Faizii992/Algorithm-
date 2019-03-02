#include<bits/stdc++.h>
#define true 1
#define false 0
using namespace std;
vector < int > visited;
vector <int> parent;
vector <int > key;
int node,edge;
typedef pair<int, int> PII;
list < pair <int ,int > >adj[100];
priority_queue< PII, vector<PII>, greater<PII> > que;
list < pair < int, int> > ::iterator i;
int cost=0;

void creategraph(int a,int b,int c)
{

    for(int i=0;i<edge;i++)
    {cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));

    }
}
int main()
{ int a,b,c;
    cout<<"Enter node and edge number :"<<endl;
    cin>>node>>edge;
int source=0;
    cout<<"Enter two connected vertices and cost : "<<endl;

    creategraph(a,b,c);
    visited.assign(node,false);
    parent.assign(node,-1);
key.assign(node,INT_MAX);

key[source]=0;
parent[source]=0;
que.push(make_pair(0,source));
while(!que.empty())
{
    int u=que.top().second;
    que.pop();

 visited[u]=true;

 for( i =adj[u].begin();i!=adj[u].end();++i)
 {
     int v=(*i).first;
     int weight=(*i).second;

     if(visited[v]==false&&weight<key[v])
     {
         key[v]=weight;
         parent[v]=u;
         que.push(make_pair(key[v],v));
     }


 }

}
cout<<"The connected vertices on application of Prim's are: "<<endl;
for(int i=1;i<node;i++)
{
    cout<<parent[i]<<"---"<<i<<" "<<key[i]<<endl;
    cost+=key[i];

}


cout<<"Cost is "<<cost<<endl;
}


