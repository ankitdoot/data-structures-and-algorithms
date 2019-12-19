#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int min = arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                swap(arr[j],arr[i]);
            }
        }
    }
    cout<<"\nYour sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cout<<"Enter no of elements in array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter elements of array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    SelectionSort(arr,n);
}

//Time complexity is O(N^2) in Worst/Best/Avg case.
//Space complexity is O(1).
//THis is an In Place sorting algorithm
//THis is an unstable sorting algorithm
