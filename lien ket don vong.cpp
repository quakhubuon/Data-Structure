#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *initNode(int n){
    Node *newNode = new Node;
    newNode->next = newNode;
    newNode->data = n; 
    return newNode;
}

void addNode(Node *head, int n){
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = head;
	
	Node *cur = head;
	while (cur->next != head){
		cur = cur->next;
	}
	cur->next = newNode;
	newNode->next = head;
}

void InsertFront (Node *head, int n)
{
	Node *newNode = new Node;
	newNode->next = head;
	newNode->data = n;
	
	Node *cur = head;
	while (cur->next != head)
	{
		cur = cur->next;
	}
	cur->next = newNode;
	head = newNode;
}

struct Node *searchNode(Node *head, int n)
{
    Node *cur = head;
    do
    {
        if (cur->data == n)
            return cur;
        cur = cur->next;
    } while(cur != head);
    return cur = NULL;
}


void deleteNode (Node **head, int n)
{
	Node *cur = *head;
	Node *pre = NULL;
	
	if (cur->data == n) //firts Node
	{
		Node *pre = *head;
		while (pre->next != *head )
		{
			pre = pre->next;
		}
		*head = cur->next;
		pre->next = *head;
		delete cur;
	}
	else
	{
		while (cur->data != n)	
		{
			if (cur->next == *head) //khong co node can xoa
				return;
			pre = cur;
			cur = cur->next;
		}	
		if (cur->next == *head) //last Node
		{
			pre->next = *head;
			delete cur;
		}
		
		else // cac node con lai
		{
			pre->next = cur->next;
			delete cur;
		}
	}
}

void reverse(Node **head)
{
	Node *cur = *head;
	Node *pre = NULL;
	Node  *next = NULL;
	do 
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	} while (cur != *head);
	cur->next = pre;
	*head = pre;
}

void deleteList(struct Node **head)
{
    Node *cur = *head;
    do
    {
        *head = cur->next;
        delete cur;
    	*head = cur;
    } while(cur != *head);
    *head = NULL;
}

Node *Copy (Node *head)
{
	Node *cur = head;
	Node *newL = NULL;
	
	if (head == NULL)
		return NULL;

	do
	{
		if (newL == NULL) //first Node
		{
			initNode (cur->data);
		}
		
		else
		{
			addNode (newL, cur->data);
			cur = cur->next;
		}
	} while (cur != head);	
}

void Compare (Node *head, Node *head2)
{
	Node *cur = head;
	Node *cur2 = head2;
	
	do{
		if (cur->data != cur2->data)
		{
			cout<<"Not same";
			return;
		}
		cur = cur->next;
		cur2 = cur2->next;
	}while (cur != head && cur2 != head2);
	if (cur == head && cur2 == head2)
		cout <<"Same";
	else
		cout<<"Not same";	
}

void Print (Node *head)
{
    Node *cur = head;
    cout << "List is: ";
    if(head != NULL)
    {
    do
    {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    }
    cout<<endl;
}

int main ()
{
    Node *head;
    head = initNode(1);
    addNode (head, 2);
    addNode (head, 3);
    addNode (head, 4);
    addNode (head, 5);
    addNode (head, 6);
    //InsertFront (head, 0);
    //Print(head);
    head = searchNode (head, 0);
    if (head != NULL)
    {
    	cout<<"Co Node can tim trong List.\n";
	}
	else 
	{
		cout<<"Khong co Node can tim trong List.\n";
	}
	
	//deleteNode (&head, 6);
	//Print(head);
	
	//cout<<"Reverse: ";
	//reverse (&head);
	//Print (head);
	
	//cout<<"Sau khi xoa:\n ";
	//deleteList (&head);
	//Print(head);
	
	

	/*
    head2 = initNode(1);
    addNode (head2, 2);
    addNode (head2, 3);
    addNode (head2, 4);
    addNode (head2, 5);
    addNode (head2, 6);
    InsertFront (head2, 0);
    //Print(head2);
    //Compare(head, head2);
    */
    
    //Node *head2;
	//cout<<"Copy: \n";
	//head2 = Copy (head);
	//Print (head2);
	
    return 0;
}
