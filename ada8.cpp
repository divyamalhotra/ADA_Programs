#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
	int freq,symIndex;
	char *binarycode;
	node *left,*right;
}*Q[50];
int m=0;
char *lstring,*rstring;
node* Extract_Min()
{
	node *min=Q[m++];
	return min;
}
void InsertQueue(node *root,int &qs)
{
	int pos=qs;
	for(int i=m;i<qs;i++)
	{
		if(Q[i]->freq>root->freq)
		{
			pos=i;
			break;
		}
	}
	for(int i=qs;i>pos;i--)
	Q[i]=Q[i-1];
	Q[pos]=root;
	qs++;
}
void generate_code(node *root,char *code[50],int n)
{
	if(root->left==NULL)
	{
		code[root->symIndex]=new char[n];
		strcpy(code[root->symIndex],root->binarycode);
	}
	//cout<<root->binarycode<<" ";}
	else
	{
		strcpy(lstring,root->binarycode);
		strcpy(rstring,root->binarycode);
		strcat(lstring,"0");
		strcpy(root->left->binarycode,lstring);
		strcat(rstring,"1");
		strcpy(root->right->binarycode,rstring);
		generate_code(root->left,code,n);
		generate_code(root->right,code,n);
	}
}
bool compare(node *t1,node *t2)
{
	return (t1->freq<t2->freq);
}
void huffman(int freq[],int n,char *code[50])
{
	int qs=n;
	node *P,*L,*R,*root;
	for(int i=0;i<n;i++)
	{
		Q[i]=new node;
		Q[i]->binarycode = new char[n];
		strcpy(Q[i]->binarycode,"");
		Q[i]->symIndex=i;
		Q[i]->freq=freq[i];
		Q[i]->left=NULL;
		Q[i]->right=NULL;	
	}
	sort(Q,Q+n,compare);
	for(int i=0;i<n-1;i++)
	{
		L=Extract_Min();
		R=Extract_Min();
		//cout<<L->freq<<" "<<R->freq<<endl;
		root=new node;
		root->binarycode = new char[n];
		strcpy(root->binarycode,"");
		root->symIndex=-1;
		root->left=L;
		root->right=R;
		root->freq=L->freq+R->freq;
		InsertQueue(root,qs);		
	}
	generate_code(root,code,n);
}
int main()
{
	int freq[50],n;
	char A[50],*code[50];
	cout<<"Enter no. of symbols: ";
	cin>>n;
	lstring = new char[n];
	rstring = new char[n];
	cout<<"Enter the symbols and corresponding frequency: \n";
	for(int i=0;i<n;i++)
	{
		cin>>A[i]>>freq[i];
	}
	huffman(freq,n,code);
	cout<<"Huffman code: \n";
	for(int i=0;i<n;i++)
		cout<<A[i]<<" = "<<code[i]<<endl;
	return 0;
}
