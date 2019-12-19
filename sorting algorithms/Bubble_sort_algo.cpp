//Bubble Sort
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of element in array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter elements of array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++)
    {
        int flag = 0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }

    cout<<"Sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
/*Time Complexity in best case is O(N),when array is already sorted.
Time Complexity in avg/worst case is O(N^2).
Bubble sort is an stable sorting algorithm.
This is  an In-place sorting algorithm.
It's auxilliary space Complexity is O(1). */
