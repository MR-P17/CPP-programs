//maximize job profit if a array with deadline & another array with profit is given
#include<bits/stdc++.h>
using namespace std;

struct job
{
  char id;
  int dead,profit;
};
bool cmp(struct job a,struct job b)
{
	int p1=a.profit;
	int p2=b.profit;
	return p1>p2;
}
void job_seq(job arr[],int n,vector<bool> &filled)
{
	sort(arr,arr+n,cmp);
	//cout<<endl<<endl;
	//for(int i=0;i<n;i++)
	//cout<<arr[i].profit<<"  "<<arr[i].dead<<endl;
     int prof=0,count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,arr[i].dead)-1;j>=0;j--)
		{
           if(filled[j]==false)
           {
           	filled[j]=true;
           //v.push_back(arr[i].id);
           	count++;
           	prof+=arr[i].profit;
           	break;
           }
		}
	}
	cout<<count<<" "<<prof<<endl;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
	int n;cin>>n;
   job arr[n];
   for(int i=0;i<n;i++)
   cin>>arr[i].id>>arr[i].dead>>arr[i].profit;
   //vector<char>v;
   vector<bool> filled(n,false);
   job_seq(arr,n,filled);
    }
   return 0;	
}
