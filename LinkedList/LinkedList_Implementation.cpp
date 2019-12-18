#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

struct node* head ;

void insert(void)
{
	struct node* new_node;
	new_node = new struct node;
	cin>>new_node->data;
	new_node->next = NULL;
	if(head == NULL)
	{
		head = new_node;
	}
	else 
	{
		struct node* p;
		p = head;	
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new_node;
	}	
}

void display(int n)
{
	struct node* ptr;
	ptr = head;
	for(int i=0;i<n;i++)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
			
	}
}

void remove_element(int key)
{
	struct node* ptr;
	ptr = head;
	int count = 1;
	while(ptr->data != key)
	{
		count++;
		ptr = ptr->next;
		if(ptr->next == NULL)
			return;
	}
	cout<<count<<endl;
	struct node* a;
	
	if(count == 1)
	{
		head = ptr->next;
		ptr->next = NULL;
		delete(ptr);
	}
	else {
		int i=1;
		ptr = head;
		while(i<count-1)
		{
				i++;
				ptr = ptr->next;
		}
		a = ptr->next;
		ptr->next = a->next;
		a->next = NULL;
	}

}

int main()
{
	int n;
	cout<<"enter no. of elements in linked list\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		insert();
	}
	display(n);
	cout<<"\nEnter value of element you want to delete : ";
	int key;
	cin>>key;
	remove_element(key);
	display(n-1);
}
