#include<iostream>
#define MAXSIZE 50
using namespace std;
int main()
{
	int n,array[MAXSIZE];
	int ThisSum=0,MaxSum=0;
	cout<<"Enter the size of the array:";
	cin>>n;
	cout<<"Enter the elements of the array:"<<endl; 
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ThisSum=0;
			for(int k=0;k<n;k++)
			{
				ThisSum+=array[k];
			}
			if(ThisSum>MaxSum)
				MaxSum=ThisSum;
		}
	}
	cout<<MaxSum;
	return 0;
}
