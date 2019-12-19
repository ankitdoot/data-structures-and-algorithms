//CREATING MIN_HEAP
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void min_heapify(int arr[],int i,int n)
{
   
    int lowest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]<arr[lowest])
        lowest = l;
    if(r<n && arr[r]<arr[lowest])
        lowest = r;
    if(lowest != i)
    {
        swap(arr[lowest],arr[i]);
        min_heapify(arr,lowest,n);
    } 
}

void Build_min_heap(int arr[],int n)
{
    for(int i = n/2-1;i>=0;i--)
    {
        min_heapify(arr,i,n);
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
    
    Build_min_heap(arr,n);
    cout<<"\nYour min_heap is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
//Time complexity for building max_heap is O(N).
//Space complexity is O(1).




