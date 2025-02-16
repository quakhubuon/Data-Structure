#include <iostream>
#include <climits>
using namespace std;

struct Stack {
    int indexdata;
    Stack *next;
};

struct Stack *createStack(int data) {
    Stack *newStack = new Stack;
    newStack->indexdata = data;
    newStack->next = NULL;
    return newStack;
}

bool isEmpty(Stack *root) {
    if (root == NULL)
        return true;
    return false;
}

void push(Stack **root, int data) {
    Stack *newStack = createStack(data);
    newStack->next = *root;
    *root = newStack;
    cout <<"Them phan tu gia tri: " << data << " vao stack" << endl;
}

int pop(Stack **root) {
    Stack *temp = *root;
    *root = (*root)->next;
    int value = temp->indexdata;
    free(temp);
    return value;
}

int peek(Stack *root) {
    if (!isEmpty(root))
        return root->indexdata;
    return INT_MIN; 
}

void print(Stack *root) {
    while (root) {
        cout << root->indexdata << " ";
        root = root->next;
    }
}

struct Stack *chuyencoso(int n, int b) {
    Stack *root = NULL;
    int sodu;
    while (n>0) {
        sodu = n%b;
        push(&root, sodu);
        n /= b;
    }
    return root;
}

int main() {
    Stack *root = NULL;
    push (&root, 1); 
    push (&root, 2); 
    push (&root, 3); 
    cout <<"Gia tri cua phan tu cuoi cung : " << peek(root) << endl;
    pop(&root); 
    cout <<"Gia tri cua phan tu cuoi cung sau khi pop: " << peek(root) << endl;
    print(root);
    cout << endl;
    
    int n;
    int b;

    cout <<"Nhap n: ";
    cin >>n;

    cout <<"Nhap b: ";
    cin >>b;

    Stack *stack = NULL;
    stack = chuyencoso(n, b);
    print(stack);
    return 0;
}