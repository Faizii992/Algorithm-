#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;
static vector<int> visited;
 vector<vector<int> > adj;
static queue<int> q;
static int edge,node;
void creategraph(int edge)
{ int x;
int y;

for(int i=0;i<edge;i++)
{   cin>>x>>y;
    adj[x].push_back(y);
     adj[y].push_back(x);
}

}
void BFS(int s)
{
    visited[s]=1;
    q.push(s);
    cout<<s<<endl;
    while(!q.empty())
    { int f=q.front();
    q.pop();

for(int i=0;i<adj[f].size();i++)
{
    if(visited[adj[f][i]]==false)
    {
        visited[adj[f][i]]=true;
        cout<<adj[f][i]<<" "<<endl;
        q.push(adj[f][i]);
    }
}

    }


}
int main()
{
int startingnode;
   printf("Enter edge and node:");
   cin>>edge>>node;
   adj.assign(node,vector<int>());
visited.assign(node,false);
   printf("Enter starting node:");
   cin>>startingnode;
   cout<<"Enter the adjacent two matrixes:"<<endl;
creategraph(edge);

cout<<"The path of traversal is:"<<endl;
   BFS(startingnode);


}
