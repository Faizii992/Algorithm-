#include<bits/stdc++.h>
#define true 1
#define false 0
using namespace std;
vector <int > visited;
vector <int > parent;
vector < int > key;
int src=0;
list < pair < int, int > > ::iterator i;
list< pair < int, int > > adj[100];
typedef pair < int, int > PII;
priority_queue< PII ,vector < PII > ,greater <PII > > que;
int node,edge;
int minimum_weight;
map<string,bool>M;
int total_weight;
int unused_weight;
void creategraph()
{
    int a,b,c;
    for(int i=0;i<edge;i++)
    { cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
         adj[b].push_back(make_pair(a,c));
         string U=to_string(a);
        string V=to_string(b);
        string U1=U+"---"+V;
        string U2=V+"---"+U;
        M[U1]=true;
        M[U2]=true;
        total_weight+=c;
    }
}
int main()
{
    cout<<"Enter node and edge no : "<<endl;
    cin>>node>>edge;
    cout<<"Enter two vertices and cost : "<<endl;
    creategraph();
    key.assign(node,INT_MAX);
    parent.assign(node,-1);
    visited.assign(node,false);
    que.push(make_pair(0,src));
    key[src]=0;
    parent[src]=0;
    while(!que.empty())
    {
        int u=que.top().second;
        que.pop();
        visited[u]=true;
        for(i = adj[u].begin();i!=adj[u].end();i++)
        {
            int v=(*i).first;
            int weight=(*i).second;
            if(visited[v]==false&&key[v]>weight)
            {
                key[v]=weight;
                parent[v]=u;
                que.push(make_pair(key[v],v));
            }
        }
    }
    for(int i=1;i<node;i++)
    {
        cout<<parent[i]<<"---"<<i<<" "<<key[i]<<endl;
    }
 for (int i = 1; i < node; ++i)
       {
                string U=to_string(parent[i]);
                string V=to_string(i);
                string U1=U+"---"+V;
                string U2=V+"---"+U;
                M[U1]=false;
                M[U2]=false;
                printf("%d - %d---%d\n", parent[i], i,key[i]);
                minimum_weight+=key[i];
       }
        cout<<"minimum weight: "<<minimum_weight<<endl;
        unused_weight=total_weight-minimum_weight;
        cout<<"unused weight: "<<unused_weight<<endl;
    for(auto it1: M)
    {
         string str=it1.first;
        reverse(str.begin(),str.end());
        if(M[str]==true)M[str]=false;

        if(it1.second==true)
        {
            cout<<it1.first<<endl;
        }
    }
}
