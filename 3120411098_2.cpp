#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
//khoi tao
struct Node *initNode (int n) //t?o 1 hàm có tên initNode truy?n vào 1 bi?n n, hàm tr? v? 1 node
{
    struct Node *newNode = new Node; //khai báo và t?o 1 node m?i có tên newNode
    newNode->data = n; //giá tr? c?a newNode = giá tr? bi?n n truy?n vào hàm
    newNode->next = NULL; //v?a kh?i t?o nên node->next = NULL
    return newNode; //tr? v? 1 Node
}
//them node vao cuoi
void addNode (Node *head,int n) //khai báo 1 hàm có tên addNode ?? thêm 1 node vào cu?i dslk, truy?n vào hàm 1 Node head và 1 bi?n n là giá tr? c?a node ta s? thêm vào dslk
{
    Node *newNode = new Node; //khai báo và t?o 1 Node m?i có tên newNode
    newNode->data = n; //Node v?a t?o có giá tr? = n ta truy?n vào hàm
    newNode->next = NULL; //node v?a t?o nên ->next = NULL

    Node *cur = head; //khai báo 1 Node có tên cur tr? ??n con tr? head dùng ?? duy?t dslk
    while(cur) //?i?u ki?n cur != NULL
    {
        if (cur->next == NULL) //lúc này ?ang ? node cu?i c?a dslk
        {
            cur->next = newNode; //t?o m?i liên k?t gi?a node cu?i và node m?i v?a t?o
            return; //thoát vòng l?p
        }
        cur = cur->next; //n?u không th?a mãn ?i?u ki?n if thì th?c duy?t ti?p ?? ki?m tra Node khác
    }
}
//them vao dau
void InsertFront (Node **head, int n) //t?o 1 hàm có tên InsertFront truy?n vào 1 Node có tên head do là khi thêm vào con tr? head s? thay ??i nên ta c?n truy?n tham chi?u và 1 bi?n n là giá c?a node ta s? thêm vào
{
    Node *newNode = new Node; //khai báo và t?o 1 node m?i có tên newNode
    newNode->data = n; //giá tr? c?a node m?i = giá tr? c?a bi?n ta truy?n vào
    newNode->next = *head; //t?o m?i liên k?t gi?a Node v?a t?o v?i node ??u tiên c?a dslk vì c?n thêm vào ??u dslk
    *head = newNode; //c?p nh?t l?i con tr? head, vì lúc này node v?a t?o ?ã là node ??u tiên c?a dslk
}
// tim node co khoa
struct Node *searchNode (struct Node *head, int n) //t?o hàm có tên searchNode tr? v? 1 node, truy?n vào hàm 1 Node tên head và 1 bi?n n là giá tr? c?a node c?n tìm
{
    Node *cur = head; //khai báo 1 Node có tên cur tr? ??n con tr? head dùng ?? duy?t dslk
    while (cur) //?i?u ki?n ?? th?c hi?n vòng l?p
    {
        if (cur->data == n) //?ã tìm ra node c?n tìm
        {
            return cur; //thoát vòng l?p
        }
        cur = cur->next; //n?u ch?a tìm th?y duy?t sang node k? ti?p ??n h?t dslk
    }
    cout << " Khong tim thay.\n ";  //n?u duy?t xong dslk mà không tìm th?y node xu?t ra dòng Khong tim thay.
}
// xoa node
void deleteNode (Node **head, int n) //t?o hàm có tên deleteNode truy?n vào 1 Node có tên head do con tr? head có th? thay ??i khi xóa nên ta c?n truy?n vào tham chi?u và 1 bi?n n là giá tr? c?a node ta c?n xóa
{
    Node *cur = *head; //khai báo 1 Node có tên cur tr? ??n con tr? head dùng ?? duy?t dslk
    Node *pre = NULL; //khai báo 1 Node tên pre cho tr? ??n NULL m?c ?ích dùng ?? xóa node khác node ??u dslk
    if (cur->data == n) //tr??ng h?p tìm th?y giá tr? node c?n xóa ngay node ??u dslk
    {
        *head = cur->next; //di chuy?n con tr? head sang node k? ti?p
        delete cur; //xóa node c?n xóa
        return; //thoát vòng l?p
    }
    else //tr??ng h?p node c?n xóa khác node ??u tiên 
        while (cur != NULL && cur->data != n) //?i?u ki?n duy?t vòng l?p ?? tìm node c?n xóa
        {
            pre = cur; //cho con tr? pre tr? ??n cur
            cur = cur->next; //cho con tr? cur di chuy?n ??n node k? ti?p
        }
    if (cur == NULL) //tr??ng h?p duy?t h?t dslk t?c là node c?n xóa ko có 
        return; //thoát ?i?u ki?n if
    pre->next = cur->next; //tr??ng h?p tìm ???c node c?n xóa thì ta cho con tr? pre tr? ??n node k? ti?p c?a node cur ?? t?o m?i liên k?t
    delete cur; //xóa node cur c?ng chính là node c?n xóa
}
//in danh sach 
void Print (Node *head) //t?o hàm có tên Print truy?n vào 1 Node tên head dùng ?? in ra dslk
{
    Node *cur = head; //khai báo và t?o 1 Node tên cur tr? ??n head dùng ?? duy?t dslk
    while (cur) //?i?u ki?n ?? th?c hi?n vòng l?p
    {
        cout << cur->data << " "; //xu?t ra giá tr? data c?a node
        cur = cur->next; //di chuy?n ??n node ti?p theo
    }
    cout << endl;
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
			addNode (newL, cur->data);
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

int main ()
{
    Node *head;
    head = initNode(1);
    addNode (head, 2);
    addNode (head, 3);
    addNode (head, 4);
    addNode (head, 5);
    InsertFront (&head,0);
    Print (head);
    
    //head = searchNode (head,1);
    //if (head != 0)
    {
    	//cout<<"Co node trong List";
	}
    
    //deleteNode(&head,0);
    //cout <<"List is: ";
	//Print(head);
    
    //reverse(&head);
    //cout <<"List after: ";
    //Print(head);
    
    //cout <<"Copy list: ";
    //head = Copy(head);
    //Print (head);
    
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
