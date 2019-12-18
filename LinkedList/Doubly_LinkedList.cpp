#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

struct node* head = NULL;

void insert(int new_data)
{
    struct node* new_node;
    new_node = new struct node;
    new_node->data = new_data;
    if(head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        struct node* ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL;
        new_node->prev = ptr;
    }
}

void display()
{
    struct node* ptr;
    ptr=head;
    while(ptr !=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    insert(12);
    insert(10);
    insert(15);
    insert(21);
    insert(32);

    display();

}
