#include<iostream>
using namespace std;

void Sort_BinaryArray(int arr[],int n)
{
    int zero=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
            zero++;
    }
    for(int i=0;i<zero;i++)
    {
        arr[i]=0;
    }
    for(int i=zero;i<n;i++)
    {
        arr[i]=1;
    }
}

int main()
{
    int arr[]={1,0,0,1,0,1,1,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    Sort_BinaryArray(arr,n);
    cout<<"Your Sorted Binary Array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
//time complexity O(N)
//space complexity O(N)

