#include<iostream>
#include<queue>
using namespace std;

struct Bstnode
{
    int data;
    Bstnode* left;
    Bstnode* right;
};

Bstnode* insert_data(Bstnode* ,int );
Bstnode* make_new_node(Bstnode* ,int );
int find_height(Bstnode* );
void TreeTraversal(Bstnode* );
void Level_Order_Traversal(Bstnode*);

int main()
{
    Bstnode* root=NULL;
    root = insert_data(root,5);
    insert_data(root,7);
    insert_data(root,4);
    insert_data(root,8);
    insert_data(root,10);
    insert_data(root,2);
    insert_data(root,1);

    int height = find_height(root);
    cout<<"Max Height of Tree is : "<<height;
    cout<<"\nTree Traversal By Preorder : ";

    TreeTraversal(root);

    cout<<"\nTree Traversal By Level Order : ";
    Level_Order_Traversal(root);
}

Bstnode* insert_data(Bstnode* root,int value)
{
    if(root==NULL)
    {
        root = make_new_node(root,value);
        return root;
    }
    else if(value <= root->data)
    {
        root->left = insert_data(root->left,value);
    }
    else {
        root->right = insert_data(root->right,value);
    }

}

Bstnode* make_new_node(Bstnode* root,int value)
{
    Bstnode* new_node;
    new_node = new struct Bstnode;
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int find_height(Bstnode* root)
{
    if(root==NULL)
            return -1;
    else return max(find_height(root->left),find_height(root->right)) + 1;
}

//Pre-order depth first Traversal
//Time complexity is O(N)
//Space Complexity is O(h),where h is height of tree
//Space Complexity in Worst case is O(N),in avg case O(logN)
void TreeTraversal(Bstnode* root)
{
    if(root == NULL)
        return;
    else
        cout<<root->data<<" ";
        TreeTraversal(root->left);
        TreeTraversal(root->right);
        return ;
}

//Level Order Traversal
//Time Complexity is O(N) .
//Space complexity is O(N) in worst case and O(1) in best case.
void Level_Order_Traversal(Bstnode* root)
{
    queue<Bstnode*>q;
    if(root == NULL)
        return;
    else q.push(root);
    while(!q.empty())
    {
        Bstnode* current = q.front();
        cout<<current->data<<" ";
        if(current->left != NULL)
            q.push(current->left);
        if(current->right != NULL)
            q.push(current->right);
        q.pop();
    }
}

