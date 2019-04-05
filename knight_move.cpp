//fill the chessboard of n*n by steps taken by a knight
// using Backtracking
#include<bits/stdc++.h>
using namespace std;
#define n 6
bool knight_visit(int i,int j,int move,int **arr)
{
    if(move==n*n){
     
    	return true;
    }
    if(i+2<n && j+1<n && arr[i+2][j+1]==-1)
    {
       	arr[i+2][j+1]=move;
        if(knight_visit(i+2,j+1,move+1,arr)==true)
          return true;
       	arr[i+2][j+1]=-1;
    }

    if(i+2<n && j-1>=0 && arr[i+2][j-1]==-1)
    {
       	arr[i+2][j-1]=move;
        if(knight_visit(i+2,j-1,move+1,arr)==true)
        	return true; 
       	arr[i+2][j-1]=-1;
    }

      if(i-2>=0 && j-1>=0 && arr[i-2][j-1]==-1)
    {
       	arr[i-2][j-1]=move;
        if(knight_visit(i-2,j-1,move+1,arr)==true)
        	return true;
       	arr[i-2][j-1]=-1;
    }

      if(i-2>=0 && j+1<n && arr[i-2][j+1]==-1)
    {
       	arr[i-2][j+1]=move;
        if(knight_visit(i-2,j+1,move+1,arr)==true)
        	return true;
       	arr[i-2][j+1]=-1;
    }

      if(i-1>=0 && j-2>=0 && arr[i-1][j-2]==-1)
    {
       	arr[i-1][j-2]=move;
        if(knight_visit(i-1,j-2,move+1,arr)==true)
        	return true;
       	arr[i-1][j-2]=-1;
    }

      if(i+1<n && j-2>=0 && arr[i+1][j-2]==-1)
    {
       	arr[i+1][j-2]=move;
        if(knight_visit(i+1,j-2,move+1,arr)==true)
        	return true;
       	arr[i+1][j-2]=-1;
    }


      if(i-1>=0 && j+2<n && arr[i-1][j+2]==-1)
    {
       	arr[i-1][j+2]=move;
        if(knight_visit(i-1,j+2,move+1,arr)==true)
        	return true;
       	arr[i-1][j+2]=-1;
    }

      if(i+1<n && j+2<n && arr[i+1][j+2]==-1)
    {
       	arr[i+1][j+2]=move;
        if(knight_visit(i+1,j+2,move+1,arr)==true)
        	return true;
       	arr[i+1][j+2]=-1;
    }

    return false;
}
void knight_move(int **arr)
{
	int move=0;
	arr[0][0]=0;
	if(knight_visit(0,0,move+1,arr)==true)
    {
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++)
    			cout<<arr[i][j]<<" ";
    		cout<<endl;
    	}
    	return;
    }
    else{
    	cout<<"no soln exist"<<endl;
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
    		arr[i][j]=-1;
    //cout<<arr[0][0]<<" "<<arr[7][7];
    knight_move(arr);

    return 0;
}