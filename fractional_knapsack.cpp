#include <bits/stdc++.h>
using namespace std;
struct item
{
  int value,weight;
};
bool cmp(struct item a,struct item b)
{
    double r1=(double)a.value/a.weight ;
    double r2=(double)b.value/b.weight ;
    return r1>r2;
}
double f_knapsack(int wt,item arr[],int n)
{
sort(arr,arr+n,cmp);

int cur_wt=0;
double final_value=0.0;
for(int i=0;i<n;i++)
{
    if(cur_wt+arr[i].weight<=wt)
    {
        cur_wt+=arr[i].weight;
        final_value+=arr[i].value;
    }
    else
    {
        int rest=wt-cur_wt;
        final_value+=arr[i].value*((double)rest/arr[i].weight);
        break;
    }
}
  return final_value;
}
int main() 
{
    int wt=50;
    int n;cin>>n;

    item arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i].value>>arr[i].weight;

    cout<<f_knapsack(wt,arr,n);
    return 0;
}
