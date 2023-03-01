#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node *pre;
};
//khoi tao
struct Node* initNode(int n)
{
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	newNode->pre = NULL;
	return newNode;
}
//them node
void addNode(Node *head, int n)
{
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	newNode->pre = NULL;
	
	Node *cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
	newNode->pre = cur;
}
//them vao dau 1 node
void InsertFront(Node **head, int n)
{
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	newNode->pre = NULL;
	*head = newNode;
}
//tim node voi khoa x
Node *searchNode (Node *head, int n)
{
	Node *cur = head;
	Node *pre = NULL;
	while(cur)
	{
		if(cur->data==n)
		{
			return cur;
		}	
		cur = cur->next;
	}
	return cur = NULL;
}
//xoa 1 node trong danh sach lien ket
void deleteNode (Node **head, int n)
{
	Node *cur = *head;
	Node *pre = NULL;
	Node *temp = NULL;
	
	if (cur->data == n) // node dau
	{
		*head = cur->next;
		(*head)->pre = NULL;
		delete cur;
		return;
	}
	else
	{
		while (cur != NULL && cur->data != n)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur == NULL) // khong ton tai
			return;
		if (cur->next == NULL) // node cuoi
		{
			pre->next = NULL;
			delete cur;
			return;
		}
		temp = cur->next;
		pre->next = temp;
		temp->pre = pre;
		delete cur;
	}
}

//dao danh sach
void reverse (Node **head)
{
	Node *cur = *head;
	Node *temp = NULL;
	while (cur)
	{
		temp = cur->pre;
		cur->pre = cur->next;
		cur->next = temp;
		cur = cur->pre;
	}
	if (temp != NULL)
		*head = temp->pre;
}
//sao chep
Node *Copy (Node *head)
{

	if (head == NULL)
		return NULL;
	
	else
	{
		Node *cur = head;
		Node *newL = new Node;
		newL->next = NULL;
		newL->pre = NULL;
		newL->data = cur->data;
		while (cur->next != NULL)
		{
			cur = cur->next;
			addNode(newL, cur->data);
		}
		return newL;
	}
}
//xoa danh sach lien ket
void deleteList (Node **head)
{
	Node *cur = *head;
	while (cur)
	{
		*head = cur->next;
		delete cur;
		*head = cur;
	}
	*head = NULL;
}
//so sanh
void Compare (Node *head, Node *head2)
{
	Node *cur = head;
	Node *cur2 = head2;
	
	while (cur && cur2)
	{
		if (cur->data != cur2->data)
		{
			cout <<"Not same";
			return;
		}
		cur = cur->next;
		cur2 = cur2->next;
	}
	if (cur==NULL && cur2==NULL)
		cout<<"Same";
	else
		cout<<"Not same";
}
//xuat
void Print(Node* head)
{
	Node*cur = head;
	cout<<"List is: ";
	while(cur)
	{
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout << endl;
}
int main()
{
	
	Node *head;
    head = initNode(1);
	addNode(head,2);
   	addNode(head,3);
   	addNode(head,4);
   	addNode(head,5);
   	
    //InsertFront(&head,0);
    //Print(head);
    
    head = searchNode (head,1);
    if (head != 0)
    {
    	cout<<"Co node trong List";
	} else {
		cout <<"Ko co node trong List";
	}
    
    //deleteNode (&head, 0);
    //Print(head);
    
    //cout<<"List After: ";
	//reverse(&head);
	
	//cout<<"Copy list is: ";
	//head = Copy(head);
	//Print(head);
	
	//deleteList(&head);
	//Print(head);
	
	//Node *head2;
    //head2 = initNode(1);
	//addNode(head2,2);
   	//addNode(head2,3);
   	//addNode(head2,4);
   	//addNode(head2,5);
   	
    //InsertFront(&head2,0);
    //Print(head2);
   	//Compare(head, head2);
    	
	//Print(head);
	
	return 0;
}
