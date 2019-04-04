#include<bits/stdc++.h>
using namespace std;

void egyptian_fraction(int nr,int dr)
{
	if(nr==0 || dr==0)
		return;
	if(nr%dr==0)
	{
		cout<<nr/dr<<" ";
		return;
	}
	if(dr%nr==0)
	{
		cout<<"1/"<<dr/nr<<" ";
		return;
	}
	if(nr>dr)
	{
		cout<<nr/dr<<" + ";
		return egyptian_fraction(nr%dr,dr);
	}
	    int n=dr/nr + 1;
		cout<<"1/"<<n<<" + ";
		return egyptian_fraction(nr*n-dr,n*dr);
	
}
int main()
{
	int nr,dr;cin>>nr>>dr;
	egyptian_fraction(nr,dr);

	return 0;
}