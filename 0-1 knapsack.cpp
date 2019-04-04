// 0-1 knapsack problem
#include<bits/stdc++.h>
using namespace std;
int knapsack(int *wt,int *value,int n,int w)
{
    int **dp=new int *[n];
    for(int i=0;i<n;i++)
    dp[i]=new int[w+1];

    for(int i=0;i<n;i++)
    dp[i][0]=0;
     
     for(int i=1;i<w+1;i++)
     {
         if(i<wt[0])
         dp[0][i]=0;
         else
         dp[0][i]=value[0];
     }
     for(int i=1;i<n;i++)
     {
         for(int j=1;j<w+1;j++)
         {
             if(j<wt[i])
             dp[i][j]=dp[i-1][j];
             else
             dp[i][j]=max(value[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
         }
     }
     cout<<dp[n-1][w]<<endl;
     cout<<endl;
}
int main()
{
    int n,w;cin>>n>>w;
    int *wt=new int[n];
    int *value=new int[n];

    for(int i=0;i<n;i++)
    cin>>value[i];

    for(int i=0;i<n;i++)
    cin>>wt[i];


    knapsack(wt,value,n,w);
    return 0;
}
