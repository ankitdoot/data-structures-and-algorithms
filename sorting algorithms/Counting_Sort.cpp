#include<iostream>
using namespace std;

//find max elements of array
int get_max_size(int arr[],int n)
{
    int max_arr=arr[0];
    for(int p=1;p<n;p++)
    {
        if(arr[p]>max_arr)
                max_arr = arr[p];
    }
    return max_arr;
}

void CountingSort(int arr[],int n)
{
    int output[n];
    int max_arr = get_max_size(arr,n);
    int count_ite[max_arr+1];

    //initialize all elements to zero
    for(int x=0;x<=max_arr;x++)
    {
        count_ite[x] = 0;
    }

    //finding frequency of each element
    for(int i=0;i<n;i++)
    {
        ++count_ite[arr[i]];
    }

    for(int i=1;i<=max_arr;i++)
    {
        count_ite[i] += count_ite[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        output[count_ite[arr[i]]-1] = arr[i];//This line of code assures Counting Sort is stable
        --count_ite[arr[i]];
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }

}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++)
    {
        cin>>arr[j];
    }
    CountingSort(arr,n);
    cout<<"Your sorted array is : \n";
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<" ";
    }

}
/*Time Complexity :
As per Introduction to algorithm :
Counting sort assumes that each of the n input elements is an integer in the range 0 to k,
for some integer k. When k=O(n) counting sort runs in O(n) time.
or we can say time complexity is O(n+k).
~~~This is stable sorting algorithm.
~~~This is not an in-place sorting algorithm
~~~It's space complexity is O(n+k)*/

