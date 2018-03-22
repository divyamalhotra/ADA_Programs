#include<iostream>
using namespace std;
void fractional_knapsack(float V[],float W[],float c,int n,float&value)
{
	float R[100];
	for(int i=0;i<n;i++)
	R[i]=V[i]/W[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(R[j]<R[j+1])
			{
				swap(R[j],R[j+1]);
				swap(V[j],V[j+1]);
				swap(W[j],W[j+1]);
			}
		}
	}
	float wgt=0,f=0;
	value=0;
	for(int i=0;i<n;i++)
	{
		if(c!=0)
		{
			f=c/W[i];
			if(f>=1)
			f=1;
			wgt=f*W[i];
			value+=f*V[i];
			c-=f*W[i];
		}
	}
}
int main()
{
	float V[100],W[100],value,c;
	int n;
	cout<<"Enter no. of items: ";
	cin>>n;
	cout<<"Enter values of items: ";
	for(int i=0;i<n;i++)
	cin>>V[i];
	cout<<"Enter weights of items: ";
	for(int i=0;i<n;i++)
	cin>>W[i];
	cout<<"Enter the capacity of knapsack: ";
	cin>>c;
	fractional_knapsack(V,W,c,n,value);
	cout<<"Value: "<<value;
	return 0;
}
