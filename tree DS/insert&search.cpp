#include<iostream>
using namespace std;

struct Bstnode{
	int data;
	Bstnode* left;
	Bstnode* right;
};

void search(Bstnode* root,int n)
{
	if(root == NULL)
	{
		cout<<"\nNotFound :(";
	}
	else if(root->data == n)
	{
		cout<<"\nFound :)";
	}
	else if(root->data >= n)
	{
		search(root->left,n);
	}
	else if(root->data < n)
	{
		search(root->right,n);
	}
}

Bstnode* Getnewnode(Bstnode* root,int data)
{
	Bstnode* newnode;
	newnode = new struct Bstnode;
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

Bstnode* insert(Bstnode* root,int data)
{
	if(root == NULL)//empty BST
	{
		root = Getnewnode(root,data);
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left,data);
	}
	else {
		root->right = insert(root->right,data);
	}
	return root;
}

int main()
{
		Bstnode* root = NULL;
		root = insert(root,10);
		insert(root,15);
		insert(root,20);
		int n;
		cout<<"Enter element to search : ";
		cin>>n;
		search(root ,n);
}
