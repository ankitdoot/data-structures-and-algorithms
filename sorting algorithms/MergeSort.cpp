#include<iostream>
using namespace std;

void Merge(int arr[], int left[], int right[], int nL, int nR)//algorithm for merging two arrays
{
	int i=0,j=0,k=0;
	while(i<nL && j<nR)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else {
				arr[k]=right[j];
				j++;
			}
		k++;
	}
	while(i<nL)
	{
		arr[k]=left[i];
			i++;
			k++;
	}
	while(j<nR)
	{
		arr[k]=right[j];
			j++;
			k++;
	}
}

void MergeSort(int arr[], int n)
{
	if(n<2)
		return ;
	int mid = n/2;
	int nL=mid,nR=n-mid;
	int left[nL],right[nR];//dividing into two arrays
	for(int i=0;i<mid;i++)
	{
		left[i] = arr[i];
	}
	for(int i=mid;i<n;i++)
	{
		right[i-mid] = arr[i];
	}
	MergeSort(left,nL);
	MergeSort(right,nR);
	Merge(arr,left,right,nL,nR);//function for merging two sorted arrays
}

int main()
{
	int n;//no. of elements in array
	cout<<"Enter No.of elements in array : ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array : ";
	for(int i=0;i<n;i++)//taking inputs of array
	{
		cin>>arr[i];
	}
	MergeSort(arr, n);//function for merge sort algorithm
    cout<<"\nYour sorted array is : ";
	for(int i=0;i<n;i++)//printing sorted array
	{
		cout<<arr[i]<<" ";
	}
}
//It is a Divide and Conquer Algorithm.
/*~~~time complexity for merge sort is O(NLogn) in worst/best/avg case scenerio. */
//~~~This is not an in-place sorting algorithm
//~~This is a stable sorting algorithm.
//Space complexity is O(N).
/*If you draw the space tree out, it will seem as though the space complexity is O(nlgn).
However, as the code is a Depth First code, you will always only be expanding along one branch
of the tree, therefore, the total space usage required will always be bounded by O(3n) = O(n).
*/
