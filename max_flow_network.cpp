
#include<bits/stdc++.h>
using namespace std;
# define int_max 7000
bool bfs(int **rgraph,int s,int t,vector<int> &pi,int v)
{
   vector<bool>visited(v,false);
   queue<int> q;
   q.push(s);
   visited[s]=true;
   pi[s]=-1;
   while(!q.empty())
   {
       int z,u=q.front();q.pop();
       for(z=0;z<v;z++)
       {
           if(visited[z]==false && rgraph[u][z]>0)
           {
               q.push(z);
               pi[z]=u;
               visited[z]=true;
           }
       }
   }
   return (visited[t]==true);
}
void max_flow(int **graph,int s,int t,int v)
{
   int **rgraph=new int *[v];
   for(int i=0;i<v;i++)
   rgraph[i]=new int[v];

    for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
    rgraph[i][j]=graph[i][j];

    vector<int> pi(v,-1);
    int m_flow=0;
    while(bfs(rgraph,s,t,pi,v))
    {
        int bn_cap=int_max;
        for(int v=t;v!=s;v=pi[v])
        {
            int u=pi[v];
            bn_cap=min(bn_cap,rgraph[u][v]);
        }
        for(int v=t;v!=s;v=pi[v])
        {
            int u=pi[v];
            rgraph[u][v]-=bn_cap;
            rgraph[v][u]+=bn_cap;
        }
        m_flow=m_flow+bn_cap;
    }
    cout<<m_flow;
}
int main()
{
    int v,e;cin>>v>>e;
    int **graph=new int *[v];
    for(int i=0;i<v;i++)
    graph[i]=new int[v];

    for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
    graph[i][j]=0;
    /*for(int i=0;i<v;i++){
    for(int j=0;j<v;j++)
    cout<<graph[i][j]<<" ";
    cout<<endl;} */
    for(int i=0;i<e;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        graph[x][y]=w;
    }
    int s,t;cin>>s>>t;
    max_flow(graph,s,t,v);
    return 0;
}