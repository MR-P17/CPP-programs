//Given a string find its corresponding bit code for whole string
//such that each distinct character get unique bit representation. 
#include<bits/stdc++.h>
using namespace std;
struct node
{
	char data;
	int f;
	node *lc,*rc; 
	node(char data,int f)
	{
		lc=rc=nullptr;
		this->data=data;
		this->f=f;
	}
};
struct cmp
{
   bool operator() ( node* a,node* b)
   {
   	  return a->f>b->f;
   }
};
void print(struct node* root,string str)
{
	if(!root)
	return;
    if(root->data!='#')
    cout<<root->data<<" : "<<str<<endl;
    print(root->lc,str+'0');
    print(root->rc,str+'1');
}
void huffman_coding(char arr[],int freq[],int size)
{  
	struct node *node1,*node2,*node3;
	priority_queue< node*, vector<node*> ,cmp >pq;
    for(int i=0;i<size;i++)
    pq.push(new node(arr[i],freq[i]));
    //cout<<pq.top()->data<<" "<<pq.top()->f<<endl;

    while(pq.size()!=1)
    {
    	node1=pq.top();pq.pop();
    	node2=pq.top();pq.pop();
    	node3=new node('#',node1 -> f + node2 -> f);
    	node3->lc=node1;
    	node3->rc=node2;
    	pq.push(node3);
    } 
    print(pq.top(),"");
}   
int main()
{
	int t;cin>>t;
	while(t--){
    string str;cin>>str;
    strcpy(arr,str.c_str());

    int n=sizeof(arr)/sizeof(arr[0])-1;
    int freq[n];
    for(int i=0;i<n;i++)
    cin>>freq[i];	

    huffman_coding(arr,freq,n);
    }
	return 0;
}
