#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
//khoi tao
struct Node *initNode (int n)
{
    struct Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}
//them node vao cuoi
void addNode (Node **head,int n)
{
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    
    if(*head == NULL){
    	*head = newNode;
    	return;
	}

    Node *cur = *head;
    while(cur)
    {
        if (cur->next == NULL)
        {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}
//them vao dau
void InsertFront (Node **head, int n)
{
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = *head;
    *head = newNode;
}
// tim node co khoa
struct Node *searchNode (struct Node *head, int n)
{
    Node *cur = head;
    while (cur)
    {
        if (cur->data == n)
        {
            return cur;
        }
        cur = cur->next;
    }
    return cur = NULL;
}
// xoa node
void deleteNode (Node **head, int n)
{
    Node *cur = *head;
    Node *pre = NULL;
    if (cur->data == n)
    {
        *head = cur->next;
        delete cur;
        return;
    }
    else
        while (cur != NULL && cur->data != n)
        {
            pre = cur;
            cur = cur->next;
        }
    if (cur == NULL)
        return;
    pre->next = cur->next;
    delete cur;
}
//dao danh sach
void reverse (Node **head)
{
    Node *cur = *head ;
    Node *pre = NULL;
    Node *next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    *head = pre;
}
//copy list
Node *Copy (Node *head)
{
	if (head == NULL)
	return NULL;

	else 
	{
		Node *cur = head;
		Node *newL = new Node;
		newL->data = cur->data;
		newL->next = NULL;
		
		while (cur->next != NULL)
		{
			cur = cur->next;
			addNode (&newL, cur->data);
		}
		return newL;
	}
}
//xoa danh sach
void deleteList (Node **head)
{
    Node *cur = *head;
    while (cur)
    {
        *head = cur->next;
        delete cur;
        cur = *head; 
    }
}
//sosanh
void Compare (Node *head, Node *head2)
{
    Node *cur = head;
    Node *cur2 = head2;

    while ( cur!=NULL && cur2 != NULL)
    {
        if (cur->data != cur2->data)
        {
            cout <<"Not same";
            return;
        }
        cur = cur->next;
        cur2 = cur2->next;
    }
    if (cur==NULL && cur2 == NULL)
    cout <<"Same";
    else
    cout <<"Not same";
}
//in danh sach
void Print (Node *head)
{
    Node *cur = head;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main ()
{
    struct Node *head = NULL;
    int n, x;
    cout<<"Nhap so luong Node: ";
    cin>>n;
    for (int i = 1; i <= n; i++){
    	cout<<"Nhap gia tri cua Node: ";
    	cin>>x;
    	addNode (&head, x);
	}
    //Print (head);
    
    head = searchNode (head,10);
    if (head != NULL)
    {
    	cout<<"Co node trong List";
	} else {
        cout << "Ko co node trong List";
    }
    
    //deleteNode(&head,0);
    //cout <<"List is: ";
	//Print(head);
    
    //reverse(&head);
    //cout <<"List after: ";
    //Print(head);
    
//    cout <<"Copy list: ";
//    head = Copy(head);
//    Print (head);
    
    //cout<<"Sau khi xoa";
    //deleteList(&head);
    //Print(head);

	/*
    Node *head2;
    head2 = initNode(1);
    addNode (head2, 2);
    addNode (head2, 3);
    addNode (head2, 4);
    addNode (head2, 5);
    InsertFront (&head2,0);
    Print (head2);
	Compare(head, head2);
	*/
	//Print(head);
	
	return 0;
}
