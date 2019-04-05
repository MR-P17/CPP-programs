//place N queens in NxN chessboard such that no queen can attack oter
#include<bits/stdc++.h>
using namespace std;
#define n 10
bool is_safe(int x,int y,int **arr)
{
	for(int i=x;i>=0;i--)
	if(arr[i][y]==1)
	return false;

    for(int i=y;i>=0;i--)
    if(arr[x][i]==1)
    return false;

    for(int i=x,j=y;i>=0 && j>=0;i--,j--)
    if(arr[i][j]==1)
    return false;

    for(int i=x,j=y;i>=0 && j<n;i--,j++)
    if(arr[i][j]==1)
    return false;

    return true;
}
bool queens_visit(int i,int** arr)
{
	if(i==n)
	return true;
        for(int j=0;j<n;j++){
    	if(is_safe(i,j,arr)==true)
    	{
    		arr[i][j]=1;
    		if(queens_visit(i+1,arr)==true)
    		return true;
    	    arr[i][j]=0;
    	}
    }
    return false;
}
void print(int **arr)
{   
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	cout<<arr[i][j]<<" ";
    cout<<endl;}
}
void place_queens()
{
	int **arr=new int *[n];
	for(int i=0;i<n;i++)
	arr[i]=new int[n];

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    arr[i][j]=0;

    if(queens_visit(0,arr)==true)
    {
    	print(arr);
    	return;
    }
    else
    {
    	cout<<"No possibility!"<<endl;
    	return;
    }
}
int main()
{
    place_queens();

	return 0;
}