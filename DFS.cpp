#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<stdlib.h>

using namespace std;

 vector <vector<int> > adj;
 vector<int> visited;
 queue<int> q;
 int node,edge;
 int WHITE=1;
 int GREY=2;
 int BLACK=3;
void creategraph(int edge)
{ int a,b;


    for(int i=0;i<edge;i++)
    {   cin>>a;
    cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}
/*void DFS(int startingNode)
{
    visited[startingNode] = true;
    cout << startingNode << " ";
    for(int i = 0; i < adj[startingNode].size(); i++)
    {
        if(visited[adj[startingNode][i]] == false)
        {
            DFS(adj[startingNode][i]);
        }
    }
}
*/
void DFS(int startingnode)
{  visited[startingnode]=GREY;
cout<<startingnode<<endl;

for(int i=0;i<adj[startingnode].size();i++)
{
 if(visited[adj[startingnode][i]]==WHITE)
 {


    //visited[[adj][i]]='GREY';
    DFS(adj[startingnode][i]);
 }

}
visited[startingnode]=BLACK;

}

 int main()
 { int startingnode;
     printf("Enter node and edge:");
     cin>>node>>edge;
adj.assign(node,vector<int>());
visited.assign(node,WHITE);

cout<<"Enter the adjacent nodes:"<<endl;
     creategraph(edge);


 printf("Enter starting node:");
     cin>>startingnode;
     printf("The path of traversal is:");
     DFS(startingnode);

 }

