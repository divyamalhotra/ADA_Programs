#include<iostream>
using namespace std;
void sort(int A[],int B[],int C[],int n)
{
	int i=1;
	bool swapped;
	do
	{
		swapped=false;
		for(int j=0;j<n-i;j++)
		{
			if(A[j+1]>A[j])
			{
				swap(A[j+1],A[j]);
				swap(B[j+1],B[j]);
				swap(C[j+1],C[j]);
	            swapped=true;
			}
		}
		i++;
	}while(swapped);
}
void Job_sch(int d[],int p[],int n)
{
	int job[n],dmax,k,m;
	for(int i=0;i<n;i++)
	job[i]=i+1;
	sort(p,d,job,n);	
	dmax=d[0];
	for(int i=1;i<n;i++)
	{
		if(d[i]>dmax)
		dmax=d[i];
	}
	m=min(n,dmax);
	int slot[m];
	for(int i=0;i<m;i++)
	{
		slot[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		k=min(n-1,d[i]-1);
		while(k>=0)
		{
			if(slot[k]==0)
			{
				slot[k]=job[i];
				break;
			}
			k--;
		}
	}
	cout<<"Scheduled jobs: ";
	for(int i=0;i<m;i++)
	if(slot[i]!=0)
	cout<<"Job"<<slot[i]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Enter the no. of jobs: ";
	cin>>n;
	int d[n],p[n];
	cout<<"Enter the deadlines: \n";
	for(int i=0;i<n;i++)
	cin>>d[i];
	cout<<"Enter the profits: \n";
	for(int i=0;i<n;i++)
	cin>>p[i];
	Job_sch(d,p,n);
	return 0;
}
