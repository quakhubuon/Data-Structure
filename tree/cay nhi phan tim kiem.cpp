#include <iostream>
using namespace std;

struct Node {
    int indexdata;
    Node *left;
    Node *right;
};

struct Node *createNode (int n)
{
    Node *newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->indexdata = n;
    return newNode;
}

struct Node *InsertNode (Node *root, int n)
{
    if (root == NULL)
        root = createNode(n);
    if (n < root->indexdata)
        root->left = InsertNode (root->left, n);
    if (n > root->indexdata)
    	root->right = InsertNode (root->right, n);
    return root;
}

struct Node *minValue(struct Node *root)
{
    Node *cur = root;
    while(cur != NULL && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}
struct Node *deleteNode(struct Node *root, int data)
{
    if(root == NULL)
        return root;
    
    if(data < root->indexdata)
        root->left = deleteNode(root->left,data);
    else if (data > root->indexdata)
        root->right = deleteNode(root->right,data);
    else
    {
        //1 child or leaf
        if(root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
		//2 child
        Node *temp = minValue(root->right);
        root->indexdata = temp->indexdata;
        root->right = deleteNode(root->right, temp->indexdata);
            
    }
    return root;
}

void DestroyTree (Node *root)
{
    if (root != NULL)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}

Node *findNode (Node *root, int n)
{
    if (root == NULL)
        return NULL;
    if (n < root->indexdata)
        return findNode (root->left, n);
    if (n > root->indexdata)
        return findNode (root->right, n);
    return root;
}

void printLNR (Node *root)
{
    if (root != NULL)
    {
        printLNR(root->left);
        cout << root->indexdata << " ";
        printLNR(root->right);
    }
}

void printNLR (Node *root)
{
	if (root != NULL)
	{
		cout << root->indexdata <<" ";
		printNLR(root->left);
		printNLR(root->right);
	}
}

void printRNL (Node *root)
{
	if (root != NULL)
	{
		printRNL(root->right);
		cout << root->indexdata << " ";	
		printRNL(root->left);
	}	
}

int main ()
{
    Node *t = NULL;
    t = createNode (5);
    t = InsertNode (t, -5);
    t = InsertNode (t, 8);
    t = InsertNode (t, 7);
    t = InsertNode (t, 15);
    t = InsertNode (t, 14);
    t = InsertNode (t, 13);
    t = InsertNode (t, 20);
    printLNR (t);
    cout <<endl;

    //deleteNode (t, 8);
    //printLNR (t);
    //Node *f = findNode(t, 1);
    //if (f == NULL)
    {
        //cout <<"Khong co Node trong cay.\n";
    }
    //else
    {
        //cout <<"Co node trong cay.\n";
    }

    //cout <<"Destroy Tree";
    //DestroyTree (t);
    //printLNR (t);
    
    //cout <<"NLR: ";
    //printNLR(t);
    
    //cout<<"RNL: ";
    //printRNL(t);
}
