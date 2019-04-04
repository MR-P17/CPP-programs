#include<bits/stdc++.h>
using namespace std;
#define int_max 9999
int s[100];
int f[100];
int wt[100];
int ans;
int dfs(int u )
{
	if(s[u]==0)
		return u;
	if(wt[u]<ans)
		ans=wt[u];
	return dfs(s[u]);
}
void water_con(int **arr,int n,int p)
{
	int i=0;
	while(i<p)
	{
		int x=arr[i][0],y=arr[i][1],z=arr[i][2];
		s[x]=y;
		f[y]=x;
		wt[x]=z;
		i++;
	}
	vector<int> a;
	vector<int> b;
	vector<int> c;

	for(int j=1;j<=n;j++)
	{
		if(f[j]==0 && s[j])
		{
			ans=int_max;
			int w=dfs(j);

            a.push_back(j);
            b.push_back(w);
            c.push_back(ans);
		}
	}
	cout<<a.size()<<endl;
	for(int j=0;j<a.size();j++)
		cout<<a[j]<<" "<<b[j]<<" "<<c[j]<<endl;

}
int main()
{
   int n,p;cin>>n>>p;
   int **arr=new int *[p];
   for(int i=0;i<p;i++)
   	arr[i]=new int[3];

   for(int i=0;i<p;i++)
   	for(int j=0;j<3;j++)
   	cin>>arr[i][j];
   	
   	memset(s,0,sizeof(s));
    memset(f,0,sizeof(f));
    memset(wt,0,sizeof(wt));


    water_con(arr,n,p);
	return 0;
} 