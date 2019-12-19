#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;

class stack{
        queue<int> q1,q2;
        public:
            void push(int data)
            {
                while(!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                q1.push(data);
                while(!q2.empty())
                {
                    q1.push(q2.front());
                    q2.pop();
                }
            }

            int pop()
            {
                if(q1.size() == 0)
                   { cout<<"underflow";
                    exit(0);}
                else
                {
                    int front = q1.front();
                    q1.pop();
                    return front;
                }
            }

};

int main()
{
    vector<int>keys = {10,20,30,40,50};
    stack s;
    for(int i=0;i<keys.size();i++)
    {
        s.push(keys[i]);
    }
    for(int i=0;;i++)
    {
        cout<<s.pop()<<"\n";
    }
}
