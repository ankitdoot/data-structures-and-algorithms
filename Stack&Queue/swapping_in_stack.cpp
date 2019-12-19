#include<iostream>
#include<stack>
#include<vector>
#include<cstdlib>
using namespace std;

int main()
{
    stack<int> s1;
    stack<int> s2 ;
    cout<<"enter elements of stack1 : \n";
    for(int i=0;i<3;i++)
    {
        int x;
        cin>>x;
        s1.push(x);
    }
    cout<<"enter elements of stack2 : \n";
    for(int i=0;i<3;i++)
    {
        int x;
        cin>>x;
        s2.push(x);
    }
    cout<<"enter index of elements to swap : ";
    int a,b;
    cin>>a>>b;
    stack<int>temp1;
    stack<int>temp2;

    while(s1.top() != a)
    {
        temp1.push(s1.top());
        s1.pop();
    }
    while(s2.top() != b)
    {
        temp2.push(s2.top());
        s2.pop();
    }
    int temp = s2.top();
    s2.top() = s1.top();
    s1.top() = temp;
    while(!temp1.empty())
    {
        s1.push(temp1.top());
        temp1.pop();
    }
    
    
    while(!temp2.empty())
    {
        s2.push(temp2.top());
        temp2.pop();
    }
    cout<<"\nelements swapped";
    for(int i=0;i<3;i++)
    {
        cout<<"\n"<<s1.top();
        s1.pop();
    }
    for(int i=0;i<3;i++)
    {
        cout<<"\n"<<s2.top();
        s2.pop();
    }

}
    
