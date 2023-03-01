#include <iostream>
using namespace std;
struct Node
{
    int indexdata;
    Node *left;
    Node *right;
    int height;
};

Node *createNode(int n)
{
    struct Node *newNode = new Node;
    newNode->indexdata = n;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}
int Height(struct Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
int Balance(struct Node *root)
{
    if (root == NULL)
        return 0;
    return Height(root->left) - Height(root->right);
}
struct Node *leftRotate(struct Node *root)
{
    Node *W = root->right;
    root->right = W->left;
    W->left = root;
    root->height = max(Height(root->left), Height(root->right)) + 1;
    W->height = max(Height(W->left), Height(W->right)) + 1;
    return W;
}
struct Node *rightRotate(struct Node *root)
{
    Node *W = root->left;
    root->left = W->right;
    W->right = root;

    // update height
    root->height = max(Height(root->left), Height(root->right)) + 1;
    W->height = max(Height(W->left), Height(W->right)) + 1;
    return W;
}
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (root->indexdata > data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    // update height
    root->height = max(Height(root->left), Height(root->right)) + 1;

    // get balance factor
    int b = Balance(root);
    int left = Balance(root->left);
    int right = Balance(root->right);

    // Left left
    if (b == 2 && left == 1)
        return rightRotate(root);
    // Left right
    if (b == 2 && left == -1)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right right
    if (b == -2 && right == -1)
        return leftRotate(root);
    // Right left
    if (b == -2 && right == 1)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
struct Node *search(struct Node *root, int data)
{
    if (root == NULL || root->indexdata == data)
        return root;
    if (data < root->indexdata)
        return search(root->left, data);
    return search(root->right, data);
}

struct Node *minValue(struct Node *root)
{
    Node *cur = root;
    while (cur != NULL && cur->left != NULL)
        cur = cur->left;
    return cur;
}
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->indexdata)
        root->left = deleteNode(root->left, data);
    else if (data > root->indexdata)
        root->right = deleteNode(root->right, data);
    else
    {
        // 1 child or leaf
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = minValue(root->right);
        root->indexdata = temp->indexdata;

        root->right = deleteNode(root->right, temp->indexdata);
    }
    // get balance factor
    int b = Balance(root);
    int left = Balance(root->left);
    int right = Balance(root->right);

    // Left left
    if (b == 2 && left == 1)
        return rightRotate(root);
    // Left right
    if (b == 2 && left == -1)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right right
    if (b == -2 && right == -1)
        return leftRotate(root);
    // Right left
    if (b == -2 && right == 1)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void deleteTree(Node *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void printLNR(struct Node *root)
{
    if (root == NULL)
        return;
    printLNR(root->left);
    cout << root->indexdata << " ";
    printLNR(root->right);
}
void printRNL(struct Node *root)
{
    if (root == NULL)
        return;
    printRNL(root->right);
    cout << root->indexdata << " ";
    printRNL(root->left);
}
void printNLR(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->indexdata << " ";
    printNLR(root->left);
    printNLR(root->right);
}

int main()
{
    Node *t = NULL;
    t = insertNode(t, 50);
    t = insertNode(t, 30);
    t = insertNode(t, 70);
    t = insertNode(t, 60);
    t = insertNode(t, 80);
    t = insertNode(t, 40);
    // t = insertNode(t, 5);
    // cout<<t->indexdata<<'\n';
    // cout<<t->right->indexdata<<'\n';
    // cout<<t->left->indexdata<<'\n';
    // cout<<t->left->left->right->indexdata<<'\n';
    deleteNode(t, 70);
    deleteNode(t, 30);
    //cout<<t->left->indexdata<<'\n';
    printLNR(t);

    return 0;
}
