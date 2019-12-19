#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n;
    cout<<"Input no.of elements in stack : ";
    cin>>n;
    stack<int>s;
    stack<int>temp1;
    stack<int>temp2;
    cout<<"\nEnter elements of stack : ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    cout<<"enter index of stack : first and last : to  reverse\n";
    int i,j;
    cin>>i>>j;
    for(int k=1;k<i;k++)
    {
        temp1.push(s.top());
        s.pop();
    }
    
    for(int k=i;k<=j;k++)
    {
        temp2.push(s.top());
        s.pop();
    }
    while(!temp1.empty())
    {
        temp2.push(temp1.top());
        temp1.pop();
    }
    while(!temp2.empty())
    {
        temp1.push(temp2.top());
        temp2.pop();
    }
    while(!temp1.empty())
    {
        s.push(temp1.top());
        temp1.pop();
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}






