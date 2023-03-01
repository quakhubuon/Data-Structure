#include <iostream>
using namespace std;

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode (int data) //khai báo 1 hàm có tên là newNode truyền vào 1 biến data và trả về 1 Stacknode dùng để tạo mới 1 stackNode
{
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); //khai báo và sử dụng malloc cấp phát bộ nhớ động để tạo một StackNode mới
    stackNode->data = data; //giá trị của stackNode = giá trị data truyền vào
    stackNode->next = NULL; //do vừa khởi tạo nên stackNode ->next = NULL
    return stackNode; //trả về stackNode
}

int isEmpty (struct StackNode* root) //tạo 1 hàm có tên isEmpty truyền vào 1 StackNode để kiểm tra danh sách có rỗng không
{
    return !root; //
}

void push (struct StackNode** root, int data) //tạo hàm có tên push để thêm giá trị data vào stack, truyền vào 1 StackNode do khi thêm phần tử vào, StackNode sẽ thay đổi nên ta truyền tham chiếu và 1 biến data là giá trị sẽ thêm vào stack
{
    struct StackNode* stackNode = newNode(data); //khai báo và tạo 1 StackNode mới có tên stackNode
    stackNode->next = *root; //phần tử mới thêm vào sẽ lên kết với các phần tử cũ
    *root = stackNode; //cập nhật lại stack sau khi đã thêm data vào
    printf("%d pushed to Stack\n", data); //xuất ra giá trị vừa thêm vào stack
}

int pop (struct StackNode** root) //tạo 1 hàm có tên pop dùng để xóa phần tử ở đỉnh stack, truyền vào 1 StackNode do khi xóa phần tử ở đỉnh stack sẽ thay đổi nên ta truyền tham chiếu, hàm trả về giá trị đã xóa
{
    if (isEmpty(*root)) //kiểm tra stack rỗng hay không
        return INT_MIN; //nếu rỗng trả về min
    struct StackNode* temp = *root; //khai báo và tạo 1 biến kiểu StackNode tên temp trỏ đến root dùng để lưu lại node hiện tại để tiếp tục thao tác công việc xóa
    *root = (*root)->next; //di chuyển trỏ root sang node kế tiếp
    int popped = temp->data; //khai báo biến kiểu int tên popped gán = temp->data để lưu giá trị của phần tử mình sắp xóa
    free(temp); //xóa phần tử
    return popped; //trả về giá trị vừa xóa
}

int peek (struct StackNode* root) //khai báo hàm có tên peek kiểu int truyền vào 1 StackNode, hàm trả về giá trị phần tử ở đỉnh stack
{
    if (isEmpty(root)) //kiểm tra stack có rỗng không
        return INT_MIN; //trả về min nếu rỗng
    return root->data; //trả về phần tử ở đỉnh stack
}

int main ()
{
    struct StackNode* root = NULL;
    //push (&root, 1);
    //push (&root, 2);
    //push (&root, 3);
    //printf ("%d popped from stack\n", pop(&root));
    //printf ("Top element: %d\n", peek(root));
//d.	 	Giải thích và viết chương trình ứng dụng ngăn sếp (stack) để thực hiện việc chuyển đổi một số từ hệ cơ số 10 sang một số mới với cơ số b bất kỳ (2 <= b <= 9).
     int n, b; //khai báo 2 biến n và b là một số từ hệ cơ số 10 và cơ số b bất kì (2 <= b <=9)
    cout<<"Nhap vao 1 so n : "; 
    cin>>n; //nhập vào số từ hệ cơ số 10
    cout<<"Nhap vao co so b: ";
    cin>>b; //nhập cơ số b bất kì (2 <= b <=9)
    int temp = n; //khai báo và tạo 1 biến temp gán = số hệ cơ số 10
    while(temp > 0) //điều kiện số cần chuyển đổi là số nguyên dương > 0
    {
        int le = temp % b; //khai báo vào tạo 1 biến le kiểu int gán = kết quả phép chia lấy dư của 2 số là số ta cần chuyển đổi và cơ số b do rằng muốn chuyển đổi cơ số ta thực hiện phép chia lấy dư
        push(&root, le); //ta bỏ kết quả phép chia trên vào stack 
        temp /= b; //lấy biến temp chia cho cơ số b để tiếp tục việc chuyển đổi cơ số cho đến khi không còn thỏa mãn điều kiện
    }
        while(!isEmpty(root)) //nếu stack khác rỗng
        cout<<pop(&root); //xuất ra kết quả là số được chuyển đổi từ hệ cơ số 10
    
    return 0;
}
