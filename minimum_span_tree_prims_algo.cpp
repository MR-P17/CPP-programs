
#include<bits/stdc++.h>
using namespace std;
#define int_max 7000
class graph
{
   int V;
   vector< pair<int,int> > *adj;
   public:
   graph (int v)
   {
      V=v;
      adj=new vector< pair<int,int> >[v];
   }
   void add_edge(int x,int y,int w)
   {
     adj[x].push_back(make_pair(y,w));
     adj[y].push_back(make_pair(x,w));
   }
   int find_min(vector<bool> &visited,vector<int> &weight)
   {
       int m=int_max;
       for(int i=0;i<V;i++)
       if(visited[i]==false)
       {
           m=i;break;
       }
       for(int i=0;i<V;i++)
       {
          if(visited[i]==false && weight[i]<weight[m])
          {
              m=i;
          }
       }
       return m;
   }
   void prims()
   {
     vector<int>pi(V,-1);
     vector<bool>visited(V,false);
     vector<int> weight(V,int_max);
     //for(int i=0;i<V;i++)
     //pi[i]=i;

     pi[0]=-1;
     weight[0]=0;
     queue<int> q;
     q.push(0);

     while(!q.empty())
     {
         int u=q.front();
         q.pop();
         for(int i=0;i<adj[u].size();i++)
         {
             int v=adj[u][i].first;
             int wt=adj[u][i].second;
             if(visited[v]==false && wt<weight[v])
             {
                 pi[v]=u;
                 weight[v]=wt;
             }
         }
         visited[u]=true;
         int m=find_min(visited,weight);

         if(m!=int_max)
         {
             q.push(m);
         }
     }
     int s=0;
    for(int i=0;i<V;i++){
    cout<<i<<" "<<pi[i]<<" "<<weight[i]<<endl;
    s+=weight[i];}

    cout<<s<<endl;

   }
};
int main()
{
    int v,e;cin>>v>>e;
    graph g(v);
    for(int i=0;i<e;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        g.add_edge(x,y,w);
    }
    g.prims();

    return 0;
}