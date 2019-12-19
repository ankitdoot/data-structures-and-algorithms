#include<iostream>
using namespace std;

struct node{
    
    int data;
    node* next;
};

struct node* head;

void push()
{
    cout<<"\nEnter element to push : ";
    struct node* new_node;
    new_node = new struct node;
    cin>>new_node->data;
    new_node->next = NULL;
    if(head == NULL)
    {
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
}

void pop()
{
    if(head->next == NULL)
        head =NULL;
    else {
        head = head->next;
    }
    cout<<"\none element popped\n";
}

void display()
{
    struct node* ptr;
    ptr = head; 
    cout<<"\nYour final stack is : ";
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    int x = 1;
    while(x != 0)
    {
        cout<<"Enter for push=1___pop=-1___nothing=0 : ";
        cin>>x;
        if(x == 1)
        {
            push();
        }
        else if(x == -1)
        {
            pop();
        }
        else break;
    }
    display();
}

