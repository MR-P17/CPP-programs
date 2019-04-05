#include<bits/stdc++.h>
using namespace std;
# define n 5
bool maze_visit(int i,int j,int **arr,int **path)
{
	if(i==n-1 && j==n-1)
	return true;
	

    if(j+1<n && arr[i][j+1]==1)
    {   
    	path[i][j+1]=1;
    	if(maze_visit(i,j+1,arr,path)==true)
    	return true;
        path[i][j+1]=0;
    }



    if(i+1<n && arr[i+1][j]==1)
    {   
    	path[i+1][j]=1;
    	if(maze_visit(i+1,j,arr,path)==true)
    	return true;
        path[i][j+1]=0;
    }
     return false;
}
void rat_maze(int **arr)
{
	int **path=new int*[n];
	for(int i=0;i<n;i++)
	path[i]=new int[n];

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    path[i][j]=0;

    path[0][0]=1;

    cout<<endl<<endl;

    if(maze_visit(0,0,arr,path)==true)
    {
    	for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++)
    	cout<<path[i][j]<<" ";
        cout<<endl;}

        return;
    }
    else
    {
    	cout<<"No path exist"<<endl;
    	return;
    }
}
int main()
{
    int **arr=new int *[n];
    for(int i=0;i<n;i++)
    arr[i]=new int[n];

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];

    rat_maze(arr);

	return 0;
}