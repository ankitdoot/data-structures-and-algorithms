
#include<iostream>
using namespace std;

struct Bstnode
{
    int data;
    Bstnode* left;
    Bstnode* right;
};

Bstnode* create_new_node(Bstnode* root,int data)
{
    Bstnode* new_node;
    new_node = new struct Bstnode;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Bstnode* insert(Bstnode* root,int data)
{
    if(root==NULL)
    {
        root=create_new_node(root,data);
        return root;
    }
    else if(data <= root->data)
    {

        root->right = insert(root->right,data);
    }
    else{
        root->left = insert(root->left,data);
    }
    return root;
}

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
		search(root->right,n);
	}
	else if(root->data < n)
	{
		search(root->left,n);
	}
}

//Taking mirror output of BST

void mirror(Bstnode* root)
{
	Bstnode* temp = root->right;
	root->right = root->left;
	root->left = temp;
}


int main()
{
    Bstnode* root = NULL;
    root = insert(root,8);
    insert(root,5);
    insert(root,9);
    insert(root,4);
    insert(root,12);

    int n;
	cout<<"Enter element to search : ";
	cin>>n;
	search(root ,n);

    mirror(root);
	cout<<"\nEnter element to search : ";
	cin>>n;
	search(root ,n);

}


