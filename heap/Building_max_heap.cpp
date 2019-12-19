//Creating a max heap
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int i,int n)
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
        heapify(arr,largest,n);
    }
}

void Build_max_heap(int arr[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(arr,i,n);
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
}
//Time complexity for buliding max_heap is O(N).
//Space complexity is O(1).



