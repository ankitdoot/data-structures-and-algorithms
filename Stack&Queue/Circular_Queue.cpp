#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int q[n];
    int front=-1,rear = -1;
    while(1)
    {
        int i;
        cout<<"\nPress 1 for enque and -1 for qeque and 0 for stop : ";
        cin>>i;
        /****************enqueue************************/
        if(i==1)
        {
            cout<<"\nEnter element to enque : ";
            int new_data;
            cin>>new_data;
            if(front == -1 && rear == -1)
            {
                front = rear = 0;
                q[rear] = new_data;
            }
            else if((rear+1) % n == front)
            {
                cout<<"\nQueue is already full";
            }
            else {
                rear = (rear + 1) % n;
                q[rear] = new_data;
            }
        }
        /****************dequeue***************************/
        else if(i == -1)
        {
            if(front == -1 && rear == -1)
            {
                cout<<"\nQueue is already empty";
            }
            else if(front == rear)
            {
                front = rear = -1;
            }
            else
            {
                cout<<"\n"<<q[front]<<" is dequed";
                front  = (front+1)%n;
            }
        }
        /*********************stop/exit*************************/
        else break;
    }
}
