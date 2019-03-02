#include<bits/stdc++.h>
#define false 0
#define true 1
#define white 0
#define grey 1

using namespace std;
int mark=-1;
int node,edge;
int color[100];
int visited[100];
stack < int > stck;
vector <int > adj[100];
vector <int > reverseadj[100];
vector < int > scc[100];

void DFS(int source)
{
    color[source]=grey;

    for(int i=0;i<adj[source].size();i++)
    {

        if(color[adj[source][i]]==white)
        {


        DFS(adj[source][i]);
        }
    }

    stck.push(source);

}
void DFS2visit(int source)
{
    scc[mark].push_back(source);
    visited[source]=true;

    for(int i=0;i<reverseadj[source].size();i++)
    {
        if(visited[reverseadj[source][i]]==false)
        {


        DFS2visit(reverseadj[source][i]);
    }
    }

    //stck.push(source);

}
int main()
{
    cout<<"Enter node and edge : "<<endl;
    cin>>node>>edge;

    for(int i=0;i<edge;i++)
    {
        adj[i].clear();
        color[i]=white;
        visited[i]=false;
        reverseadj[i].clear();
    }
    cout<<"Enter two vertices: "<<endl;
    for(int i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        reverseadj[b].push_back(a);
    }

    for(int i=0;i<node;i++)
    {
        if(color[i]==white)
        {
            DFS(i);
        }
    }

    while(!stck.empty())
    {
        int u=stck.top();
        stck.pop();

        if(visited[u]==false)
        {
            mark++;
            DFS2visit(u);
        }
    }
    cout<<"no of connected comps : "<<mark+1;
    puts("");

    for(int i=0;i<=mark;i++)
    { cout<<"Elements in comp no :"<<i+1<<endl;
        for(int j=0;j<scc[i].size();j++)
        { cout<<scc[i][j]<<" "<<endl;

        }
        puts("");
    }
}
