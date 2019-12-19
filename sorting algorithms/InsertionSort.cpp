#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
	for(int i=1;i<n;i++)
	{
		int value=arr[i];
		int hole=i;
		while(hole > 0 && arr[hole-1]>value)
		{
			arr[hole]=arr[hole-1];
			hole--;
		}
		arr[hole]=value;
	}
}

int main()
{
	int n;
	cout<<"Enter no. of elements in array : ";
	cin>>n;
	cout<<"\nEnter elements of array : ";
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	InsertionSort(arr, n);
	cout<<"\nYour sorted array is : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
/*Time complexity
~~~In best case,array is already sorted and run time is= Ω(N).
~~~In worst case array is reverse sorted and run time is=O(N^2).
~~~In avg case time complexity is O(N^2).
*/
//Auxillary Space complexity is O(1)
//In practice, merge sort beats insertion sort for n > 30 or so.

/*Uses: Insertion sort is used when number of elements is small.
It can also be useful when input array is almost sorted,
only few elements are misplaced in complete big array.

This is a stable and In place sorting algorithm*/


