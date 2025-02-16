#include <iostream>
using namespace std;

struct Queue {
    int indexdata;
    Queue *next;
};

struct Queue *createQueue(int n) {
    Queue *newQueue = new Queue;
    newQueue->indexdata = n;
    newQueue->next = NULL;
    return newQueue;
}

bool isEmpty(Queue *root) {
    if (root == NULL) 
        return true;
    return false;
}

void EnQueue(Queue **root, int data) {
    Queue *newQueue = createQueue(data);
    if (*root == NULL) {  // Nếu queue rỗng, gán node mới làm root
        *root = newQueue;
    } else {
        Queue *temp = *root;
        // Di chuyển đến phần tử cuối cùng của queue
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newQueue;
    }
    cout << "Them phan tu gia tri: " << data << " vao queue" << endl;
}

void DeQueue(Queue **root) {
    if (root == NULL) {
        cout <<"Queue rỗng !";
        return;
    }
    Queue *temp = *root;
    *root = (*root)->next;
    int data = temp->indexdata;
    free(temp);
    cout << "Gia tri vua duoc lay ra: " << data << endl;
}

void print(Queue *root) {
    while (root) {
        cout << root->indexdata << " ";
        root = root->next;
    }
}


int main() {
    Queue *root = NULL;
    EnQueue(&root, 1);
    EnQueue(&root, 2);
    EnQueue(&root, 3);
    print(root);
    cout << endl;
    DeQueue(&root);
    cout <<"DeQueue: ";
    print(root);
    return 0;
}