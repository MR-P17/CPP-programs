#include<bits/stdc++.h>
using namespace std;
struct item
{
  int s,f;
};
bool cmp(struct item a,struct item b)
{
    int r1=a.f;
    int r2=b.f;
    return r1<r2;
}
void activity_sel(item arr[],int n)
{
	sort(arr,arr+n,cmp);
	//cout<<endl<<endl;
	//for(int i=0;i<n;i++)
	//	cout<<arr[i].f<<"  "<<arr[i].s<<endl; 

    int count=1;
    int last_f=arr[0].f;
    vector<int> idx;
    idx.push_back(0);
	for(int i=1;i<n;i++)
	{
       if(arr[i].s>last_f)
       {
       	count++;
        idx.push_back(i);
        last_f=arr[i].f;
       }
	}
	cout<<count<<endl;
	for(int i=0;i<idx.size();i++)
	{
		cout<<idx[i]<<": "<<arr[idx[i]].s<<"  "<<arr[idx[i]].f<<endl;
	}
}
int main()
{
	int t;cin>>t;
	while(t--){
	int n,s,f;cin>>n;
	int start[n];
	for(int i=0;i<n;i++)
		cin>>start[i];
	int finish[n];
	for(int i=0;i<n;i++)
		cin>>finish[i];
	item arr[n];
	for(int i=0;i<n;i++){
       arr[i].s=start[i];
       arr[i].f=finish[i];
	}
	

    activity_sel(arr,n);}
	return 0;
}