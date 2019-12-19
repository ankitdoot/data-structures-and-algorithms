#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>q;
    queue<int>temp1;
    queue<int>temp2;
    int n;
    cout<<"Enter no.of elements in queue : ";
    cin>>n;
    cout<<"\nEnter elements of queue : ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    cout<<"Enter indices of elements to remove : ";
    int a,b;
    cin>>a>>b;
    int i,j;
    int length_temp1 = a-1;
    for(i=1;i<a;i++)
    {
        temp1.push(q.front());
        q.pop();
    }
    int length_temp2=b-a+1;;
    for(j=a;j<=b;j++)
    {
        temp2.push(q.front());
        q.pop();
    }
    for(int i=1;i<length_temp2;i++)
    {
        for(int j=i+1;j<=length_temp2;j++)
        {
            temp2.push(temp2.front());
            temp2.pop();
        }
        temp1.push(temp2.front());
        temp2.pop();
    }
    temp1.push(temp2.front());
        temp2.pop();
    
    
   for(int i=1;i<=n-b;i++)
   {
       temp1.push(q.front());
       q.pop();
   }
        
    cout<<"\nYour queue after reversing is : ";
    for(int i=1;i<=n;i++)
    {
        cout<<temp1.front()<<" ";
        temp1.pop();
    }
    
}



