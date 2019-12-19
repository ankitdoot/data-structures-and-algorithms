#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

void search(struct node* root,int value)
{
    if(root == NULL)
    {
        cout<<"\nData not found";
        return;
    }
    else if(root->data == value)
    {
        cout<<"\nData found";
        return ;
    }
    else if(value <= root->data)
    {
        search(root->left,value);
    }
    else {
        search(root->right,value);
    }
}

struct node* make_new_node(struct node* root, int new_data)
{
    struct node* new_node;
    new_node = new struct node;
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;
    cout<<1<<"\n";
    return new_node;
}

struct node* insert(struct node* root, int new_data)
{
    if(root == NULL)
    {
        root = make_new_node(root,new_data);
    }
    else if(new_data <= root->data)
    {
        root->left = insert(root->left,new_data);
    }
    else {
        root->right = insert(root->right,new_data);
    }
    return root;
}


struct node* delete(struct node* root,int key)
{
    if(root == NULL)
    {
        return;
    }
    else if(key < root->data)
    {
        root->left = delete(root->left,key);
    }
    else if(key > root->data)
    {
        root->right = delete(root->right, key);
    }
    else
    {
        //if key has no chilren
        if(root->left == NULL && root->right == NULL)
        {
            root = NULL;
        }
        else if(root->left == NULL)
        {
            root = root->right;
        }
        else if(root->right == NULL)
        {
            root = root->left;
        }
        else {
            struct node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}

struct node* FindMin(struct node* root)
{
    while(root->left != NULL)
    {
        root  = root->left;
        return root;
    }
}



int main()
{
    struct node* root = NULL;
    root = insert(root, 15);
    insert(root,10);
    insert(root,12);
    insert(root,20);
    insert(root,17);
    insert(root,13);
    insert(root,21);
    insert(root,37);

    search(root,13);
    search(root,18);
    /*****delete a key********/
    delete(root,37);
    delete(root,13);

}
