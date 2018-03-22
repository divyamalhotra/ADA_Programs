#include<iostream>
using namespace std;
struct minmax
{
	int min,max;
};
minmax MaxMin(int A[],int first,int last)
{
	int mid;
	minmax mm,mm1,mm2;
	if(first==last)
	{
		mm.max=mm.min=A[first];
		return mm;
	}
	else if(first==last-1)
	{
		if(A[first]>A[last])
		{
			mm.max=A[first];
			mm.min=A[last];
		}
		else
		{
			mm.max=A[last];
			mm.min=A[first];
		}
		return mm;
	}
	else
	{
		mid=(first+last)/2;
	    mm1=MaxMin(A,first,mid);
		mm2=MaxMin(A,mid+1,last);
		if(mm1.max>mm2.max)
		mm.max=mm1.max;
		else
		mm.max=mm2.max;
		if(mm1.min<mm2.min)
		mm.min=mm1.min;
		else
		mm.min=mm2.min;
		return mm;
	}
}
int main()
{
	int n;
	minmax mm;
	cout<<"Enter the size of array: ";
	cin>>n;
	int A[n];
	cout<<"Enter the array: ";
	for(int i=0;i<n;i++)
	cin>>A[i];
	mm=MaxMin(A,0,n-1);
	cout<<"Max= "<<mm.max<<"\tMin= "<<mm.min;
	return 0;
}
