#include <iostream>
#include <math.h>
using namespace std;

struct Node {
    int indexdata;
    Node *left;
    Node *right;
};
//Hàm kh?i t?o 1 node
struct Node *createNode (int n) // khai báo 1 hàm có tên là createNode tr? v? 1 node, truy?n vào 1 bi?n n là giá tr? c?a node ?ó
{
    Node *newNode = new Node;  // khai báo và t?o 1 node m?i có tên là newNode
    newNode->left = NULL;  // khi v?a kh?i t?o nên cây con trái = NULL
    newNode->right = NULL;  // khi v?a kh?i t?o nên cây con ph?i = NULL
    newNode->indexdata = n;  // giá tr? c?a newNode = giá tr? n ta truy?n vào hàm
    return newNode; // tr? v? 1 node
}

struct Node *InsertNode (Node *root, int n) //1 hàm có tên là InsertNode dùng ?? chèn 1 node m?i vào cây có giá tr? n, ??u vào ta truy?n vào hàm 1 cái g?c và 1 bi?n n. Hàm tr? v? 1 g?c
{
    if (root == NULL) // n?u g?c = NULL
        root = createNode(n); // ta g?i hàm t?o m?i ?? chèn 1 node v?i giá tr? n
    if (n < root->indexdata) // n?u giá tr? c?a node m?i ta mu?n thêm vào < giá tr? node g?c
        root->left = InsertNode (root->left, n); // thì ta g?i ?? quy ?? thêm node vào bên trái
    if (n > root->indexdata) // n?u giá tr? c?a node m?i ta mu?n thêm vào > giá tr? node g?c
        root->right = InsertNode (root->right, n); // thì ta g?i ?? quy ?? thêm node vào bên ph?i
    return root; // tr? v? 1 cái g?c
}

struct Node *minValue(struct Node *root) //khai báo hàm có tên minValue truy?n vào 1 cái g?c và tr? v? 1 node dùng ?? tìm node con nh? nh?t bên trái ph?c v? cho vi?c xóa Node có 2 con
{
    Node *cur = root; //khai báo và t?o 1 Node cur và gán = root dùng ?? duy?t ?? tìm node con nh? nh?t bên trái
    while(cur != NULL && cur->left != NULL) //vòng l?p v?i ?i?u ki?n cur != NULL và cur->left != NULL vì c?n tìm node con nh? nh?t bên trái nên cur->left != NULL n?u cur->left = NULL t?c là ?ã tìm ?c node c?n tìm nên s? d?ng vòng l?p
    {
        cur = cur->left; // n?u th?a ?i?u ki?n thì duy?t ??n node k? ti?p
    }
    return cur; // tr? v? cái node c?n tìm
}
struct Node *deleteNode(struct Node *root, int data) //khai báo hàm có tên deleteNode và truy?n vào 1 g?c và 1 bi?n data là giá tr? c?a node c?n xóa, hàm tr? v? 1 cái g?c
{
    if(root == NULL) //n?u root = NULL ??ng ngh?a không có node c?n xóa trong cây ch? c?n tr? v? g?c
        return root; // tr? v? g?c
    
    if(data < root->indexdata) // n?u giá tr? c?a node c?n xóa < node g?c thì ta ?i tìm node c?n xóa ?ó bên cây con trái
        root->left = deleteNode(root->left,data); // g?i ?? qui tìm node c?n xóa bên cây con trái
    else if (data > root->indexdata) // n?u giá tr? c?a node c?n xóa < node g?c thì ta ?i tìm node c?n xóa ?ó bên cây con ph?i
        root->right = deleteNode(root->right,data); // g?i ?? qui tìm node c?n xóa bên cây con trái
    else //lúc này n?u node c?n xóa có t?n t?i trong cây thì ta s? thi hành các câu l?nh trong hàm else t?c là hi?n t?i ta ?ã tìm ra node c?n xóa (data == root->indexdata)
    {
        //1 child or leaf
        if(root->left == NULL) // n?u node con c?a node c?n xóa = NULL thì ?ây là cây con ph?i
        {
            Node *temp = root->right; // khai báo và t?o m?t Node temp và gán = giá tr?  c?a cây con ph?i c?a node c?n xóa ?? l?u l?i giá tr? cây con ph?i node c?n xóa
            delete root; // sau ?ó xóa node c?n xóa
            return temp; // return temp ?? c?p nh?t l?i m?i liên k?t c?a node g?c v?i temp
        }
        else if(root->right == NULL) // n?u node con c?a node c?n xóa = NULL thì ?ây là cây con trái
        {
            Node *temp = root->left; // khai báo và t?o m?t Node temp và gán = giá tr?  c?a cây con trái c?a node c?n xóa ?? l?u l?i giá tr? c?a cây con trái node c?n xóa
            delete root; // sau ?ó xóa node c?n xóa
            return temp; ; // return temp ?? c?p nh?t l?i m?i liên k?t c?a node g?c v?i temp
        }
        //2 child
        Node *temp = minValue(root->right); // khai báo và t?o 1 node temp và gán = giá tr? c?a node con nh? nh?t bên trái
        root->indexdata = temp->indexdata; // gán node c?n xóa = giá tr? c?a node con nh? nh?t bên trái
        root->right = deleteNode(root->right, temp->indexdata); // g?i ?? quy ?? xóa node con nh? nh?t bên trái
    }
       return root; // tr? v? g?c
}

void DestroyTree (Node *root)  //t?o hàm có tên là DestroyTree truy?n vào 1 cái g?c
{
    if (root != NULL) //?i?u ki?n n?u root != NULL
    {
        DestroyTree(root->left); //g?i ?? quy h?y bên trái
        DestroyTree(root->right); //g?i ?? quy h?y bên ph?i
        delete root; // h?y node g?c
    }
}

Node *findNode (Node *root, int n) //t?o hàm có tên finNode truy?n vào 1 cái g?c và 1 bi?n n là giá tr? c?a node c?n tìm, hàm tr? v? 1 node
{
    if (root == NULL) //n?u root == NULL t?c là không có node c?n tìm
        return NULL; //nên tr? v? NULL
    if (n < root->indexdata) //n?u giá tr? c?n tìm < node g?c 
        return findNode (root->left, n); //thì g?i ?? quy tìm node bên cây con trái
    if (n > root->indexdata) //n?u giá tr? c?n tìm > node g?c 
        return findNode (root->right, n); //thì g?i ?? quy tìm node bên cây con ph?i
    return root; //tr? v? node c?n tìm = NULL n?u không tìm ???c
}

void printLNR (Node *root) //t?o hàm có tên là printLNR truy?n vào 1 g?c ?? duy?t cây 
{
    if (root != NULL) //n?u cây khác r?ng
    {
        printLNR(root->left); //duy?t bên trái
        cout << root->indexdata << " ";  //duy?t node g?c
        printLNR(root->right); //duy?t bên ph?i
    }
}

void printNLR (Node *root) //t?o hàm có tên là printNLR truy?n vào 1 g?c ?? duy?t cây 
{
        if (root != NULL) //n?u cây khác r?ng
       {
               cout << root->indexdata <<" "; //duy?t node g?c
               printNLR(root->left); //duy?t bên trái
               printNLR(root->right); //duy?t bên trái
      }
}

void printRNL (Node *root) //t?o hàm có tên là printRNL truy?n vào 1 g?c ?? duy?t cây 
{
               if (root != NULL) //n?u cây khác r?ng
     {
               printRNL(root->right); //duy?t bên trái
               cout << root->indexdata << " ";	 //duy?t node g?c
               printRNL(root->left); //duy?t bên trái
     }	
}

bool SNT (int n)
{
	if (n < 2)
	{
		return false;
	}
	else 
	{
		for (int i = 2;i <= sqrt(n);i++)
		{
			if (n % i == 0)
				return false;
		}
	}
	return true;
}


int demsonguyento (Node *root, int &count)
{
	if (root != NULL)
	{
		if (SNT(root->indexdata) == true)
		{
			count++;
		}
		demsonguyento(root->left, count);
		demsonguyento(root->right, count);
	}
	return count;
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

    deleteNode (t, 20);
    printLNR (t);
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
    
    int count = 0;
	cout<<"So luong so nguyen to: " <<demsonguyento(t, count);
}

