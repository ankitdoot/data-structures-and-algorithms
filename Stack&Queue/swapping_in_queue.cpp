#include<iostream>
#include<stack>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter no. of elements in queue : ";
    int n;
    cin>>n;
    queue<int>q;
    queue<int>temp1;
    queue<int>temp2;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    int a,b;
    cout<<"\nEnter elements to be Swapped : ";
    cin>>a>>b;
    while(q.front() != a && q.front() != b)
    {
        temp1.push(q.front());
        q.pop();
    }
    a=q.front();
    q.pop();
    while(q.front() != a && q.front() != b)
    {
         temp2.push(q.front());
        q.pop();
    }
    b = q.front();
    q.pop();
    temp1.push(b);
    while(!temp2.empty())
    {
        temp1.push(temp2.front());
        temp2.pop();
    }
    temp1.push(a);
    while(!q.empty())
    {
        temp1.push(q.front());
        q.pop();
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<temp1.front()<<" ";
        temp1.pop();
    }
}



