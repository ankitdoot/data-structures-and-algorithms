#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void BucketSort(float arr[],int n)
{
    vector<float>b[n];

    for(int i=0;i<n;i++)
    {
        int bi = n*arr[i];
        b[bi].push_back(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        sort(b[i].begin(),b[i].end());
    }
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            arr[index++]=b[i][j];
        }
    }
}

int main()
{
    float arr[]={0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n=sizeof(arr)/sizeof(arr[0]);
    BucketSort(arr,n);

    cout << "Sorted array is \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}
/*The average time complexity for Bucket Sort is O(n + k). The worst time complexity is O(N^2).
The space complexity for Bucket Sort is O(n+k)
this is not an in-place sorting.
Bucket sort is also stable, if the underlying sorting algorithm is stable.*/

