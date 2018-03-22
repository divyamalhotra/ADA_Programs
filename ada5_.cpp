#include<iostream>
using namespace std;
char P[50];
int rank[50];
void makeset(char x)
{
	P[x-97]=x;
	rank[x-97]=0;
}
char find_set(char x)
{
	if(x==' ')
	return -1;
	if(x!=P[x-97])
	P[x-97]=find_set(P[x-97]);
	return P[x-97];
}
void union_set(char x,char y)
{
	char rep1,rep2;
	rep1=find_set(x);
	rep2=find_set(y);
	if(rep1==-1||rep2==-1)
	{
		cout<<"Set does not exist!!!\n";
		return;
	}
	if(rep1==rep2)
	{
		cout<<"Same set!!!\n";
		return;
	}
	if(rank[rep1-97]>rank[rep2-97])
	P[rep2-97]=rep1;
	else if(rank[rep1-97]<rank[rep2-97])
	P[rep1-97]=rep2;
	else
	{
		P[rep2-97]=rep1;
		rank[rep1-97]++;
	}
}
void disp()
{
	for(int i=0;i<26;i++)
	{
		if(P[i]!=' ')
		cout<<P[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int ch;
	char c,value;
	for(int i=0;i<26;i++)
	P[i]=' ';
	do
	{
		cout<<"Choose: \n";
		cout<<"1. Make a set\n";
		cout<<"2. Union of two sets\n";
		cout<<"3. Find set\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the data: ";
			cin>>value;
			makeset(value);
			cout<<"Parent array: \n";
			disp();
		}
		else if(ch==2)
		{
			char x,y;
			cout<<"Enter the members of two sets that you want to join: ";
			cin>>x>>y;
			union_set(x,y);
			cout<<"Parent array: \n";
			disp();
		}
		else if(ch==3)
		{
			char s;
			cout<<"Enter the value you want to search for: ";
			cin>>value;
			s=find_set(value);
			if(s==-1)
			cout<<value<<" not found!!!\n";
			else
			cout<<"Representative of the set containing "<<value<<" is: "<<s<<endl;
		}
		else
		cout<<"Wrong Choice!!!\n";
		cout<<"\nDo you want to perform more?? y or n- ";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}
