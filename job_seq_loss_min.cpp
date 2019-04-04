// find sequence in which job to be done such that total is minimized
#include<bits/stdc++.h>
using namespace std;
struct job
{
   int loss,time;
};
bool cmp(struct job a,struct job b)
{
	int l_a=a.loss,l_b=b.loss;
	int t_a=a.time,t_b=b.time;
	return l_a*t_b>l_b*t_a;
}
void loss_min(job arr[],int n,vector<int> &v)
{
	stable_sort(arr,arr+n,cmp);
	cout<<endl;
	//for(int i=0;i<n;i++)
	//cout<<arr[i].loss<<"  "<<arr[i].time<<endl;
	
	for(int i=0;i<n;i++)
		v.push_back(arr[i].loss);
}
int main()
{
   int n;cin>>n;
   job arr[n],arr_tmp[n];
   int a,b;
   for(int i=0;i<n;i++){
   	cin>>a>>b;
   	arr[i].loss=arr_tmp[i].loss=a;
   	arr[i].time=arr_tmp[i].time=b;
   }
    vector<int>v;
    loss_min(arr,n,v);


    for(int i=0;i<v.size();i++)
		for(int j=0;j<n;j++)
		{
			if(v[i]==arr_tmp[j].loss)
			{
				cout<<j+1<<" ";
				break;
			}
		}
	return 0;
}
