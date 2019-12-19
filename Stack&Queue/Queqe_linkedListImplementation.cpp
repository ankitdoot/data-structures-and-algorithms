#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void push()
{
	struct node* new_node;
	new_node = new struct node;
	cout<<"\nEnter value to push : ";
	cin>>new_node->data;
	if(tail == NULL)
	{
		 head = new_node;
		 tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
		tail->next=NULL;
	}
}

void pop()
{
	if(head == NULL)
		cout<<"\nError : queue already empty";
	else
	{
		head = head->next;
		cout<<"\nOne element popped";

	}
}

void display()
{
	cout<<"\nYour Queue is : ";
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}

}

int main()
{
	int x=1;
	while(x != 0)
	{
		cout<<"\nEnter for push=1__pop=-1__nothing=0 : ";
		cin>>x;
		if(x == 1)
			push();
		else if(x == -1)
			pop();
		else break;
	}
	display();
}
