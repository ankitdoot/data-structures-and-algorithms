//Creating a max heap
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify_TopDown(int arr[],int i,int n)
{
    int largest = i;
    int l = 2*i+1;//left child = 2*i+1
    int r = 2*i+2;//right child = 2*i+2
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify_TopDown(arr,largest,n);
    }
}

void heapify_BottomUp(int arr[],int i,int n)
{
	int parent = (i-1)/2;
	if(arr[i]>arr[parent])
	{
		swap(arr[i],arr[parent]);
		heapify_BottomUp(arr,parent,n);
	}
}

void Build_max_heap(int arr[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify_TopDown(arr,i,n);
    }
}

int main()
{
    int n;
    cout<<"Enter no of elements to insert : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter elements to insert in array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Build_max_heap(arr,n);
    cout<<"\nYour max_heap is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
        
    cout<<"\nEnter Element to change : ";
    int data;
    cin>>data;
    int i;
    for(i=0;i<n;i++)
    {
    	if(arr[i]==data)
    		break;
    }
    cout<<"\nEnter new value of element : ";
    int new_data;
    cin>>new_data;
    arr[i] = new_data;
    int diff = data - new_data;
    if(diff>0)
    {
    	heapify_TopDown(arr,i,n);
    }
    else if(diff<0)
    {
    	heapify_BottomUp(arr,i,n);
    }
    cout<<"\nYour max_heap is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
