#include<iostream>
using namespace std;

void push(int arr[],int* top)
{
	cout<<"\nenter element you want to push : ";
	int x;
	cin>>x;
	arr[*top] = x;
}


int main()
{
	int max_size;
	cout<<"Enter max elements in stack : ";
	cin>>max_size;
	int arr[max_size];
	int top = -1;
	int x = 1;
	int count = 0;
	while(x != 0)
	{
		cout<<"\nFor push = 1___pop = -1___End = 0 : ";
		cin>>x;
		if(x == 1)
		{
			if(top == max_size)
				cout<<"\n Error : Stack Overflow ";
			else
			{
				top++;
				push(arr, &top);
				count++;
			}
		}
		else if (x == -1)
		{
			if(top == -1)
				cout<<"\n Error : Stack Empty";
			else
			{
				top--;
				count--;
				cout<<"\nOne element poped";
			}
		}
		else break;
	}
	cout<<"\nYour stack is : ";
	for(int i=0;i<count;i++)
	{
		cout<<arr[i]<<" ";
	}
}
