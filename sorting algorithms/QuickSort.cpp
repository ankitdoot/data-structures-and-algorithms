#include<iostream>
using namespace std;

int Partition(int arr[], int start, int end)//partitioning array into two sub-array
{
	int pivot = arr[end];
	int pindex=start;
	for(int i=start;i<end;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr[i], arr[pindex]);
			++pindex;
		}
	}
	swap(arr[pindex], arr[end]);
	return pindex;

}

void QuickSort(int arr[], int start,int end)//quick sort algorithm
{
	if(start < end)
	{
		int pindex = Partition(arr, start, end);
		QuickSort(arr, start, pindex-1);
		QuickSort(arr, pindex+1, end);
	}
}
int main()
{
	int n;//no. of elements of array
	cout<<"Enter no of elements : ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter elements of array : ";
	for(int i=0;i<n;i++)//taking inputs of array
	{
		cin>>arr[i];
	}
	QuickSort(arr, 0, n-1);
	cout<<"Your sorted array is : ";
	for(int i=0;i<n;i++)//printing sorted array
	{
		cout<<arr[i]<<" ";
	}
}
////It is a Divide and Conquer Algorithm.
//~~~Time Complexity,In best case,time complexity is O(NLog(N))
//In worst case it is O(N^2)
//The Average case run time of Quick sort is O( NlogN ).
//space complexity is O(N).
//Auxiliary space required as Stack is O(logN).
//This is an in-place sorting algorithm
//~~~This is not a stable sorting  algorithm

