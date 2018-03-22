#include<iostream>
using namespace std;
struct set
{
	int data;
	set *next;
	set *rep;
}*head[10],*tail[10];
int count=0;
void makeset(int x)
{
	count++;
	for(int i=0;i<count;i++)
	if(head[i]==NULL)
	{
		head[i]=new set;
		head[i]->data=x;
		head[i]->rep=head[i];
		head[i]->next=NULL;
		tail[i]=head[i];	
	}
}
set* find_set(int x)
{
	set *temp;
	for(int i=0;i<count;i++)
	{
		temp=head[i];
		while(temp!=NULL)
		{
			if(temp->data==x)
			return head[i];
			temp=temp->next;
		}
	}
	return NULL;
}
void union_set(int x,int y)
{
	set *rep1,*rep2,*temp1,*temp2;
	int r1,r2;
	rep1=find_set(x);
	rep2=find_set(y);
	if(rep1==NULL||rep2==NULL)
	{
		cout<<"Set does not exist!!!\n";
		return;
	}
	if(rep1==rep2)
	{
		cout<<"Same set!!!\n";
		return;
	}
	temp1=rep1;
	temp2=rep2;
	for(int i=0;i<count;i++)
	{
		if(head[i]==rep1)
		r1=i;
		if(head[i]==rep2)
		r2=i;
	}
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next;
	}
	if(temp2!=NULL)
	{
		while(temp2->next!=NULL)
		temp2=temp2->next;
		temp2->next=rep1;
		temp1=rep1;
		while(temp1!=NULL)
		{
			temp1->rep=rep2;
			temp1=temp1->next;
		}
		head[r1]=head[r2];
	}
	else
	{
		temp1->next=rep2;
		temp2=rep2;
		while(temp2!=NULL)
		{
			temp2->rep=rep1;
			temp2=temp2->next;
		}
		tail[r1]=tail[r2];
	}
	tail[r2]=NULL;
	head[r2]=NULL;
	delete tail[r2];
	delete head[r2];
}
void disp()
{
	set *temp;
	for(int i=0;i<count;i++)
	{
		temp=head[i];
		if(temp==NULL)
		continue;
		while(temp!=NULL)
		{
			cout<<temp->data;
			if(temp!=tail[i])
			cout<<"->";
			temp=temp->next;
		}
		cout<<endl;
	}
}
int main()
{
	int ch,value;
	char c;
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
			cout<<"Now sets are: \n";
			disp();
		}
		else if(ch==2)
		{
			int x,y;
			cout<<"Enter the members of two sets that you want to join: ";
			cin>>x>>y;
			union_set(x,y);
			cout<<"Now sets are: \n";
			disp();
		}
		else if(ch==3)
		{
			set *s;
			cout<<"Enter the value you want to search for: ";
			cin>>value;
			s=find_set(value);
			if(s==NULL)
			cout<<value<<" not found!!!\n";
			else
			cout<<"Representative of the set containing "<<value<<" is: "<<s->data<<endl;
		}
		else
		cout<<"Wrong Choice!!!\n";
		cout<<"Do you want to perform more?? y or n- ";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}
