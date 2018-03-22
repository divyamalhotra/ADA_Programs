#include<iostream>
using namespace std;
int** strassen(int **A,int **B,int n)
{
	if(n==1)
	{
		int **P=new int*[1];
		P[0]=new int[1];
		P[0][0]=A[0][0]*B[0][0];
		return P;
	}
	int **A11,**A12,**A21,**A22,**B11,**B12,**B21,**B22,
		**P1,**P2,**P3,**P4,**P5,**P6,**P7,
		**C11,**C12,**C21,**C22,
		**A1112,**B1112,**A1122,**B1122,**A2122,**B2122,**A1222,**B1222,**A2111,**B2111,**C;
	A11=new int*[n/2];
	B11=new int*[n/2];
	A12=new int*[n/2];
	B12=new int*[n/2];
	A21=new int*[n/2];
	B21=new int*[n/2];
	A22=new int*[n/2];
	B22=new int*[n/2];
	for(int i=0;i<n/2;i++)
	{
		A11[i]=new int[n/2];
		B11[i]=new int[n/2];
		A12[i]=new int[n/2];
		B12[i]=new int[n/2];
		A21[i]=new int[n/2];
		B21[i]=new int[n/2];
		A22[i]=new int[n/2];
		B22[i]=new int[n/2];
		for(int j=0;j<n/2;j++)
		{
			A11[i][j]=A[i][j];
			B11[i][j]=B[i][j];
			A12[i][j]=A[i][j+n/2];
			B12[i][j]=B[i][j+n/2];
			A21[i][j]=A[i+n/2][j];
			B21[i][j]=B[i+n/2][j];
			A22[i][j]=A[i+n/2][j+n/2];
			B22[i][j]=B[i+n/2][j+n/2];
		}
	}
	A1112=new int*[n/2];
	B1112=new int*[n/2];
	A1122=new int*[n/2];
	B1122=new int*[n/2];
	A2122=new int*[n/2];
	B2122=new int*[n/2];
	A1222=new int*[n/2];
	B1222=new int*[n/2];
	A2111=new int*[n/2];
	B2111=new int*[n/2];
	for(int i=0;i<n/2;i++)
	{
		A1112[i]=new int[n/2];
		B1112[i]=new int[n/2];
		A1122[i]=new int[n/2];
		B1122[i]=new int[n/2];
		A2122[i]=new int[n/2];
		B2122[i]=new int[n/2];
		A1222[i]=new int[n/2];
		B1222[i]=new int[n/2];
		A2111[i]=new int[n/2];
		B2111[i]=new int[n/2];
	 	for(int j=0;j<n/2;j++)
		{
			A1112[i][j]=A11[i][j]+A12[i][j];
			B1112[i][j]=B11[i][j]+B12[i][j];
			A1122[i][j]=A11[i][j]+A22[i][j];
			B1122[i][j]=B11[i][j]+B22[i][j];
			A2122[i][j]=A21[i][j]+A22[i][j];
			B2122[i][j]=B21[i][j]+B22[i][j];
			A1222[i][j]=A12[i][j]-A22[i][j];
			B1222[i][j]=B12[i][j]-B22[i][j];
			A2111[i][j]=A21[i][j]-A11[i][j];
			B2111[i][j]=B21[i][j]-B11[i][j];
		}
	}
	P1=strassen(A1122,B1122,n/2);
	P2=strassen(A2122,B11,n/2);
	P3=strassen(A11,B1222,n/2);
	P4=strassen(A22,B2111,n/2);
	P5=strassen(A1112,B22,n/2);
	P6=strassen(A2111,B1112,n/2);
	P7=strassen(A1222,B2122,n/2);
	C11=new int*[n/2];
	C12=new int*[n/2];
	C21=new int*[n/2];
	C22=new int*[n/2];
	for(int i=0;i<n/2;i++)
	{
		C11[i]=new int[n/2];
		C12[i]=new int[n/2];
		C21[i]=new int[n/2];
		C22[i]=new int[n/2];
		for(int j=0;j<n/2;j++)
		{	
			C11[i][j]=P1[i][j]+P4[i][j]-P5[i][j]+P7[i][j];
			C12[i][j]=P3[i][j]+P5[i][j];
			C21[i][j]=P2[i][j]+P4[i][j];
			C22[i][j]=P1[i][j]+P3[i][j]-P2[i][j]+P6[i][j];
		}
	}
	C=new int*[n];
	for(int i=0;i<n/2;i++)
	{
		C[i]=new int[n];
		C[i+n/2]=new int[n];
		for(int j=0;j<n/2;j++)
		{
			C[i][j]=C11[i][j];
			C[i][j+n/2]=C12[i][j];
			C[i+n/2][j]=C21[i][j];
			C[i+n/2][j+n/2]=C22[i][j];
		}
	}
	return C;
}
int main()
{
	int n,**A,**B,**C;
	cout<<"Enter the size of matrix: ";
	cin>>n;
	cout<<"Enter the first matrix: \n";
	A=new int*[n];
	for(int i=0;i<n;i++)
	{
		A[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>A[i][j];
	}
	cout<<"Enter the second matrix: \n";
	B=new int*[n];
	for(int i=0;i<n;i++)
	{
		B[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>B[i][j];
	}
	C=strassen(A,B,n);
	cout<<"Result: \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<C[i][j]<<" ";
		cout<<endl;
    }	
	return 0;
}
